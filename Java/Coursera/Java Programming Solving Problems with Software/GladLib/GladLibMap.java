import edu.duke.*;
import java.util.*;

public class GladLibMap {
    private HashMap<String, ArrayList<String>> wordMap;
    
    private ArrayList<String> used;
    
    private ArrayList<String> trackedCategory;
    
    private Random myRandom;
    
    private static String dataSourceURL = "http://dukelearntoprogram.com/course3/data";
    private static String dataSourceDirectory = "data";
    
    public GladLibMap(){
        wordMap = new HashMap<String, ArrayList<String>>();
        used = new ArrayList<String>();
        trackedCategory = new ArrayList<String>();
        initializeFromSource(dataSourceDirectory);
        myRandom = new Random();
    }
    
    public GladLibMap(String source){
        wordMap = new HashMap<String, ArrayList<String>>();
        used = new ArrayList<String>();
        trackedCategory = new ArrayList<String>();
        initializeFromSource(source);
        myRandom = new Random();
    }
    
    private void initializeFromSource(String source) {
        
        String[] categories = {"adjective.txt","noun.txt","color.txt","country.txt","name.txt","animal.txt","timeframe.txt","verb.txt","fruit.txt"};
                                        
        for(String category : categories){
            int period = category.indexOf(".");
            String categoryName = category.substring(0, period);
            wordMap.put(categoryName, readIt(source+"/"+category));
        }
            
        
    }
    
    private String randomFrom(ArrayList<String> source){
        int index = myRandom.nextInt(source.size());
        return source.get(index);
    }
    
    private String getSubstitute(String label) {
        for(String category : wordMap.keySet()){
            if(category.equals(label)){
                if(!trackedCategory.contains(label)){
                    trackedCategory.add(label);
                }
                return randomFrom(wordMap.get(category));
            }
        }
        return "**UNKNOWN**";
    }
    
    private String processWord(String w){
        int first = w.indexOf("<");
        int last = w.indexOf(">",first);
        if (first == -1 || last == -1){
            return w;
        }
        String prefix = w.substring(0,first);
        String suffix = w.substring(last+1);
        String sub = getSubstitute(w.substring(first+1,last));
        while(used.contains(sub)){
            sub = getSubstitute(w.substring(first+1,last));
        }
        used.add(sub);
        return prefix+sub+suffix;
    }
    
    private void printOut(String s, int lineWidth){
        int charsWritten = 0;
        for(String w : s.split("\\s+")){
            if (charsWritten + w.length() > lineWidth){
                System.out.println();
                charsWritten = 0;
            }
            System.out.print(w+" ");
            charsWritten += w.length() + 1;
        }
    }
    
    private String fromTemplate(String source){
        String story = "";
        if (source.startsWith("http")) {
            URLResource resource = new URLResource(source);
            for(String word : resource.words()){
                story = story + processWord(word) + " ";
            }
        }
        else {
            FileResource resource = new FileResource(source);
            for(String word : resource.words()){
                story = story + processWord(word) + " ";
            }
        }
        return story;
    }
    
    private ArrayList<String> readIt(String source){
        ArrayList<String> list = new ArrayList<String>();
        if (source.startsWith("http")) {
            URLResource resource = new URLResource(source);
            for(String line : resource.lines()){
                list.add(line);
            }
        }
        else {
            FileResource resource = new FileResource(source);
            for(String line : resource.lines()){
                list.add(line);
            }
        }
        return list;
    }
    
    public int totalWordsInMap(){
        /**
         * method returns the total number of words in all the ArrayLists in the 
         * HashMap
         */
        
        int total = 0;
        
        for(ArrayList<String> aL : wordMap.values()){
            total += aL.size();
        }
        return total;
    }
    
    public int totalWordsConsidered(){
        /**
         * method returns the total number of words in the ArrayLists of the categories
         * that were used for a particular GladLib
         */
        int wordsConsidered = 0;
        for(String category : trackedCategory){
            wordsConsidered += wordMap.get(category).size();
        }
        return wordsConsidered;
    }
    
    public void makeStory(){
        used.clear();
        trackedCategory.clear();
        //wordMap.clear();
        System.out.println("\n");
        String story = fromTemplate("data/madtemplate2.txt");
        printOut(story, 60);
        System.out.println("\nThe words to pick from totaled " + totalWordsInMap());
        System.out.println("\nThe words considered totaled " + totalWordsConsidered());
    }
    


}
