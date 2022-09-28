import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;

public class Main {
  public static void displayFirst() {
    System.out.println("Choose your choice of query" + "\n");
    System.out.println("1. Query information through rewards members");
    System.out.println("2. Query information through rewards perks");
    System.out.println("3. What are the reward tiers?");
    System.out.println("4. Quit");
    System.out.println("\n" + "What is your choice?");
  }
  public static void displaySecond() {
      System.out.println("Selected option 1: Query information through rewards members");
      System.out.println("\n" + "1. Miles accumulated in the current year");
      System.out.println("2. Total miles accumulated since joining the rewards program");
      System.out.println("3. Join date of the rewards program");
      System.out.println("4. Current reward tier(based on miles accumluated from the previous year");
      System.out.println("5. Reward tier of GIVEN prior year");
      System.out.println("4. EXIT");
  }
  public static int milesAccumulatedCurrent(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length, int accumulated) {
    accumulated = 0;
    System.out.println("What year? Put year first and then id");
    Scanner input = new Scanner(System.in);
    int yearChoice = input.nextInt();
    int ID = input.nextInt();
    for (int i = 0; i < length; ++i) {
      if ((year[i] == yearChoice) && (memberID[i] == ID)) {
        accumulated += flightMiles[i];
      }
    }
    System.out.println(accumulated);
    return accumulated;
  }
  public static int totalMilesAccumulated(String[] date, int[] memberID, int[] flightMiles,
  int[] year, int length, int overall) {
    overall = 0;
    System.out.println("Which member do you want to search, for the total accumulated miles");
    Scanner input = new Scanner(System.in);
    int ID = input.nextInt();
   for (int i = 0; i < length; ++i) {
      if (memberID[i] == ID) {
        overall += flightMiles[i];
      }
    }
    System.out.println(overall);
    return overall; 
  }
  public static void main(String[] args) throws IOException {
    FileInputStream inputFile = null;
    Scanner scnr = null;
    System.out.println("Opening file input.txt.");
    inputFile = new FileInputStream("input.txt");
    scnr = new Scanner(inputFile);
    
    int counter = 0;
    int accumulated = 0;
    int overall = 0;

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
    
    Scanner myChoice = new Scanner(System.in);
    int choice = 0;
    while (choice == 0) {
    displayFirst();
    choice = myChoice.nextInt();
    if (choice == 1) {
    displaySecond();
    choice = myChoice.nextInt();
    if (choice == 1) {
      milesAccumulatedCurrent(date, memberID, flightMiles, year, length, accumulated);
    } else if (choice == 2) {
      totalMilesAccumulated(date, memberID, flightMiles, year, length, overall);
    }
    } else if (choice == 4) {
      System.edit(0);
    }

    choice = 0;
}

    scnr.close();
    System.out.println("Closing file input.txt");
  }
}
