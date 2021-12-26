
/**
 * Write a description of WordPlay here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class WordPlay {
    
    public boolean isVowel(char ch){
        // method returns true if ch is a vowel (one of 'a', 'e', 'i', 'o', or 
        // 'u' or the uppercase versions) and false otherwise
        
        String upCaseVowels = "AEIOU";
        
        String lowCaseVowels = "aeiou";
        
        for(int i = 0; i < upCaseVowels.length();i++){
            if (Character.compare(upCaseVowels.charAt(i), ch) == 0){
                return true;
            } else if (Character.compare(lowCaseVowels.charAt(i), ch) == 0){
                return true;
            }
        }
        return false;
    }
    
    
    public String replaceVowels(String phrase, char ch){
        // method should return a String that is the string phrase with all 
        // the vowels (uppercase or lowercase) replaced by ch.
        
        // convert string to string builder class which allows manipulation
        StringBuilder sb = new StringBuilder(phrase);
        
        for(int i = 0; i < phrase.length(); i++){
            
            if (isVowel(phrase.charAt(i))){
                sb.replace(i, i+1, Character.toString(ch));
            }
        }
        
        return sb.toString();
    }
    
    public String emphasise (String phrase, Character ch) {
        /**
         * method should return a String that is the string phrase but with
         * the Char ch (upper- or lowercase) replaced by:
         * 
         * (a) ‘*’ if it is in an odd number location in the string (e.g.
         *     the first character has an odd number location but an even 
         *     index, it is at index 0), or
         *     
         * (b) ‘+’ if it is in an even number location in the string (e.g. the
         *     second character has an even number location but an odd index, 
         *     it is at index 1).
         */ 
        
        // var with string builder that will be manipulated
        StringBuilder sb = new StringBuilder(phrase);
       
        
        // variable to count whether char is in odd or even pos
        int count = 1;
        
        // loop through the characters in the String argument
        for (int i = 0; i < phrase.length(); i++) {
            
            if(Character.compare(Character.toLowerCase(phrase.charAt(i)), Character.toLowerCase(ch)) == 0) {
                
                if ((count % 2) == 0) {
                    sb.replace(i, i+1, "+");
                    count++;
                } else {
                    sb.replace(i, i+1, "*");
                    count++;
                }
                
            } else {
                count++;
            }
        }
        
        return sb.toString();
    }
    
    public void testEmphasise(){
        System.out.println(emphasise("dna ctgaaactga", 'a'));
        System.out.println(emphasise("Mary Bella Abracadabra", 'a'));
    }
    
    public void testReplaceVowels(){
        System.out.println(replaceVowels("Hello World", '*'));
        System.out.println(replaceVowels("BDSM", '@'));
        System.out.println(replaceVowels("Chad Tyrone", ' '));
    }
    
    public void testIsVowel(){
        System.out.println(isVowel('F'));
        System.out.println(isVowel('a'));
        System.out.println(isVowel('i'));
        System.out.println(isVowel('Z'));
    }

}
