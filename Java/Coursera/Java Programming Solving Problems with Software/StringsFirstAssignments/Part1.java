
/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part1 {
    
    public String findSimpleGene(String dna) {
        // find the position of the start codon
        int startIndex = dna.indexOf("ATG");
        // find the index of the stop codon after the start codon that was 
        // found
        int stopIndex = dna.indexOf("TAA", startIndex);
        // if no ATG or TAA was found return am empty string
        if(startIndex == -1 || stopIndex == -1) {
            return "";
        }
        
        // retrieves the substring using the start and stop indexes
        String found = dna.substring(startIndex, stopIndex + 3);
        
        int foundLength = found.length();
        
        if(foundLength % 3 == 0){
            return found;
        } else {
            return "";
        }
    }
    
    public void testSimpleGene(){
        System.out.println("Testing ATCGAAATTGTCTAA with no ATG");
        System.out.println(findSimpleGene("ATCGAAATTGTCTAA"));
        System.out.println("---------------------------------------");
        System.out.println("Testing ATCGAAATTGTCATG with no TAA");
        System.out.println(findSimpleGene("ATCGAAATTGTCATG"));
        System.out.println("---------------------------------------");
        System.out.println("Testing ATCGAAATTGTCGTA with no TAA or ATG");
        System.out.println(findSimpleGene("ATCGAAATTGTCGTA"));
        System.out.println("---------------------------------------");
        System.out.println("Testing ATGGAAATTGTCTAA with TAA and ATG");
        System.out.println(findSimpleGene("ATGGAAATTGTCTAA"));
        System.out.println("---------------------------------------");
        System.out.println("Testing ATCGAAATGGTCGCTAA with TAA and ATG but not mult of 3");
        System.out.println(findSimpleGene("ATCGAAATTGTCGCTAA"));
    }

}
