import edu.duke.*;
import org.apache.commons.csv.*;
import java.io.File;

/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part1 {
    
    private CSVRecord lowest;
    private DirectoryResource dr;
    private File coldestTempFile;
    private File lowestHumidityTempFile;
    private CSVRecord lowestHumidityRecord;
    
    public double averageTemperatureWithHighHumidityInFile(CSVParser parser, int value){
        
        // variable to hold the sum of the temperature
        double sum = 0.0;
        
        // variable to hold the number of days in a month
        int numDays = 0;
        
        // loop through the records
        for (CSVRecord currentRecord : parser) {
            
            double currTemp = Double.parseDouble(currentRecord.get("TemperatureF"));
            int currHumidity = Integer.parseInt(currentRecord.get("Humidity"));
            
            // verify the temp value is greater than 0.0
            if(currTemp > 0.0 && currHumidity >= value){
                sum += currTemp;
                numDays++;
            }
        }
        return sum/numDays;
    }
    
    public double averageTemperatureInFile(CSVParser parser){
        
        // variable to hold the sum of the temperature
        double sum = 0.0;
        
        // variable to hold the number of days in a month
        int numDays = 0;
        
        // loop through the records
        for (CSVRecord currentRecord : parser) {
            
            double currTemp = Double.parseDouble(currentRecord.get("TemperatureF"));
            
            // verify the temp value is greater than 0.0
            if(currTemp > 0.0){
                sum += currTemp;
                numDays++;
            }
        }
        return sum/numDays;
    }
    
    public CSVRecord lowestHumidityInManyFiles(){
        // method returns a CSVRecord that has the lowest humidity over all the files chosen
        
        dr = new DirectoryResource();
        
        // loop through each file that was selected
        for(File currentFile : dr.selectedFiles()){
            
            if (lowestHumidityTempFile == null) {
                lowestHumidityTempFile = currentFile;
            } else {
                // for each file call the lowestHumidityInFile method to retrieve the
                // the appropriate lowest humidity
                FileResource currentFR = new FileResource(currentFile);
                FileResource previousFR = new FileResource(lowestHumidityTempFile);
                CSVRecord currentHumidity = lowestHumidityInFile(currentFR.getCSVParser());
                CSVRecord previousLowestHumidity = lowestHumidityInFile(previousFR.getCSVParser());
                
                // initialise the lowest humidity record variable to contain the value for the lowest
                // humidity value found in the lowest humidity temp file if its value is null
                if (lowestHumidityRecord == null) {
                    lowestHumidityRecord = previousLowestHumidity;
                }
                
                // cast the lowest humidity found in both cases to ints to 
                //  allow for comparison
                int currentHum = Integer.parseInt(currentHumidity.get("Humidity"));
                int previousHum = Integer.parseInt(previousLowestHumidity.get("Humidity"));
                  
                // compare the two values
                if (currentHum < previousHum){
                    // update lowestHumidityRecord to the currentHumidity
                    lowestHumidityRecord = currentHumidity;
                    // update the lowest humidity temp file to the current file
                    lowestHumidityTempFile = currentFile;
                    
                }
                
                
            }
            
        }
        return lowestHumidityRecord;
    }
        
        
    
    public CSVRecord lowestHumidityInFile(CSVParser parser) {
        // returns the CSVRecord that has the lowest humidity. If there is a 
        // tie, then return the first such record that was found
        
        CSVRecord lowestHumidityRecord = null;
        
        //loop through the file and parse each record
        for(CSVRecord currentRow : parser) {
            
            // initialise coldestRecord to current record that was just read
            if (lowestHumidityRecord == null && (!currentRow.get("Humidity").equals("N/A"))) {
                lowestHumidityRecord = currentRow;
            } else {
                
                // if value of Humidity field of the current row is == "N/A" proceed to the next record
                if (currentRow.get("Humidity").equals("N/A")){
                    
                    continue;
                    
                } else {
                    // retrieve the humidity values of the current record and previous record so far
                    int prevHumidity = Integer.parseInt(lowestHumidityRecord.get("Humidity"));
                    int currHumidity = Integer.parseInt(currentRow.get("Humidity"));
                    
                    if(currHumidity < prevHumidity) {
                        // update the lowestHumidityRecord
                        lowestHumidityRecord = currentRow;
                    }
                }
            }
        
        
        }
        return lowestHumidityRecord;
    }
    
    
    // This method returns the CSVRecord with the coldest temperature in the 
    // file and thus all the information about the coldest temperature
    public CSVRecord coldestHourInFile(CSVParser parser){
        
        CSVRecord coldestRecord = null;
        
        //loop through the file and parse each record
        for(CSVRecord currentRow : parser) {
            
            // initialise coldestRecord to current record that was just read
            if (coldestRecord == null && (Float.parseFloat(currentRow.get("TemperatureF")) > 0.0f)) {
                coldestRecord = currentRow;
            } else {
                // retrieve the temperature of current record and coldest record so far
                float prevTemp = Float.parseFloat(coldestRecord.get("TemperatureF"));
                float currTemp = Float.parseFloat(currentRow.get("TemperatureF"));
                
                // compare to find the largest value
                if (currTemp < 0){
                    
                    // continue onto the next record
                    continue;
                    
                } else if (currTemp < prevTemp) {
                    // update the coldest record so far accordingly
                    coldestRecord = currentRow;
                }
            }
            
        }
        return coldestRecord;
        
    }
    
    public String fileWithColdestTemperature(){
        
        dr = new DirectoryResource();
        
        // loop through each file that was selected
        for(File currentFile : dr.selectedFiles()){
            
            if (coldestTempFile == null) {
                coldestTempFile = currentFile;
            } else {
                // for each file call the coldestHourInFile method to retrieve the
                // the appropriate temperature
                FileResource currentFR = new FileResource(currentFile);
                FileResource previousFR = new FileResource(coldestTempFile);
                CSVRecord currentColdest = coldestHourInFile(currentFR.getCSVParser());
                CSVRecord previousColdest = coldestHourInFile(previousFR.getCSVParser());
                
                // cast the lowest temp found in both cases to floats to 
                //  allow for comparison
                float currentTemp = Float.parseFloat(currentColdest.get("TemperatureF"));
                float previousTemp = Float.parseFloat(previousColdest.get("TemperatureF"));
                
                // compare the two values
                if (currentTemp < previousTemp){
                    // update coldestTempFile to the currentFile
                    coldestTempFile = currentFile;
                    lowest = currentColdest;
                }
                
                
            }
            
        }
        return coldestTempFile.getAbsolutePath();
    }
    
    public void testAverageTemperatureInFile(){
        double averageTemp = averageTemperatureInFile(returnCSVParser(returnFileResource()));
        System.out.println("Average temperature in file is " + averageTemp);
    }
    
    public void testAverageTemperatureWithHighHumidityInFile(){
        double averageTemp = averageTemperatureWithHighHumidityInFile(returnCSVParser(returnFileResource()), 80);
        System.out.println("Average temperature when there is high humidity is " + averageTemp);
    }
    
    public void testLowestHumidityInManyFiles(){
        CSVRecord lowestHumidity = lowestHumidityInManyFiles();
        System.out.println("Lowest humidity was " + lowestHumidity.get("Humidity") + " " + lowestHumidity.get("DateUTC"));
    }
    
    
    public void testLowestHumidityInFile() {
        CSVRecord lowestHumidity = lowestHumidityInFile(returnCSVParser(returnFileResource()));
        System.out.println("Lowest humidity was " + lowestHumidity.get("Humidity") + " " + lowestHumidity.get("DateUTC"));
    }
    
    public void testFileWithColdestTemperature(){
        String path = fileWithColdestTemperature();
        System.out.println("Coldest day was in file (absolute path) " + path);
        System.out.println("Coldest temperature on that day was " + lowest.get("TemperatureF"));
        System.out.println("All the Temperatures on the coldest day were:");
        printAllTemps(path);
        
        
    }
    
    public void testcoldestHourInFile(){
        CSVRecord lowest = returnLargestRecord();
        System.out.println("Coldest hour occurred at time " + lowest.get("TimeEST") + " on the following date " + lowest.get("DateUTC") + ". The temperature was " + lowest.get("TemperatureF"));
    }
    
    public FileResource returnFileResource() {
        return new FileResource();
        
    }
    
    public CSVParser returnCSVParser(FileResource fr){
        return fr.getCSVParser();
    }
    
    public CSVRecord returnLargestRecord(){
        return coldestHourInFile(returnCSVParser(returnFileResource()));
    }
    
    public void printAllTemps(String path){
        FileResource fr = new FileResource(path);
        CSVParser parser = fr.getCSVParser();
        for(CSVRecord currentRecord : parser){
            System.out.print(currentRecord.get("DateUTC") + ": ");
            System.out.println(currentRecord.get("TemperatureF"));
        }
    
    }

}
