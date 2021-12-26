import edu.duke.*;
import java.io.*;
/**
 * Write a description of Part2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Part2 {
    
    public ImageResource makeInversion(ImageResource inImage){
        // create a new image (all black) using attributes from image passed to the function
        ImageResource outImage = new ImageResource(inImage.getWidth(), inImage.getHeight());
        
        // loop over all the pixels in the created image
        for(Pixel pixel : outImage.pixels()){
            // retrieve the pixel at the corresponding position in inImage
            Pixel currPixel = inImage.getPixel(pixel.getX(), pixel.getY());
            
            // set each RGB value in current pixel to the current value
            // subtracted from 255
            pixel.setRed(255 - currPixel.getRed());
            
            pixel.setGreen(255 - currPixel.getGreen());
            
            pixel.setBlue(255 - currPixel.getBlue());
        }
        return outImage;
    }
    
    public void selectAndConvert(){
        // open a folder and select multiple files
        DirectoryResource dr = new DirectoryResource();
        // loop through each of the files 
        for(File f : dr.selectedFiles()){
            // create an image resource for the current image
            ImageResource ir = new ImageResource(f);
            // get the name of the current image
            String currentName = ir.getFileName();
            // convert the current image to grey colour and save it to a different variable
            ImageResource outImage = makeInversion(ir);
            // set the new file name 
            outImage.setFileName("inverted-"+currentName);
            // save it and then draw it
            outImage.save();
            outImage.draw();
            
        }
        
    }

}
