
/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part2 {
    
    public String findSimpleGene(String dna, String startCodon, String stopCodon) {
        
        if (dna == dna.toUpperCase()){
            startCodon = startCodon.toUpperCase();
            stopCodon = stopCodon.toUpperCase();
        } else {
            startCodon = startCodon.toLowerCase();
            stopCodon = stopCodon.toLowerCase();
        }
        
        int startIndex = dna.indexOf(startCodon);
        int stopIndex = dna.indexOf(stopCodon);
        
        if(startIndex == -1 || stopIndex == -1) {
            return "";
        }
        
        String found = dna.substring(startIndex, stopIndex + 3);
        int foundLength = found.length();
        
        if(foundLength % 3 == 0){
            return found;
        } else {
            return "";
        }
    }
    
    public void testSimpleGene(){
        System.out.println("Testing ATGGGTTAAGTC - string returned should be upper case");
        System.out.println(findSimpleGene("ATGGGTTAAGTC", "atg", "taa"));
        System.out.println("----------------------------------------------");
        System.out.println("Testing gatgctataat - string returned should be lower case");
        System.out.println(findSimpleGene("gatgctataat", "ATG", "TAA"));
        System.out.println("----------------------------------------------");
        System.out.println("Testing ATCGAAATTGTCGTA - no string should be returned");
        System.out.println(findSimpleGene("ATCGAAATTGTCGTA", "ATG", "TAA"));
        System.out.println("----------------------------------------------");
        System.out.println("Testing gatgctataat - string returned should be lower case");
        System.out.println(findSimpleGene("gatgctataat", "atg", "taa"));
        System.out.println("----------------------------------------------");
        
    }

}

