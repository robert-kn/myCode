import java.util.*;
import edu.duke.*;
/**
 * Write a description of Dictionary here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Dictionary {
    
    private HashMap<String,Integer> countCodons;
    
    public Dictionary(){
        countCodons = new HashMap<String,Integer>();
    }
    
    public void buildCodonMap(int start, String dna){
        /**
         * method will build a new map of codons mapped to their counts from 
         * the string dna with the reading frame with the position start 
         * (a value of 0, 1, or 2).
         */
        countCodons.clear();
        
        for(int i = start; i < dna.length() - 3; i+=3){
            String codon = dna.substring(i, i+3);
            if(countCodons.containsKey(codon)){
                Integer value = countCodons.get(codon);
                countCodons.put(codon, value + 1);
            } else {
                countCodons.put(codon, 1);
            }
        }
        
    }
    
    public String getMostCommonCodon(){
        /**
         * method returns a String, the codon in a reading frame that has the 
         * largest count.
         */
        
        String largestCount = null;
        
        for(String codon : countCodons.keySet()){
            Integer freq = countCodons.get(codon);
            if(largestCount == null){
                largestCount = codon;
            } else if(freq > countCodons.get(largestCount)){
                largestCount = codon;
            }
        }
        
        return largestCount;
    }
    
    public void printCodonCounts(int start, int end){
        /**
         * method prints all the codons in the HashMap along with their 
         * counts if their count is between start and end, inclusive
         */
        for(String codon : countCodons.keySet()){
            Integer value = countCodons.get(codon);
     
            if (value >= start || value <= end){
                System.out.println(codon + "\t" + value);
            }
        }
    }
    
    public void test(){
        FileResource fr = new FileResource();
        String dna = fr.asString().toUpperCase();
        Dictionary d = new Dictionary();
        
        for(int i=0; i<3;i++){
            System.out.println("==================================");
            d.buildCodonMap(i, dna);
            System.out.println("most common codon is " + d.getMostCommonCodon());
            System.out.println("Counts of codons between 1 and 5 inclusive are:");
            d.printCodonCounts(1,5);
        }
    }

}
