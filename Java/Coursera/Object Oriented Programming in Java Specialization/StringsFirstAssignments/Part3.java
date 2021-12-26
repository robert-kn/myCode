
/**
 * Write a description of Part3 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part3 {
    
    public boolean twoOccurrences(String stringa, String stringb){
        // should return true if stringa appears at least twice in stringb
        // otherwise it returns false
        
        // declare and initialise the count variable
        int count = 0;
        
        // start searching for stringa in stringb repeatedly until 
        // condition in while clause is false
        do {
            // find the current index of stringa in stringb
            int found = stringb.indexOf(stringa);
            
            // if not stringa is not found then break from the loop
            if(found == -1){
                break;
            } else{
                // otherwise increase count by 1
                count += 1;
                
                // update stringb such that it excludes the most recent
                // copy of stringa that was found above
                stringb = stringb.substring(found + stringa.length());
            }
        }while(!stringb.isEmpty());
        
        if(count >= 2) {
            return true;
        } else {
            return false;
        }
    
    }
    
    
    public String lastPart(String stringa, String stringb){
        // finds the first occurrence of stringa in stringb, and returns the 
        // part of stringb that follows stringa
        // If stringa does not occur in stringb, then return stringb.
        int found = stringb.indexOf(stringa);
        
        if (found == -1) {
            return stringb;
        } else{
            return stringb.substring(found + stringa.length());
        }
    }
    
    public void testing(){
        System.out.println("Testing 'an' and 'banana'");
        System.out.println(twoOccurrences("an","banana"));
        
        System.out.println("Testing 'sh' and 'shower'");
        System.out.println(twoOccurrences("sh","shower"));
        
        System.out.println("Testing 'ta' and 'melons'");
        System.out.println(twoOccurrences("sh","shower"));
        
        System.out.println("Testing 'atg' and 'ctgtatgta'");
        System.out.println(twoOccurrences("atg","ctgtatgta"));
    }
    
    public void testing2(){
        System.out.println("Testing 'an' and 'banana'");
        System.out.println(lastPart("an","banana"));
        
        System.out.println("Testing 'sh' and 'shower'");
        System.out.println(lastPart("sh","shower"));
        
        System.out.println("Testing 'ta' and 'melons'");
        System.out.println(lastPart("ta","melons"));
    }

}
