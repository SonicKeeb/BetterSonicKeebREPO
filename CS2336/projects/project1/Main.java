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
    int totalMiles1 = 0, totalMiles2 = 0, totalMiles3 = 0, totalMiles4 = 0, totalMiles5 = 0, totalMiles6 = 0,
        totalMiles7 = 0, totalMiles8 = 0, totalMiles9 = 0, totalMiles10 = 0, totalMiles11 = 0, totalMiles12 = 0;

    System.out.println("Opening file input.txt.");
    inputFile = new FileInputStream("input.txt");
    scnr = new Scanner(inputFile);
    int count = 0;
    for (int i = 0; i < 37; ++i) {
      date[i] = scnr.next();
      memberID[i] = scnr.nextInt();
      flightMiles[i] = scnr.nextInt();
      if (memberID[0] == memberID[i]) {
        count++;
        totalMiles1 += flightMiles[i];
      }
      if (memberID[1] == memberID[i]) {
        count++;
        totalMiles2 += flightMiles[i];
      }
      if (memberID[2] == memberID[i]) {
        count++;
        totalMiles3 += flightMiles[i];
      }
      if (memberID[3] == memberID[i]) {
        count++;
        totalMiles4 += flightMiles[i];
      }
      if (memberID[4] == memberID[i]) {
        count++;
        totalMiles5 += flightMiles[i];
      }
      if (memberID[5] == memberID[i]) {
        count++;
        totalMiles6 += flightMiles[i];
      }
      if (memberID[6] == memberID[i]) {
        count++;
        totalMiles7 += flightMiles[i];
      }
      if (memberID[7] == memberID[i]) {
        count++;
        totalMiles8 += flightMiles[i];
      }
      if (memberID[8] == memberID[i]) {
        count++;
        totalMiles9 += flightMiles[i];
      }
      if (memberID[9] == memberID[i]) {
        count++;
        totalMiles10 += flightMiles[i];
      }
      if (memberID[10] == memberID[i]) {
        count++;
        totalMiles11 += flightMiles[i];
      }
      if (memberID[11] == memberID[i]) {
        count++;
        totalMiles12 += flightMiles[i];
      }
    }

    for (int i = 0; i < 36; ++i) {
      System.out.println("Date: " + date[i] + " MemberID: " + memberID[i] 
          + " FlightMiles: " + flightMiles[i]);
    }

    System.out.println("Total cumulative count of each member id: ");
    System.out.println("101: " + totalMiles1 + " 102: " + totalMiles2 + " 103: " + totalMiles3 + "104: " + totalMiles4
        + " 105: " + totalMiles5 + " 106: " + totalMiles6 + "107: " + totalMiles7 + " 108: " + totalMiles8 + " 109: " + totalMiles9 +
        "110: " + totalMiles10 + " 111: " + totalMiles11 + " 112: " + totalMiles12);

    System.out.println("Closing file input.txt");
    inputFile.close();
  }
}
