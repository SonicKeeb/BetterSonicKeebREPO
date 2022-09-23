import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;

public class Main {
  public static void main (String[] args) throws IOException {
    FileInputStream inputFile = null;
    Scanner scnr = null;
    String[] date = new String[37];
    int[] memberID = new int[37];
    int[] flightMiles = new int[37];
    int totalMiles1, totalMiles2, totalMiles3, totalMiles4, totalMiles5, totalMiles6,
        totalMiles7, totalMiles8, totalMiles9, totalMiles10, totalMiles11, totalMiles12;

    System.out.println("Opening file input.txt.");
    inputFile = new FileInputStream("input.txt");
    scnr = new Scanner(inputFile);

    for (int i = 0; i < 37; ++i) {
      date[i] = scnr.next();
      memberID[i] = scnr.nextInt();
      flightMiles[i] = scnr.nextInt();
    }

    totalMiles1 = flightMiles[0];
    totalMiles2 = flightMiles[1];
    totalMiles3 = flightMiles[2];
    totalMiles4 = flightMiles[3];
    totalMiles5 = flightMiles[4];
    totalMiles6 = flightMiles[5];
    totalMiles7 = flightMiles[6];
    totalMiles8 = flightMiles[7];
    totalMiles9 = flightMiles[8];
    totalMiles10 = flightMiles[9];
    totalMiles11 = flightMiles[10];
    totalMiles12 = flightMiles[11];


    for (int i = 0; i < 36; ++i) {
      System.out.println("Date: " + date[i] + " MemberID: " + memberID[i] 
                                  + " FlightMiles: " + flightMiles[i]);
    }

    System.out.println(totalMiles1);

    System.out.println("Closing file input.txt");
    inputFile.close();
  }
}
