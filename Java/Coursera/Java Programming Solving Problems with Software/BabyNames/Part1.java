import edu.duke.*;
import org.apache.commons.csv.*;
import java.io.*;
/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part1 {
    
    DirectoryResource dr;
    
    public int getTotalBirthsRankedHigher(int year, String name, String gender){
        // method returns an integer, the total number of births of those names with the 
        // same gender and same year who are ranked higher than name.
        
        // get the rank of name and gender
        int rank = getRank(year, name, gender);
        
        // variable to store the total number of births
        int totalBirths = 0;
        
        if (rank != -1){
            
            FileResource fr = new FileResource("yob"+year+"short.csv");
            CSVParser parser = fr.getCSVParser(false);
        
            // loop through the records in the parser
            for (CSVRecord currRecord : parser){
                // if the current record's gender matches the gender argument and its name
                // != the name argument add the total births of the current record to the
                // variable
                if(currRecord.get(1).equals(gender) && !currRecord.get(0).equals(name)){
                    totalBirths += Integer.parseInt(currRecord.get(2));
                } else if (currRecord.get(0).equals(name) && currRecord.get(1).equals(gender)) {
                    // break out of the loop if the values match
                    break;
                }
                
                    
            }
            
            
        
        }
        return totalBirths;
    }
    
    public double getAverageRank(String name, String gender){
        // method selects a range of files to process and returns a double 
        // representing the average rank of the name and gender over the selected 
        // files. It should return -1.0 if the name is not ranked in any of the 
        // selected files.
        
        // select a range of files to process
        dr = new DirectoryResource();
        
        // variable to store the rank
        int totalRank = 0;
        
        // number of times name is found with a rank in the files
        double countRank = 0.0;
        
        // loop through the individual files
        for(File f : dr.selectedFiles()){
            // extract the file year of F as an integer value
            int currentYear = Integer.parseInt(f.getName().substring(3,7));
            
            // call the get rank method to calculate highest rank in file of name and gender
            int currentFileRank = getRank(currentYear, name, gender);
            
            // if a valid rank is found add it to the total rank variable and increase count rank by 1.0
            if (currentFileRank != -1) {
                totalRank += currentFileRank;
                countRank += 1.0;
            }
        }
        
        // if the name is not ranked in any of the files
        if (totalRank == 0){
            return -1;
        } else {
            return totalRank/countRank;
        }
    }
    
    public int yearOfHighestRank(String name, String gender){
        // method selects a range of files to process and returns an integer, the year with 
        // the highest rank for the name and gender. If the name and gender are not in any of
        // the selected files, it should return -1.
        
        // select a range of files to process
        dr = new DirectoryResource();
        
        // variable to store the rank
        int rank = 0;
        
        // variable to store the year of a file
        int highestRankYear = 0;
        
        // loop through individual files
        for(File f : dr.selectedFiles()){
            // extract the file year of F as an integer value
            int currentYear = Integer.parseInt(f.getName().substring(3,7));
            // call the get rank method to calculate highest rank in file of name and gender
            int currentFileRank = getRank(currentYear, name, gender);
            
            // if rank is zero initialise it with current file rank
            if (rank == 0) {
                rank = currentFileRank;
                // additionally, initialise the highest rank year varaible
                highestRankYear = currentYear;
            } else {
                if (currentFileRank < rank){
                    rank = currentFileRank;
                    highestRankYear = currentYear;
                }
            }
        }
    
        return highestRankYear;
    }
    
    public void whatIsNameInYear(String name, int year, int newYear, String gender){
        // method determines what name would have been named if they were born in a different
        // year, based on the same popularity. It determines the rank of name in the year they
        // were born, and then print the name born in newYear that is at the same rank and 
        // same gender.
        
        // call get rank which returns the rank of name, gender in year
        int rank = getRank(year, name, gender);
        
        if(rank == -1){
            System.out.println("NO NAME");
        } else {
            System.out.println(name + " born in " + year + " would be " +
                               getName(newYear, rank, gender) + " if she was born in " +
                               newYear);
        }
    }
    
    public String getName(int year, int rank, String gender){
        // method returns the name of the person in the file at this rank, for the given 
        // gender, where rank 1 is the name with the largest number of births. If the rank 
        // does not exist in the file, then “NO NAME”  is returned.
        
        FileResource fr = new FileResource("yob"+year+".csv");
        CSVParser parser = fr.getCSVParser(false);
        
        int currentRank = 0;
        
        // loop through the records in the parser
        for (CSVRecord currRecord : parser){
            // check whether gender is in the current record
            if(currRecord.get(1).equals(gender)){
                // increase the current rank
                currentRank++;
                
                // compare the two rankings. If equal then return the name of the current
                // record
                if(currentRank == rank){
                    return currRecord.get(0);
                }
            }
        }
        
        return "NO NAME";
    }
    
    public int getRank(int year, String name, String gender) {
        
        // method returns the rank of the name in the file for the given gender,  where rank 
        // 1 is the name with the largest number of births. If the name is not in the file, 
        // then -1 is returned.
        
        // variable for checking rank when name and gender exist in chosen file
        int rank = 0;
        
        // variable for checking whether name and gender are found 
        boolean found = false;
        
        FileResource fr = new FileResource("yob"+year+".csv");
        CSVParser parser = fr.getCSVParser(false);
        
        // loop through the records in the parser
        for (CSVRecord currRecord : parser){
            // check whether name and gender are in the current record
            if(currRecord.get(1).equals(gender)){
                // increase rank by one 
                rank++;
                
                if(currRecord.get(0).equals(name)){
                    found = true;
                    // break out of the loop because you have found a matching record
                    break;
                }
            }
            
        }
        if(found) {
            return rank;
        } else {
            return -1;
        }
    }
    
    public void totalBirths(CSVParser parser){
        
        // variable for number of girls names
        int numGirlsNames = 0;
        
        // variable for number of boys names
        int numBoysNames = 0;
        
        // loop through the records in the file
        for (CSVRecord currentRecord : parser) {
            
            if(currentRecord.get(1).equals("F")){
                numGirlsNames++;
            } else {
                numBoysNames++;
            }
        }
        
        // print the variables to the console
        System.out.println("Total number of girls names " + numGirlsNames);
        System.out.println("Total number of boys names " + numBoysNames);
        System.out.println("Total number of names " + (numGirlsNames + numBoysNames));
    }
    
    public void testGetTotalBirthsRankedHigher(){
        System.out.println(getTotalBirthsRankedHigher(2012, "Ethan", "M"));
    }
    
    public void testGetAverageRank(){
        System.out.println(getAverageRank("Jacob","M"));
    }
    
    public void testYearOfHighestRank(){
        System.out.println(yearOfHighestRank("Mason", "M"));
    }
    
    public void testwhatIsNameInYear(){
        whatIsNameInYear("Isabella", 2012, 2014, "F");
    }
    
    public void testGetName(){
        System.out.println(getName(1880, 1, "M"));
    }
    
    public void testGetRank(){
        System.out.println(getRank(1880, "Bertha", "F"));
    }
    
    public void testTotalBirths(){
        totalBirths(returnParser(returnFR()));
    }
    
    public FileResource returnFR(){
        return new FileResource();
    }
    
    public CSVParser returnParser(FileResource fr){
        // the false argument is when a file contains no header row
        return fr.getCSVParser(false);
    }

}
