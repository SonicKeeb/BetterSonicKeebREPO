#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
  //declaring and initializing required variables
  int total_nucleotides=0,Adenine=0,Thymine=0,Cytosine=0,Guanine=0;
  char c ='x';
  //declaring input stream object
  ifstream in;
  //opening file in input stream
  in.open("dnaSequence.txt");
  //if file is not open
  if(!in)
  {
    //prin error message and quit program
    cout<<"Error: in opening input file\n";
    exit(0);
  }
  //reading file character by character until no character is remain unread
  while(in>>c)
  {
    //switch case for checking character read 
    switch(c)
    {
      //if character is A increase  Adenine and Total count
      case 'A':
        Adenine++;
        total_nucleotides++;
        break;
      case 'T'://if character is T increase  Thymine and Total count
        Thymine++;
        total_nucleotides++;
        break;
      case 'C':
        Cytosine++;//if character is C increase  Cytosine and Total count
        total_nucleotides++;
        break;
      case 'G': //if character is G increase  Guanine and Total count
        Guanine++;
        total_nucleotides++;
        break;
      default: //if other character is found print error message
        cout<<"Error: "<<c<<" is not a valid character\n";
    }
  }
  //close file after read is over
  in.close();
  //printing result on console
  cout<<"DNA sequence analysis:\n";
  cout<<total_nucleotides<<" nucleotides in the sequence\n";
  cout<<"\nSequence breakdown:\n";
  //setw() is for formatting output in correct order
  cout<<setw(15)<<left<<"Adenine: "<<setw(10)<<left<<Adenine<<((float)Adenine/total_nucleotides)*100<<"%\n";
  cout<<setw(15)<<left<<"Thymine: "<<setw(10)<<left<<Thymine<<((float)Thymine/total_nucleotides)*100<<"%\n";
  cout<<setw(15)<<left<<"Cytosine: "<<setw(10)<<left<<Cytosine<<((float)Cytosine/total_nucleotides)*100<<"%\n";
  cout<<setw(15)<<left<<"Guanine: "<<setw(10)<<left<<Guanine<<((float)Guanine/total_nucleotides)*100<<"%\n";
  //declaring object of output stream
  ofstream out;
  //opening output file in output stream
  out.open("output.txt");
  //if file is not open
  if(!out)
  {
    //print error message and quit program
    cout<<"Error in opening output file\n";
    exit(0);
  }
  //printing result in output file
  out<<"DNA sequence analysis:\n";
  out<<total_nucleotides<<" nucleotides in the sequence\n";
  out<<"\nSequence breakdown:\n";
  out<<setw(15)<<left<<"Adenine: "<<setw(10)<<left<<Adenine<<((float)Adenine/total_nucleotides)*100<<"%\n";
  out<<setw(15)<<left<<"Thymine: "<<setw(10)<<left<<Thymine<<((float)Thymine/total_nucleotides)*100<<"%\n";
  out<<setw(15)<<left<<"Cytosine: "<<setw(10)<<left<<Cytosine<<((float)Cytosine/total_nucleotides)*100<<"%\n";
  out<<setw(15)<<left<<"Guanine: "<<setw(10)<<left<<Guanine<<((float)Guanine/total_nucleotides)*100<<"%\n";
  out.close(); //closing file

  return 0;
}
