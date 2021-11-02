
/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part1 {
    
    // This method will return the index of the first occurrence of the stop
    // codon that appears past the start index and is a multiple of three 
    // away from start index. If none exists, it should return the length of
    // the dna strand
    
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
    
    
    public void printAllGenes(String dna){
          
        do {
            
            // find the first valid gene and then print it 
            // (an empty string may be returned)
            String currGene = findGene(dna);
            
            // if no valid gene exists then return an empty string and stop
            // searching
            if(currGene.isEmpty()){
                System.out.println("No valid gene(s)");
                break;
            } else {
                // print out the first gene found
                System.out.println(currGene);
                
                // get the index of the current gene found in the dna string
                int currIndex = dna.indexOf(currGene);
                
                // update the dna string with what is left to keep searching
                // for valid dna genes
                dna = dna.substring(currIndex + currGene.length());
                
            }
             
        } while(!dna.isEmpty()); 
    }
    
    public void testAllGenes(){
        System.out.println("Testing ATGCGCATATAAATGTGAATGTAG with 3 valid genes");
        printAllGenes("ATGCGCATATAAATGTGAATGTAG");
        System.out.println("--------------------------------------------");
        System.out.println("Testing '' with 0 valid genes");
        printAllGenes("");
        System.out.println("--------------------------------------------");
        System.out.println("Testing ATGTCATGGTTATTTATG with 0 valid genes");
        printAllGenes("ATGTCATGGTTATTTATG");
        System.out.println("--------------------------------------------");
        System.out.println("Testing TCATCGTGGTTATTTATG with 0 valid genes");
        printAllGenes("TCATCATGGTTATTTATG");
        
        //System.out.println("Testing ATGTAAATGTAGATGTGA with 3 valid genes");
        //printAllGenes("ATGTAAATGTAGATGTGA");
    }
    
    
    public void testFindGene() {
        System.out.println("Testing TGACGCATAGCT no ATG");
        System.out.println(findGene("TGACGCATAGCT"));
        
        System.out.println("Testing ATGCGCATATAA with one valid stop codon");
        System.out.println(findGene("ATGCGCATATAA"));
        
        System.out.println("Testing ATGCGCTGATAA with two valid stop codons");
        System.out.println(findGene("ATGCGCTGATAA"));
        
        System.out.println("Testing TGAATGATAGCT with ATG and no valid stop codons");
        System.out.println(findGene("TGAATGATAGCT"));
    }
    
    public void testFindStopCodon(){
        System.out.println("Testing gene: ATGGCCTAA");
        System.out.println("Index of gene:012345678");
        System.out.println(findStopCodon("ATGGCCTAA",0,"TAA"));
        System.out.println("--------------------------------");
        
        System.out.println("Testing gene: CCTATGGTA");
        System.out.println("Index of gene:012345678");
        System.out.println(findStopCodon("CCTATGGTA",3,"TAG"));
        System.out.println("--------------------------------");
        
    }

}
