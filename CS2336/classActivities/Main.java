/******************************************************************************

  Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
  C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
  Code, Compile, Run and Debug online from anywhere in world.

 *******************************************************************************/
public class Main
{
  public static void main(String[] args) {
    String[] exampleStrArr = {"This", "for", "loop", "uses", "syntactic", "sugar"};

    // also called a "for" each loop
    for(String strInArr: exampleStrArr) {
      System.out.print(strInArr + " ");
    }

    System.out.println();


    for(char letter: "word".toCharArray()) {
      System.out.println(letter);

      if (letter == 'r') {
        break;
      }
    }

    return;
  }
}

