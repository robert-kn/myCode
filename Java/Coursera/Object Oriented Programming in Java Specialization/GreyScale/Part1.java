import edu.duke.*;
import java.io.*;
/**
 * Write a description of Part1 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part1 {
    
    public ImageResource convertToGrey(ImageResource inImage){
        // create a new image (all black) using attributes from image passed to the function
        ImageResource outImage = new ImageResource(inImage.getWidth(), inImage.getHeight());
        
        // loop over all the pixels in the created image
        for(Pixel pixel : outImage.pixels()){
            // retrieve the pixel at the corresponding position in inImage
            Pixel currPixel = inImage.getPixel(pixel.getX(), pixel.getY());
            
            // calculate the average colour density of this pixel
            int average = (currPixel.getRed() + currPixel.getGreen() + currPixel.getBlue()) / 3;
            
            // set each RGB value in current pixel of outImage to average
            pixel.setRed(average);
            
            pixel.setGreen(average);
            
            pixel.setBlue(average);
        }
        return outImage;
    }
    
    public void saveGrey(){
        // open a folder and select multiple files
        DirectoryResource dr = new DirectoryResource();
        // loop through each of the files 
        for(File f : dr.selectedFiles()){
            // create an image resource for the current image
            ImageResource ir = new ImageResource(f);
            // get the name of the current image
            String currentName = ir.getFileName();
            // convert the current image to grey colour and save it to a different variable
            ImageResource outImage = convertToGrey(ir);
            // set the new file name 
            outImage.setFileName("grey-"+currentName);
            // save it and then draw it
            outImage.save();
            outImage.draw();
            
        }
        
    }
    
    public void testConvertToGrey(){
        ImageResource ir = new ImageResource();
        convertToGrey(ir).draw();
    }
}
