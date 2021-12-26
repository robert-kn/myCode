import edu.duke.*;
/**
 * Write a description of WordLengths here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class WordLengths {
    
    public int[] countWordLengths(FileResource resource, int[] counts){
        /**
         * This method should read in the words from resource and count the number of words of each length for all 
         * the words in resource, storing these counts in the array counts.
         */
        
        for (String word : resource.words()){
            
            if(word.endsWith(",") || word.endsWith(".")) {
                word = word.substring(0, word.length() - 1);
                counts[word.length()] += 1;
            } else {
                counts[word.length()] += 1;
            }
        }
        
        for(int i = 1; i < counts.length; i++) {
            System.out.println(counts[i] + " words of length " + i);
        }
        return counts;
    }
    
    public int indexOfMax(int[] values){
        /**
         *  method returns the index position of the largest element in values.
         */
        
        int largest = 0;
        
        for(int i = 0; i < values.length; i++){
            if(values[i] > largest){
                largest = values[i];
            }
        }
        return largest;
    }
    
    
    
    
    public void testCountWordLengths() {
        FileResource fr = new FileResource();
        int[] counts = new int[31];
        int[] largest = countWordLengths(fr, counts);
        System.out.println("Largest value " + indexOfMax(largest));
    }

}
