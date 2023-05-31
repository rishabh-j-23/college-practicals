import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.CharBuffer;

public class Prac9 {
    public static void main(String[] args) {
        File f = new File("src/filehandling/prac9.txt");

        try {
            if(f.createNewFile()){
                System.out.println(f.toPath());
            } else {
                System.out.println("file already exists");
            }
            
            System.out.println(f.getAbsolutePath());
            System.out.println(f.getName());
            System.out.println(f.getTotalSpace());
            System.out.println(f.getUsableSpace());
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            FileWriter fw = new FileWriter("src/filehandling/prac9.txt");
            fw.write("file writer");
            fw.close();
            FileReader fileReader = new FileReader(f);
            fileReader.read();
            fileReader.close();

        } catch (Exception e) {
            // TODO: handle exception
        }
        
    }
}