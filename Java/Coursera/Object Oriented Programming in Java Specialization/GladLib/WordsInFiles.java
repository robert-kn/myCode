import java.util.HashMap;
import java.util.ArrayList;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import edu.duke.*;
/**
 * Write a description of WordsInFiles here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class WordsInFiles {
    private HashMap<String, ArrayList<String>> wordFileMap;
    
    public WordsInFiles(){
        wordFileMap = new HashMap<String, ArrayList<String>>();    
    }
    
    public void printFilesIn(String word){
        /**
         * method prints the names of the files this word appears in, one 
         * filename per line
         */
        for(String currWord : wordFileMap.keySet()){
            
            if(currWord.equals(word)){
                for(String fileName : wordFileMap.get(word)){
                    System.out.println(fileName);
                }
            }
        }
    
    }
    
    public ArrayList<String> wordsInNumFiles(int number){
        /**
         * method returns an ArrayList of words that appear in exactly 
         * number files
         */
        
        ArrayList<String> aL = new ArrayList<String>();
        
        for(String word : wordFileMap.keySet()){
            if(wordFileMap.get(word).size() == number){
                aL.add(word);
            }
        }
        return aL;
    }
    
    public int maxNumber(){
        /**
         * method returns the maximum number of files any word appears in, 
         * considering all words from a group of files
         */
        
        int largestNum = 0;
        
        for(ArrayList<String> aL : wordFileMap.values()){
            if(aL.size() > largestNum){
                largestNum = aL.size();
            }
        }
        
        return largestNum;
    }
    
    public void addWordsFromFile(File f){
        /**
         * method should add all the words from f into the map. If a word is 
         * not in the map, then you must create a new ArrayList of type String 
         * with this word, and have the word map to this ArrayList. If a word 
         * is already in the map, then add the current filename to its 
         * ArrayList, unless the filename is already in the ArrayList. 
         */
        Scanner scanner = null;
        try {
            scanner = new Scanner(f);
            
            
        } catch (FileNotFoundException e){
            System.out.println("File could not be opened");
        }
        
        while(scanner.hasNext()){
            String word = scanner.next().toLowerCase();
            String name = f.getName();
            
            if (!wordFileMap.containsKey(word)){
               wordFileMap.put(word, new ArrayList<String>());
               
               wordFileMap.get(word).add(name);
            } else{
                if (wordFileMap.get(word).contains(name)){
                    continue;
                } else {
                    wordFileMap.get(word).add(name);
                }
            }
        }
        
        
    }
    
    public void buildWordFileMap(){
        wordFileMap.clear();
        DirectoryResource dr = new DirectoryResource();
        WordsInFiles wif = new WordsInFiles();
        for(File f : dr.selectedFiles()){
            wif.addWordsFromFile(f);
        }
        int largest = wif.maxNumber();
        System.out.println("Maximum number of files a word appears in " + largest);
        
        ArrayList<String> words = wif.wordsInNumFiles(largest);
        
        for(String word : words){
            wif.printFilesIn(word);
            System.out.println(word);
        }
            
    }
}
