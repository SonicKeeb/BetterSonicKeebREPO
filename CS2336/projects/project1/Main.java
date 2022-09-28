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
    System.out.println("Welcome to the flight members status terminal! \n");
    System.out.println("Choose your choice of query" + "\n");
    System.out.println("1. Query information through rewards members");
    System.out.println("2. What are the reward tiers?");
    System.out.println("3. Quit");
    System.out.println("\n" + "What is your choice?");
    System.out.print("Choice: ");
  }
  public static void displaySecond() {
    System.out.println("Selected option 1: Query information through rewards members");
    System.out.println("\n" + "1. Miles accumulated in the current year");
    System.out.println("2. Total miles accumulated since joining the rewards program");
    System.out.println("3. Join date of the rewards program");
    System.out.println("4. Current reward tier(based on miles accumluated from the previous year");
    System.out.println("5. Reward tier of GIVEN prior year");
    System.out.println("6. EXIT");
    System.out.println("*. Press any other number to go back to previous page");
  }
  public static int milesAccumulatedCurrent(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length, int accumulated) {
    int currentYear = year[length-1];
    accumulated = 0;
    System.out.println("\n");
    System.out.print("Input ID to find accumulated miles for current year: ");
    Scanner input = new Scanner(System.in);
    int ID = input.nextInt();
    for (int i = 0; i < length; ++i) {
      if ((year[i] == currentYear) && (memberID[i] == ID)) {
        accumulated += flightMiles[i];
      }
    }
    System.out.print("\n");
    System.out.println("Miles Accumulated this year: " + accumulated + "\n");
    return accumulated;
  }
  public static int totalMilesAccumulated(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length, int overall) {
    overall = 0;
    System.out.print("Input Member ID for the total miles since joining the members program: ");
    Scanner input = new Scanner(System.in);
    int ID = input.nextInt();
    for (int i = 0; i < length; ++i) {
      if (memberID[i] == ID) {
        overall += flightMiles[i];
      }
    }
    System.out.println("\n");
    System.out.println("Total Miles Since Joining: " + overall + "\n");
    return overall; 
  }
  public static void whatAreRewardsMembers() {
    System.out.println("Gold: 25,000 miles. Gold passengers get special perks"); 
    System.out.println("such as a seat to sit in during the flight." + "\n");
    System.out.println("Platinum: 50,000 miles. Platinum passengers get complementary");
    System.out.println("upgrades to padded seats." + "\n");
    System.out.println("\t" + "* Platinum Pro – 75,000 miles. Platinum Pro is a special sub-tier");
    System.out.println("\t" + "of Platinum, in which the padded seats include arm rests." + "\n");
    System.out.println("Executive Platinum: 100,000 miles. Executive Platinum passengers enjoy perks");
    System.out.println("such as complementary upgrades from the cargo hold to main cabin." + "\n");
    System.out.println("\t" + "* Super Executive Platinum – 150,000 miles. Super Executive Platinum");
    System.out.println("\t" + "is a special sub-tier of Executive Platinum, reserved for the most");
    System.out.println("\t" + "loyal passengers. To save costs, airline  management decided to");
    System.out.println("\t" + "eliminate the position of co-pilot, instead opting to reserve");
    System.out.println("\t" + "the co-pilot’s seat for Super Executive Platinum passengers." + "\n");
  }
  public static String joinDate(String[] date, int[] memberID, int[] year, int length) {
    System.out.print("Enter in the memberID you wish to find the join date for: ");
    String creation = "";
    Scanner input = new Scanner(System.in);
    int ID = input.nextInt();
    for (int i = 0; i < length; ++i) {
      if (memberID[i] == ID) {
        System.out.println("Join Date: " + date[i]);
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
    System.out.print("Year: ");
    int time = input.nextInt();
    System.out.print("ID: ");
    int ID = input.nextInt();
    System.out.print("\n");
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
    System.out.println("Total traveled miles during this year was: " + totalMiles);
    System.out.println("Tier: " + tier + "\n");
    return tier;
  }
  public static String previousYear(String[] date, int[] memberID, int[] flightMiles, int[] year,
      int length) {
    String tier = "";
    int ID;
    int totalMiles = 0;
    int latestYear = 0;
    int previousYear = 0;
    System.out.print("Enter in the ID: ");
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
    System.out.println("Previous year tier: " + tier);
    return tier;
  }
  public static void main(String[] args) throws IOException {
    FileInputStream inputFile = null;
    Scanner scnr = null;
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
      System.out.print("\n");
      if (choice == 1) {
        displaySecond();
        System.out.print("Choose your desired query: ");
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
        } else {
          System.out.println("Not any of the valid choices, going back to home query");
        }
      } else if (choice == 3) { //This is the exit for first display
        System.exit(0);
      } else if (choice == 2) {
        whatAreRewardsMembers();
      } else {
        System.out.println("Not one of the valid choices, please choose again");
      }

      choice = 0;
    }

    scnr.close();
  }
}
