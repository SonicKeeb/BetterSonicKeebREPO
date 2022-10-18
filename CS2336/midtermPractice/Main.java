import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;

/*
   Given four values representing counts of quarters, dimes, nickels and pennies, output the total amount as dollars and cents.

   Output each floating-point value with two digits after the decimal point, which can be achieved as follows:
   System.out.printf("Amount: $%.2f\n", dollars);

Ex: If the input is:

4 3 2 1
where 4 is the number of quarters, 3 is the number of dimes, 2 is the number of nickels, and 1 is the number of pennies, the output is:

Amount: $1.41
For simplicity, assume input is non-negative.
 */

public class LabProgram {
  public static void main(String[] args) throws IOException {

    int input;
    int[] inputValue = new int[4];
    double[] centValue = new double[4];

    Scanner scnr = new Scanner(System.in);

    System.out.println("Input 4 values spaced out");
    for (int i = 0; i < 4; i++) {
      inputValue[i] = scnr.nextInt();
    }

    double cents = 0.00;

    for (int i = 0; i < 4; i++) {
      if (i == 0) {
        centValue[i] = inputValue[i] * 0.25;
      } else if (i == 1) {
        centValue[i] = inputValue[i] * 0.10;
      } else if (i == 2) {
        centValue[i] = inputValue[i] * 0.05;
      } else if (i == 3) {
        centValue[i] = inputValue[i] * 0.01;
      }
    }

    for (int i = 0; i < 4; i++) {
      cents += centValue[i];
    }
    System.out.printf("Amount: $%.2f\n", cents);
  }
}
