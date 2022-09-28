import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;

public class Flight {
  private String date;
  private int memberID;
  private int flightMiles;
  private int year;

  public String getDate() {
    return date;
  }

  public void setDate(String str) {
    date = str;
  }
  
  public int getMemberID() {
    return memberID;
  }

  public void setMemberID(int integer) {
    memberID = integer;
  }

  public int getFlightMiles() {
    return flightMiles;
  }

  public void setFlightMiles(int integer) {
    flightMiles = integer;
  }

  public int getYear() {
    return year;
  }

  public void setYear(int integer) {
    year = integer;
  }

}

//Flight[] flights = new Flight[length]

//Flight[i].setDate(scnr.next())

//Flight[i].getDate();
