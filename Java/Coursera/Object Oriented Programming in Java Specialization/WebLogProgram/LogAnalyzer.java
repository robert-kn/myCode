
/**
 * Write a description of class LogAnalyzer here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.util.*;
import edu.duke.*;

public class LogAnalyzer{
     private ArrayList<LogEntry> records;
     
     public LogAnalyzer() {
         // complete constructor
         records = new ArrayList<LogEntry>();
     }
        
     public void readFile(String filename) {
         // complete method
         FileResource fr = new FileResource(filename);
         for(String line : fr.lines()){
             records.add(WebLogParser.parseEntry(line));
         }   
     }
        
     public void printAll() {
         for (LogEntry le : records) {
             System.out.println(le);
         }
     }
     
     public int countUniqueIPs(){
        /**
         * method should return an integer representing the number of unique 
         * IP addresses. It should also assume that the instance variable 
         * records already has its ArrayList of Strings read in from a file, 
         * and should access records in computing this value.
         */
        ArrayList<String> uniqueIps = new ArrayList<String>();
        
        for(LogEntry le : records){
            if(!uniqueIps.contains(le.getIpAddress())){
                uniqueIps.add(le.getIpAddress());
            }
        }
        return uniqueIps.size();
     }
     
     public ArrayList<String> uniqueIPVisitsOnDay(String someday){
        /**
         * method accesses the web logs in records and returns an ArrayList of
         * Strings of unique IP addresses that had access on the given day.
         */
        ArrayList<String> unique = new ArrayList<String>();
        for(LogEntry le : records){
            String currentDate = le.getAccessTime().toString();
            
            if (currentDate.substring(4,10).equals(someday)){
                if(!unique.contains(le.getIpAddress())){
                    unique.add(le.getIpAddress());
                }
            }
        }
        return unique;
     }
     
     public int countUniqueIPsInRange(int low, int high){
         /**
          * method returns the number of unique IP addresses in records that 
          * have a status code in the range from low to high, inclusive.
          */
         ArrayList<String> unique = new ArrayList<String>();
         for(LogEntry le : records){
             if((le.getStatusCode() >= low ) && (le.getStatusCode() <= high)){
                 if(!unique.contains(le.getIpAddress())){
                     unique.add(le.getIpAddress());
                 }
             }
         }
         return unique.size();
     }
     
     public HashMap<String, Integer> countVisitsPerIP(){
         /**
          * method returns a HashMap that maps an IP address to the number of 
          * times that IP address appears in records
          */
         
         HashMap<String,Integer> counts = new HashMap<String, Integer>();
         
         for(LogEntry le : records){
             
             String ip = le.getIpAddress(); 
             
             if(! counts.containsKey(ip)){
                 counts.put(ip, 1);
             } else {
                 counts.put(ip, counts.get(ip) + 1);
             }
         }
         
         return counts;
     }
     
     public int mostNumberVisitsByIP(HashMap<String, Integer> counts){
        /**
         * method returns the maximum number of visits to this website by a 
         * single IP address
         */
        
        int largest = 0;
        
        for(Integer visit : counts.values()){
            if(visit > largest){
                largest = visit;
            }
        }
        return largest;
     }
     
     public ArrayList<String> iPsMostVisits(HashMap<String, Integer> counts) {
         /**
          * method returns an ArrayList of Strings of IP addresses that all 
          * have the maximum number of visits to this website.
          */
         
         int mostVisits = mostNumberVisitsByIP(counts);
         ArrayList<String> mostVisitingIps = new ArrayList<String>();
         
         for(String ip : counts.keySet()){
             if(counts.get(ip) == mostVisits){
                 mostVisitingIps.add(ip);
             }
         }
         return mostVisitingIps;
     }
     
     public HashMap<String, ArrayList<String>> iPsForDays(){
         /**
          * uses records and maps days from web logs to an ArrayList of IP 
          * addresses that occurred on that day (including repeated IP 
          * addresses)
          */
         HashMap<String, ArrayList<String>> counts = new HashMap<String, ArrayList<String>>();
         
         for(LogEntry le : records){
            
             String currentDateTime = le.getAccessTime().toString();
             
             String date = currentDateTime.substring(4,10);
             
             if(! counts.containsKey(date)){
                 ArrayList<String> ips = new ArrayList<String>();
                 ips.add(le.getIpAddress());
                 counts.put(date, ips);
             } else {
                 ArrayList<String> ips = counts.get(date);
                 ips.add(le.getIpAddress());
                 counts.put(date, ips);
             }
         
         }
         return counts;
     }
     
     public String dayWithMostIPVisits(HashMap<String, ArrayList<String>> counts){
         /**
          * method returns the day that has the most IP address visits.
          */
         
         int numVisits = 0;
         String mostVisitedDay = null;
         
         for(String day : counts.keySet()){
             if(counts.get(day).size() > numVisits){
                 mostVisitedDay = day;
             }
         }
         
         return mostVisitedDay;
     }
     
     public ArrayList<String> iPsWithMostVisitsOnDay(HashMap<String, ArrayList<String>> counts, String someday){
         /**
          * method returns an ArrayList of IP addresses that had the most 
          * accesses on the given day.
          */
         
         //for(String day : counts.keySet()){
             //if(day.equals(someday)){
              //   return uniqueIPVisitsOnDay(someday);
             //}
         //}
         
         //return new ArrayList<String>();
         return uniqueIPVisitsOnDay(someday);
     }
}
