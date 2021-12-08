
/**
 * Write a description of CaesarCipher2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class CaesarCipher2 {
    
    private String alphabet = "abcdefghijklmnopqrstuvwxyz";
    private String shiftedAlphabet;
    private StringBuilder sb;
    private int mainKey;
    
    public CaesarCipher2(int key){
        this.shiftedAlphabet = alphabet.substring(key) + alphabet.substring(0, key);
        this.mainKey = key;
    }
    
    public String encrypt (String input) {
        
        sb = new StringBuilder(input);
        
        // loop through the string and encode the input String
        for (int i = 0; i < input.length(); i++) {
            
            // read the current char
            char currentChar = Character.toLowerCase(input.charAt(i));
                
            // find it's index in non shifted alphabet
            int lowCaseIndex = alphabet.indexOf(currentChar);
                
            // find the character occupying the same index in the shifted alphabet
            char shiftedChar = shiftedAlphabet.charAt(lowCaseIndex);
                
            sb.replace(i, i+1, Character.toString(shiftedChar));
        } 
         
        return sb.toString();
    }
    
    public String decrypt(String input){
        CaesarCipher2 cc2 = new CaesarCipher2(26 - mainKey);
        return cc2.encrypt(input);
    }

}
