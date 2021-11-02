import edu.duke.*;
/**
 * Write a description of Part4 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part4 {

        URLResource urlresource;
        
        public void readFile(String URL){
            // Write a program that reads the lines from the file at a URL 
            // location and prints each URL on the page that is a link to 
            // youtube.com
            
            urlresource = new URLResource(URL);
            
            for(String word : urlresource.words()){
                if((word.toLowerCase().contains("youtube.com"))) {
                    int startIndex = word.indexOf("\"");
                    int endIndex = word.indexOf("\"", startIndex + 1);
                    System.out.println(word.substring(startIndex, endIndex + 1));
                }
            }
            
        }
        
        
        public void testing(){
            readFile("https://www.dukelearntoprogram.com//course2/data/manylinks.html");
        }
}
