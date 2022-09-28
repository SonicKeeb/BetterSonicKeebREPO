/**
* @author Hamilton Ngo
*/
// Importing all of the prebuilt classes and methods
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;

/**
  * This program takes in an input file and calculates a user id's total traveled miles and
  * each members reward tiers 
  */
 
public class Main {
   /**
    * This function outputs/prints the beginning query options when it is called
    */
public static void displayFirst() { // Everything in this function is just a string output and newlines
    System.out.println("Welcome to the flight members status terminal! \n");
    System.out.println("Choose your choice of query" + "\n");
    System.out.println("1. Query information through rewards members");
    System.out.println("2. What are the reward tiers?");
    System.out.println("3. Quit");
    System.out.println("\n" + "What is your choice?");
    System.out.print("Choice: ");
  }
  /**
    * This function ouputs/prints the secondary query options after choice number "1." is called
    * which displays the next set of queries the user can use
    */
public static void displaySecond() { // Everything in this function is just a string output and newlines
    System.out.println("Selected option 1: Query information through rewards members");
    System.out.println("\n" + "1. Miles accumulated in the current year");
    System.out.println("2. Total miles accumulated since joining the rewards program");
    System.out.println("3. Join date of the rewards program");
    System.out.println("4. Current reward tier(based on miles accumluated from the previous year");
    System.out.println("5. Reward tier of GIVEN prior year");
    System.out.println("6. EXIT");
    System.out.println("*. Press any other number to go back to previous page");
  }
  /**
    * This function takes in 4 different arrays,
    * A string array date, and 3 ints, memberID, flightMiles, year, length
    * The final parameter is a int variable called accumulated
    * The function only calculates the most recent year of travels because it is the current year
    * @param date the string date of the input file
    * @param memberID the id of users in the input file
    * @param flightMiles the distance per flight that a specific memberID flew on that day
    * @param year the first 4 numbers of date which signifies the year
    * @param length the length / amount of lines in the file
    * @param accumulated total amount of miles traveled given the memberID and current year
    * @return accumulated
    */
public static int milesAccumulatedCurrent(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length, int accumulated) {
    int currentYear = year[length-1]; // declare & intialize current year as the last element in file
    accumulated = 0; // initializing variable to be 0, as we will sumnation it later
    System.out.println("\n"); // Newline for formatting
    System.out.print("Input ID to find accumulated miles for current year: "); // Prompt
    Scanner input = new Scanner(System.in); // Creation of a new scanner input
    int ID = input.nextInt(); // declaring and intializing ID as the next integer input
    for (int i = 0; i < length; ++i) { // For loop runs from 0 to length of file
      if ((year[i] == currentYear) && (memberID[i] == ID)) { // if the elements at i are the ones 
        accumulated += flightMiles[i];                       // we are looking for, then sumnation
      }
    }
    System.out.print("\n"); // Newline for formatting
    System.out.println("Miles Accumulated this year: " + accumulated + "\n"); // Output statement
    return accumulated; 
  }/**
  * This function, like the one above, has the same parameter structure
  * This function calculates the total amount of miles a member traveled since their joining
  * @param date the string date of the input file
  * @param memberID the id of users in the input file
  * @param flightMiles the distance per flight that a specific memberID flew on that day
  * @param year the first 4 numbers of date which signifies the year
  * @param length the length / amount of lines in the file
  * @param overall the overall /  total amount of miles traveled since the member joined
  * @return overall
  */
  public static int totalMilesAccumulated(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length, int overall) {
    overall = 0; // Initializing overall to be 0 because we will sumnation later
    System.out.print("Input Member ID for the total miles since joining the members program: ");
    // Line above ^ is for prompting the user's input
    Scanner input = new Scanner(System.in); // creation of new scanner input
    int ID = input.nextInt(); // initializing ID as the input of the next integer
    for (int i = 0; i < length; ++i) { // for loop runs from 0 to length of file
      if (memberID[i] == ID) { // so long as the ID at i is the same as the inputted id
        overall += flightMiles[i]; // sumnation
      }
    }
    System.out.println("\n"); // Newline for formatting
    System.out.println("Total Miles Since Joining: " + overall + "\n"); //output statement with overall
    return overall; 
  }
  /**
  * This function works just like the display functions at the beginning of the program
  * It is used just to output information about each reward members tiers and what they entail
  */
  public static void whatAreRewardsMembers() { // Function is just output strings of info about tiers
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
  /**
  * This function works similarly to the miles calculation functions
  * in that it has the same parameters, it works in a much more simple manner however
  * in that the only thing it does, since the input file is given to us sorted, the first
  * instance of when a memberID appears, we take the same index for the date and parse it to 
  * get the year.
  * @param date the string date of the input file
  * @param memberID the id of users in the input file
  * @param year the first 4 numbers of date which signifies the year
  * @param length the length / amount of lines in the file
  * @return creation
  */
  public static String joinDate(String[] date, int[] memberID, int[] year, int length) {
    System.out.print("Enter in the memberID you wish to find the join date for: "); // Prompt
    String creation = ""; // Initialized Helper string that is empty so we can change it later
    Scanner input = new Scanner(System.in); // creation of new scanner input
    int ID = input.nextInt(); // declration and initialization of ID which is the next integer input
    for (int i = 0; i < length; ++i) { // For loop runs from 0 to end of file
      if (memberID[i] == ID) { // if the ID at i is the same as the inputted ID
        System.out.println("Join Date: " + date[i]); // then output the date string at that index
        creation += date[i]; //saving that specific date in creation
        break; // one we found the date, we don't have to loop anymore so break out of loop
      }
    }
    return creation;
  }
  /**
  * This function works by finding what tier a member belongs to given the current year
  * The current year is the most recent year given to us by the input file
  * @param date the string date of the input file
  * @param memberID the id of users in the input file
  * @param flightMiles the distance per flight that a specific memberID flew on that day
  * @param year the first 4 numbers of date which signifies the year
  * @param length the length / amount of lines in the file
  * @return tier
  */
  public static String currentTier(String[] date, int[] memberID, int[] flightMiles,
      int[] year, int length) {
    String tier = ""; // Declaration and intialization of empty string tier to store tier
    int totalMiles = 0; // Declaration and intializatoin of total to be 0 because we will sumnation it
    System.out.println("Enter in the year and then the ID to find the tier belonging to that year");
    // Line above ^ will output a prompt statement for the following inputs
    Scanner input = new Scanner(System.in); // creatin of new scanner input
    System.out.print("Year: "); // prompt to input year
    int time = input.nextInt(); // declaring and intializing time to be the next date input
    System.out.print("ID: "); // prompt ID input
    int ID = input.nextInt(); // declaring and intializing ID as the next ID int input
    System.out.print("\n"); // newline for formatting
    for (int i = 0; i < length; ++i) { // For loop starts from 0 to end of file
      if ((year[i] == time) && (memberID[i] == ID)) { // if the year and ID are the same as the inputs
        totalMiles += flightMiles[i]; // then sumnation the totalmiles from the flightMiles array same i
      }
      if ((totalMiles >= 25000) && (totalMiles < 50000)) { // if the total miles fit the below criteria
        tier = "Gold";                                     // Then these are the tiers it belongs to
      } else if ((totalMiles >= 500000) && (totalMiles < 75000)) {
        tier = "Platinum";
      } else if ((totalMiles >= 75000) && (totalMiles < 100000)) {
        tier = "Executive Platinum";
      } else if (totalMiles >= 150000) {
        tier = "Super Executive Platinum";
      } else {
        tier = "Not enough for any tier"; // if not high enough for any tier, then output this
      }
    }
    System.out.println("Total traveled miles during this year was: " + totalMiles); //output statement
    System.out.println("Tier: " + tier + "\n"); // outputting the actual tier string with newline
    return tier;
  }
  /**
  * This function works very similar to the one right above it, with the exception that 
  * instead of calculating the total miles per the memberID of the current year, it finds the
  * total miles accumulated of a memberID based on the users choice of the year.
  * @param date the string date of the input file
  * @param memberID the id of users in the input file
  * @param flightMiles the distance per flight that a specific memberID flew on that day
  * @param year the first 4 numbers of date which signifies the year
  * @param length the length / amount of lines in the file
  * @return tier
  */
  public static String previousYear(String[] date, int[] memberID, int[] flightMiles, int[] year,
      int length) {
    String tier = ""; //declaring and initializing tier as empty string just like above function
    int ID; // delcaring ID
    int totalMiles = 0; // Declaring totalMiles and intializing it to 0 because we will sumnation
    int latestYear = 0; // Declaring latestYear and intializing it to 0 because we will change value
    int previousYear = 0; // Declaring previousYear and initializing it becuase we will change vlue
    System.out.print("Enter in the ID: "); // Prompt statement for input
    Scanner input = new Scanner(System.in); // creation of new scanner input
    ID = input.nextInt(); // initializing ID as input of the next integer
    for (int i = length-1; i > 0; --i) { // for loop runs from last index to 0(end of file to beginning)
      latestYear = year[i]; // latestYear is the current year, which is the most recent year(eof)
      previousYear = year[i-1]; // previousYear is year right behind the latestyear in file
      if (previousYear != latestYear) { // the moment previousyear is different, thats how we know its
        break; // once we know the year, break loop                          // the previous year
      }
    }
    for (int i = 0; i < length; ++i) { // for loop runs from 0 to end of file
      if ((year[i] == previousYear) && (memberID[i] == ID)) { // if the year at i is the same as the
        totalMiles += flightMiles[i];                         // previous year and ID is the same
      }                                                       // as the input, sumnation totalMiles
      if ((totalMiles >= 25000) && (totalMiles < 50000)) { // Same tier making as the previous function
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
    System.out.println("Previous year tier: " + tier); //output of tier
    return tier;
  }
  /**
  * This is the main function, it includes all the intialization of some pass
  * by reference parameters that are required for the functions above
  * @param args standard String[] args parameter for main functions
  * @throws IOException for input file exceptions when we scan them through
  */
  public static void main(String[] args) throws IOException { // Creation of the main function
    FileInputStream inputFile = null; // creating a fileinputstream for the inputfile and settingto null
    Scanner scnr = null; // initialize scanner to null
    inputFile = new FileInputStream("input.txt"); // initializing inputFile to be input.txt & open file
    scnr = new Scanner(inputFile); // scnr is new variable for scanning

    int counter = 0; // declaration and intialization of counter as 0 to find length of file
    int accumulated = 0; // creating and setting accumulated to 0 to find the total miles traveled
    int overall = 0; // overall is teh same for accumulated but for a different function

    while (scnr.hasNextLine()) { // while loop used for finding length of file
      counter = counter + 1; // if there is a new line, add 1 to counter
      scnr.nextLine(); // go to the next line, that way no infinite loop
    }
    scnr.close(); //close file

    // Because we are at the end of the file, we need to create the scanner again to start over

    inputFile = new FileInputStream("input.txt"); // ---\
    scnr = new Scanner(inputFile);                // ----> Starting at the beginning of the file again
    int length = counter;                         // ---/

    // Line 262 ^ create and set length to be the value of counter

    String[] date = new String[length]; // Creation of date string array with the size of length
    int[] memberID = new int[length]; // Creation of memberID Int array with size of length
    int[] flightMiles = new int[length]; // Creation of flightMiles Int array with size of length
    int[] year = new int[length]; // Creation of year Int array with size of length

    for (int i = 0; i < length; ++i) { // For loop runs from 0 to end of file
      date[i] = scnr.next(); // First input is into the date array
      memberID[i] = scnr.nextInt(); // second input is into the memberID array
      flightMiles[i] = scnr.nextInt(); // 3rd input is into the flightMiles array
      year[i] = Integer.parseInt(date[i].substring(0,4)); // the year array is the year substring 
    }                                                     // part of every element of date at i

    Scanner myChoice = new Scanner(System.in); // creating a new scanner for user inputs
    int choice = 0; // setting choice to 0 so that way the program keeps querying with the while loop
    while (choice == 0) {
      displayFirst(); // calls display function 1
      choice = myChoice.nextInt(); // setting choice to be the next integer input used for user query
      System.out.print("\n"); // new line for formatting
      if (choice == 1) { // if the user chooses option "1."
        displaySecond(); // call display function 2
        System.out.print("Choose your desired query: "); // prompt for next desired query
        choice = myChoice.nextInt(); // send another input out
        if (choice == 1) { // if they choose option 1, we call milesAccumulatedCurrent
          milesAccumulatedCurrent(date, memberID, flightMiles, year, length, accumulated);
        } else if (choice == 2) { // if user chooses 2, call totalMilesAccumulated
          totalMilesAccumulated(date, memberID, flightMiles, year, length, overall);
        } else if (choice == 3) { // if user chooses 3, call joinDate
          joinDate(date, memberID, year, length);
        } else if (choice == 4) { // if user chooses 4, call previousYear
          previousYear(date, memberID, flightMiles, year, length);
        } else if (choice == 5) { // if user chooses 5, call currentTier
          currentTier(date, memberID, flightMiles, year, length);
        } else if (choice == 6) { //This is the exit for after selecting query by id
          System.exit(1);
        } else { // if they select an invalid choice, prompt this message and query again
          System.out.println("Not any of the valid choices, going back to home query");
        }
      } else if (choice == 3) { //This is the exit for first display
        System.exit(0);
      } else if (choice == 2) { // if user chooses option 2 on beginning query,
        whatAreRewardsMembers(); // call whatAreRewardMembers
      } else {
        System.out.println("Not one of the valid choices, please choose again");
      } // in case user chooses wrong input

      choice = 0; // st choice to 0 to stop loop
    }

    scnr.close(); // close file
  }
}
