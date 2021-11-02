
/**
 * Write a description of Part2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part2 {
    
    public int howMany(String stringa, String stringb){
        // how many times does stringa appear in stringb?
        
        // declare and initialise a counting variable to 0
        int count = 0;
        
        // find remaining occurrences of stringa in stringb by looping 
        // through string as long as it is not empty
        while(!stringb.isEmpty()) {
            
            // find the index of the first occurrence of stringa in stringb
            int found = stringb.indexOf(stringa);
            
            // increment the counting variable by 1
            if(found != -1){
                count += 1;
            
                // update stringb to point to the remainder of the string that doesn't
                // have the first occurrence of stringa in it
                
                stringb= stringb.substring(found + stringa.length());
                
            } else {
                return count;
            }
        }
        
        return count;
    }
    
    
    public void testHowMany(){
        System.out.println("Testing howMany(“GAA”, “ATGAACGAATTGAATC”) returns 3");
        System.out.println(howMany("GAA", "ATGAACGAATTGAATC"));
        System.out.println("--------------------------------------------");
        System.out.println("Testing howMany(“AA”, “ATAAAA”)”) returns 2");
        System.out.println(howMany("AA", "ATAAAA"));
        System.out.println("--------------------------------------------");
        System.out.println("Testing howMany(“AA”, “”)”) returns 0");
        System.out.println(howMany("AA", ""));
        System.out.println("--------------------------------------------");
        System.out.println("Testing howMany(“”, “”)”) returns 0");
        System.out.println(howMany("", ""));
        System.out.println("--------------------------------------------");
        System.out.println("Testing howMany(“AA”, “TGCTACTAA”)”) returns 1");
        System.out.println(howMany("AA", "TGCTACTAA"));
        
    }

}
