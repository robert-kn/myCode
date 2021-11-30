import edu.duke.*;
/**
 * Write a description of CaesarCipher here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class CaesarCipher {
    
    public String encryptTwoKeys (String input, int key1, int key2) {
        /**
         *  method returns a String that has been encrypted using the following algorithm.
         *  
         *  (a) Parameter key1 is used to encrypt every other character with the Caesar Cipher algorithm, 
         *      starting with the first character
         *      
         *  (b) key2 is used to encrypt every other character, starting with the second character.
         */
        
        StringBuilder sb = new StringBuilder(input);
        
        // count variable will determine whether char is in an odd or even position
        int count = 1;
        
        // loop through input String to encode each char with corresponding key
        for (int i = 0; i < input.length(); i++) {
        
                // extract the current char
                char currentChar = input.charAt(i);
                
                // is char in an odd or even position?
                if ((count % 2) != 0) {
                    // encrypt the char
                    String encryptedChar = encrypt(Character.toString(currentChar), key1);
                    
                    sb.replace(i, i+1, encryptedChar);
                    
                    count++;
                } else {
                    // encrypt the char
                    String encryptedChar = encrypt(Character.toString(currentChar), key2);
                    
                    sb.replace(i, i+1, encryptedChar);
                    
                    count++;
                }
                
                
        }
        
        return sb.toString();
    }
    
    public String encrypt (String input, int key) {
        /**
         * method returns a String that has been encrypted using the Caesar 
         * Cipher algorithm
         */
        
        StringBuilder sb = new StringBuilder(input);
        
        String upCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String shiftedUpCase = upCase.substring(key) + upCase.substring(0, key);
        
        String lowCase = "abcdefghijklmnopqrstuvwxyz";
        String shiftedLowCase = lowCase.substring(key) + lowCase.substring(0, key);
        
        // loop through the string and encode the input String
        for (int i = 0; i < input.length(); i++) {
            
            // read the current char
            char currentChar = input.charAt(i);
            
            // determine the case of the char
            if (Character.isUpperCase(currentChar)){
                
                // find it's index in non shifted alphabet
                int upCaseIndex = upCase.indexOf(currentChar);
                
                // find the character occupying the same index in the shifted alphabet
                char shiftedChar = shiftedUpCase.charAt(upCaseIndex);
                
                sb.replace(i, i+1, Character.toString(shiftedChar));
                
            } else if (Character.isLowerCase(currentChar)) {
                
                // find it's index in non shifted alphabet
                int lowCaseIndex = lowCase.indexOf(currentChar);
                
                // find the character occupying the same index in the shifted alphabet
                char shiftedChar = shiftedLowCase.charAt(lowCaseIndex);
                
                sb.replace(i, i+1, Character.toString(shiftedChar));
            } 
            
            
        }
        
        return sb.toString();
    }
    
    public void testEncryptTwoKeys(){
        System.out.println(encryptTwoKeys("First Legion", 23, 17));
    }
    
    public void testEncrypt(){
        System.out.println(encrypt("First Legion", 17));
    }
    
    public void testCaesar(){
        FileResource fr = new FileResource ();
        String message = fr.asString();
        String encrypted = encrypt(message, 13);
        System.out.println("key is " + 13 + "\n" + encrypted);
    }

}
