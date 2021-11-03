import edu.duke.*;
/**
 * Write a description of Part3 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part3 {
    
    public int findStopCodon(String dna, int startIndex, String stopCodon){
        
        // stopIndex will hold the index of the stop codon. If it is not
        // found it will be -1
        // search the string for the stopCodon
        int stopIndex = dna.indexOf(stopCodon, startIndex);
        
        // if stopCodon is found check whether it's a multiple of three
        // away from startIndex. If it is return stopIndex.
            
        if ((stopIndex != -1) && (stopIndex - startIndex) % 3 == 0) {
            return stopIndex;
        } 
        
        // return the length of the string if stop codon is not found
        return dna.length();
        
    }
    
    public String findGene (String dna){
        // Find the index of the first occurrence of the start codon “ATG”. 
        // If there is no “ATG”, return the empty string.
        int startIndex = dna.indexOf("ATG");
        
        if (startIndex == -1) {
            return "";
        } 
        
        // the following 3 variable will be assigned to the length of the 
        // dna string if the appropriate stop codons are not found
        int stopTAA = findStopCodon(dna, startIndex, "TAA");
        int stopTAG = findStopCodon(dna, startIndex, "TAG");
        int stopTGA = findStopCodon(dna, startIndex, "TGA");
        int dnaLength = dna.length();
        
        if((stopTAA == dnaLength) && (stopTAG == dnaLength) && (stopTGA == dnaLength)) {
            return "";
        } else {
            int minIndex = 0;
            
            if (stopTAA == dnaLength) {
                minIndex = Math.min(stopTAG, stopTGA);
            } else if (stopTAG == dnaLength) {
                minIndex = Math.min(stopTAA, stopTGA);
            } else if (stopTGA == dnaLength) {
                minIndex = Math.min(stopTAA, stopTGA);
            } else {
                minIndex = Math.min(stopTAA, stopTAG);
                minIndex = Math.min(minIndex, stopTGA);
            }
            
            return dna.substring(startIndex, minIndex + 3);
        } 
    }
    
    public StorageResource getAllGenes(String dna){
        
        StorageResource storageresource = new StorageResource();
          
        do {
            
            // find the first valid gene 
            // (an empty string may be returned)
            String currGene = findGene(dna);
            
            // if no valid gene exists then return an empty storageresouce
            // data object
            if(currGene.isEmpty()){
                return storageresource;
            } else {
                // Add the current gene to the data structure
                storageresource.add(currGene);
                
                // get the index of the current gene found in the dna string
                int currIndex = dna.indexOf(currGene);
                
                // update the dna string with what is left to keep searching
                // for valid dna genes
                dna = dna.substring(currIndex + currGene.length());
                
            }
             
        } while(!dna.isEmpty()); 
        
        return storageresource;
    }
    
    public float cgRatio(String dna) {
        // returns the number of C's and G's in a dna string as a fraction of the
        // entire dna string
        
        int countC = 0;
        int countG = 0;
        
        for(int i = 0; i < dna.length(); i++){
            if (Character.valueOf('C').equals(dna.charAt(i))){
                countC++;
            } else if(Character.valueOf('G').equals(dna.charAt(i))) {
                countG++;
            }
        }
        return (float) (countC + countG)/ dna.length();
    }
    
    public void processGenes(StorageResource sr){
        // this method processes all the strings in sr to extract information
        int longerThan9 = 0;
        int higherThan35 = 0;
        String currGene = "";
        
        for (String str : sr.data()) {
            // print all the Strings in sr that are longer than 9 characters
            if (str.length() > 9){
                System.out.println("Longer than 9 chars " + str);
                longerThan9++;
            }
            
            // print the Strings in sr whose C-G-ratio is higher than 0.35
            if(cgRatio(str) > 0.35) {
                System.out.println("C-G-ratio > 0.35 " + str);
                higherThan35++;
            }
            
            // compare the length of the previous gene found to the current one
            if (str.length() > currGene.length()) {
                currGene = str;
            }
            
        }
        
        // print the number of Strings in sr that are longer than 9 characters
        System.out.println("Number of strings with longer than 9 chars = " + longerThan9);
            
        // print the number of strings in sr whose C-G-ratio is higher than 0.35
        System.out.println("Number of strings with C-G-ratio > 0.35 = " + higherThan35);
            
        // print the length of the longest gene in sr
        System.out.println("Longest gene length found is " + currGene.length());   
    }
    
    public void testProcessGenes(){
        FileResource fileresource = new FileResource("GRch38dnapart.fa");
        String contents = fileresource.asString();
        StorageResource sr = getAllGenes(contents);
        processGenes(sr);
    }
    

}
