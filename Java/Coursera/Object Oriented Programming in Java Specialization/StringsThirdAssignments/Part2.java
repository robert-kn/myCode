
/**
 * Write a description of Part2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part2 {
    
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
    
    
    public int countCTG(String dna) {
        
        // declare and initialise counting variable
        int countCTG = 0;
        
        int dnaLength = dna.length();
        
        int codonLength = "CTG".length();
        
        int index = 0;
        
        // loop through the dna string checking how many times CTG appears in
        // it. The loop advances by one each cycle
        
        while(index <= (dnaLength - codonLength)) {
            
            if(dna.substring(index, index + 3).equals("CTG")){
                countCTG++;
            }
            
            index++;
        }
        
        return countCTG;
    }
    
    public void testCTG(){
        System.out.println("Testing CTG answer will be 1");
        System.out.println(countCTG("CTG"));
        System.out.println("--------------------------------------------");
        System.out.println("Testing CTGCTGCTG answer will be 3");
        System.out.println(countCTG("CTGCTGCTG"));
        System.out.println("--------------------------------------------");
        System.out.println("Testing '' answer will be 0");
        System.out.println(countCTG(""));
        System.out.println("--------------------------------------------");
        System.out.println("Testing 'ATGTAAd' answer will be 0");
        System.out.println(countCTG(""));
        System.out.println("--------------------------------------------");
    }
    
    public void testCgRatio() {
        System.out.println("Testing ATGCGCAT ans should be 4/8");
        System.out.println(cgRatio("ATGCGCAT"));
        System.out.println("--------------------------------------------");
        System.out.println("Testing ATGCCATAG ans should be 4/9");
        System.out.println(cgRatio("ATGCCATAG"));
        System.out.println("--------------------------------------------");
    }

}
