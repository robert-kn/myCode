import java.util.ArrayList;
import edu.duke.*;
/**
 * Write a description of CharactersInPlay here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class CharactersInPlay {
    
    private ArrayList<String> names = new ArrayList<String>();
    private ArrayList<Integer> counts = new ArrayList<Integer>();
    
    
    public void update(String person){
        /**
         * method should update the two ArrayLists, adding the character’s name
         * if it is not already there, and counting this line as one speaking 
         * part for this person
         */
        
        if(names.isEmpty() || !names.contains(person)){
            names.add(person);
            counts.add(1);
        } else {
            int index = names.indexOf(person);
            int frequency = counts.get(index);
            counts.set(index, frequency + 1);
        }
    }
    
    public void findAllCharacters(){
        FileResource fr = new FileResource();
        for(String line : fr.lines()){
            int index = line.indexOf(".");
            if(index != -1){
                String person = line.substring(0, index);
                update(person);
            }
        }
        
    }
    
    public void charactersWithNumParts(int num1, int num2){
        /**
         *  assume num1 should be less than or equal to num2
         *  
         *  Method should print out the names of all those characters that 
         *  have exactly number speaking parts
         */
    }
    
    public void tester(){
        findAllCharacters();
        for(int i = 0; i < names.size(); i++){
            if(counts.get(i) > 30) {
                System.out.println(names.get(i) + " speaks " + counts.get(i));
            }
        }
    }

}
