import edu.duke.*;
import org.apache.commons.csv.*;
/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part1 {
    
    public void bigExporters(CSVParser parser, String amount){
        //prints the names of countries and their Value amount for all countries whose Value (dollars) string is longer than the amount string
        
        //loop over the records to determine whether any contain a dollar (value) that is greater in length than amount
        for (CSVRecord record : parser) {
            if (record.get("Value (dollars)").length() > amount.length()){
                System.out.println(record.get("Country") + ": " + record.get("Value (dollars)"));
            }
        }
    }
    
    public int numberOfExporters(CSVParser parser, String exportItem){
        // returns the number of countries that export exportItem
        
        // declare and initialise counting variable
        int count = 0;
        
        //loop over the records to determine whether exportItem1 is in any of the records
        for (CSVRecord record : parser){
            // check export field in each record for the export item passed as arg
            
            if (record.get("Exports").contains(exportItem)){
                // increment count by 1
                count++;
            }
        }
        
        
        return count;
    }
    
    public void listExportersTwoProducts(CSVParser parser, String exportItem1, String exportItem2){
        // prints the names of all the countries that have both exportItem1 and exportItem2 as export items
        
        //loop over the records to determine whether exportItem1 and exportItem2 are in any of the records
        for (CSVRecord record : parser){
            // check export field in each record for the two export items that were passed as args
            String exports = record.get("Exports");
            
            if (exports.contains(exportItem1) && exports.contains(exportItem2)){
                // print the details about the country found
                System.out.print(record.get("Country"));
                System.out.println(" exports " + exportItem1 + " and " + exportItem2);
            }
        }
    }
    
    public String countryInfo(CSVParser parser, String country){
        //loop over the records to determine whether country exists in any of
        // them
        for (CSVRecord record : parser){
            // check country field in each record for the arg country
            // that was passed in
            if (record.get("Country").contains(country)){
                // return the details about country found
                return country + ": " + record.get("Exports") + ": " + record.get("Value (dollars)");
            }
        }
        return "NOT FOUND";
    }
    
    public void tester(){
        // open a file
        FileResource fr = new FileResource();
        // parse the file using the CSVParser from FileResource class
        CSVParser parser = fr.getCSVParser();
        
        //System.out.println(countryInfo(parser, "South Africa"));
        //listExportersTwoProducts(parser, "gold", "diamonds");
        //System.out.println(numberOfExporters(parser, "gold"));
        bigExporters(parser, "$999,999,999");
    }

}
