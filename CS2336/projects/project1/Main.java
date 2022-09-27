import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;

public class Main {

  public static void main (String[] args) throws IOException {
    int counter = 0;
    FileInputStream inputFile = null;
    Scanner scnr = null;
    // year[index].substring(0,4);
    System.out.println("Opening file input.txt.");
    inputFile = new FileInputStream("input.txt");
    scnr = new Scanner(inputFile);
    
    while (scnr.hasNextLine()) {
      counter = counter + 1;
      scnr.nextLine();
    }

    scnr.close();
    inputFile = new FileInputStream("input.txt");
    scnr = new Scanner(inputFile);
    int length = counter;
    System.out.println("Length of file: " + length);

    String[] date = new String[length];
    int[] memberID = new int[length];
    int[] flightMiles = new int[length];
    int[] year = new int[length];

    for (int i = 0; i < length; ++i) {
      date[i] = scnr.next();
      memberID[i] = scnr.nextInt();
      flightMiles[i] = scnr.nextInt();
      year[i] = Integer.parseInt(date[i].substring(0,4));
    }

    

    scnr.close();
    System.out.println("Closing file input.txt");
  }
}
