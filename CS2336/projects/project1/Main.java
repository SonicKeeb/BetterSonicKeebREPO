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
    System.out.println("2. What are the reward tiers?");
    System.out.println("3. Quit");
    System.out.println("\n" + "What is your choice?");
  }
  public static void displaySecond() {
    System.out.println("Selected option 1: Query information through rewards members");
    System.out.println("\n" + "1. Miles accumulated in the current year");
    System.out.println("2. Total miles accumulated since joining the rewards program");
    System.out.println("3. Join date of the rewards program");
    System.out.println("4. Current reward tier(based on miles accumluated from the previous year");
    System.out.println("5. Reward tier of GIVEN prior year");
    System.out.println("6. EXIT");
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
  public static void whatAreRewardsMembers() {
    System.out.println("Gold: 25,000 miles. Gold passengers get special perks such as a seat to sit in during the flight.");
    System.out.println("Platinum: 50,000 miles. Platinum passengers get complementary upgrades to padded seats.");
    System.out.println("\t" + "* Platinum Pro – 75,000 miles. Platinum Pro is a special sub-tier of Platinum, in which the padded seats include arm rests.");
    System.out.println("Executive Platinum: 100,000 miles. Executive Platinum passengers enjoy perks such as complementary upgrades from the cargo hold to main cabin.");
    System.out.println("\t" + "* Super Executive Platinum – 150,000 miles. Super Executive Platinum is a special sub-tier of Executive Platinum, reserved for the most loyal passengers. To save costs, airline  management decided to eliminate the position of co-pilot, instead opting to reserve the co-pilot’s seat for Super Executive Platinum passengers.");
  }
  public static String joinDate(String[] date, int[] memberID, int[] year, int length) {
    System.out.println("Enter in the memberID you wish to find the join date for");
    String creation = "";
    Scanner input = new Scanner(System.in);
    int ID = input.nextInt();
    for (int i = 0; i < length; ++i) {
      if (memberID[i] == ID) {
        System.out.println("This is the join date " + date[i]);
        creation += date[i];
        break;
      }
    }
    return creation;
  }
  public static String currentTier(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length) {
    String tier = "";
    int totalMiles = 0;
    System.out.println("Enter in the year and then the ID to find the tier belonging to that year");
    Scanner input = new Scanner(System.in);
    int time = input.nextInt();
    int ID = input.nextInt();
    for (int i = 0; i < length; ++i) {
      if ((year[i] == time) && (memberID[i] == ID)) {
        totalMiles += flightMiles[i];
      }
      if ((totalMiles >= 25000) && (totalMiles < 50000)) {
        tier = "Gold";
      } else if ((totalMiles >= 500000) && (totalMiles < 75000)) {
        tier = "Platinum";
      } else if ((totalMiles >= 75000) && (totalMiles < 100000)) {
        tier = "Executive Platinum";
      } else if (totalMiles >= 150000) {
        tier = "Super Executive Platinum";
      } else {
        tier = "Not enough for any tier";
      }
    }
    System.out.println("Total traveled miles during this year was " + totalMiles + " Tier: " + tier);
    return tier;
  }
  public static String previousYear(String[] date, int[] memberID, int[] flightMiles, int[] year,
      int length) {
    String tier = "";
    int ID;
    int totalMiles = 0;
    int latestYear = 0;
    int previousYear = 0;
    System.out.println("Enter in the ID ");
    Scanner input = new Scanner(System.in);
    ID = input.nextInt();
    for (int i = length-1; i > 0; --i) {
      latestYear = year[i];
      previousYear = year[i-1];
      if (previousYear != latestYear) {
        break;
      }
    }
    for (int i = 0; i < length; ++i) {
      if ((year[i] == previousYear) && (memberID[i] == ID)) {
        totalMiles += flightMiles[i];
      }
    }
    System.out.println("Previous year miles: " + totalMiles);
    return tier;
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
        } else if (choice == 3) {
          joinDate(date, memberID, year, length);
        } else if (choice == 4) {
          previousYear(date, memberID, flightMiles, year, length);
        } else if (choice == 5) {
          currentTier(date, memberID, flightMiles, year, length);
        } else if (choice == 6) { //This is the exit for after selecting query by id
          System.exit(1);
        }
      } else if (choice == 3) { //This is the exit for first display
        System.exit(0);
      } else if (choice == 2) {
        whatAreRewardsMembers();
      }

      choice = 0;
    }

    scnr.close();
    System.out.println("Closing file input.txt");
  }
}
