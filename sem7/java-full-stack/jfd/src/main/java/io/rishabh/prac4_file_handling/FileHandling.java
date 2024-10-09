package io.rishabh.prac4_file_handling;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileHandling {
    public static void main(String[] args) throws IOException {
        fileReadWrite();
        bufferReadWrite();
    }

    public static void fileReadWrite() throws IOException {
        File f = new File("./filehandling.txt");
        if (!f.exists())
            f.createNewFile();

        FileWriter fw = new FileWriter(f);
        fw.write("written using file writer\n");
        fw.close();

        FileReader fr = new FileReader(f);
        int i;
        while ((i = fr.read()) != -1) {
            System.out.print((char) i);
        }
        fr.close();
    }

    public static void bufferReadWrite() throws IOException {
        File f = new File("./filehandlingbuffer.txt");
        if (!f.exists())
            f.createNewFile();

        FileWriter fw = new FileWriter(f);
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write("written from budffered reader");
        bw.write("\nsecond line");
        bw.close();
        fw.close();

        FileReader fr = new FileReader(f);
        BufferedReader br = new BufferedReader(fr);
        System.out.println(br.readLine());
        br.close();
        fr.close();
    }
}
