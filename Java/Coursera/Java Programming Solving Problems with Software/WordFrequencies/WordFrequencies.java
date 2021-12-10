import java.util.ArrayList;
import edu.duke.*;
/**
 * Write a description of WordFrequencies here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class WordFrequencies {
    
    private ArrayList<String> myWords;
    private ArrayList<Integer> myFreqs;
    
    public WordFrequencies(){
        myWords = new ArrayList<String>();
        myFreqs = new ArrayList<Integer>();
        
    }
    
    public void findUnique(){
        myWords.clear();
        myFreqs.clear();
        
        FileResource fr = new FileResource();
        
        for (String word : fr.words()){
            
            word = word.toLowerCase();
            int found = myWords.indexOf(word);
            if(found == -1){
                myWords.add(word);
                myFreqs.add(1);
            } else {
                int value = myFreqs.get(found);
                myFreqs.set(found, value + 1);
            }
        }
        
    }
    
    public int findIndexOfMax (){
        /**
         * method returns an int that is the index location of the largest 
         * value in myFreqs. If there is a tie, then return the first such 
         * value
         */
        
        int largest = 0;
        
        for(int i = 0; i < myFreqs.size(); i++){
            if (myFreqs.get(i) > largest) {
                largest = myFreqs.get(i);
            }
        }
        
        return largest;
    }
    
    public void tester(){
        findUnique();
        int largest = findIndexOfMax();
        System.out.println("Number of unique words: " + myFreqs.size());
        
        for(int i = 0; i < myWords.size(); i++){
            System.out.println(myFreqs.get(i) + " " + myWords.get(i));
        }
        
        System.out.println("The word that occurs most often and its count are: " + myWords.get(largest) + " " + myFreqs.get(largest));
        
        
    }
}
