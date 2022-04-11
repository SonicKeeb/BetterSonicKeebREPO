/*
   --Today
   --More about classes(Static data members and friend functions
   --A friend function of a class is defined outside the class scope and it has the right to access
   all pricate or protected data members of the class.
   --Even though the prototype is part of the class definition, a friend function is not a member
   function

   class point {
   int x,y;
   public:
   friend void show(point &);
   int getx() {
   return x;
   };

   point p1;
   p1.getx(); // getX is a member function of the class point 
   p1.show(); <-- WRONG

   void show(point &o) {
   cout << o.x << "\t" << o.y << endl;
   cout << o.getx() << "\t" << o.gety() << endl;
   }

// Because display is not friend functoin of class point
// to access any data member (private or protected)
// it needs to use the accessor
void display(point &o) {
cout << o.getx() << "\t" << o.gety() << endl;
}

-- Static data members: are allocated once, and accesible to all the objects that 
belong to the same class
-- TO initialize a static data member:
a) use the following syntax outside the class scope:
<data_type><calss_it_belongs_to>::<static_data_member_name> = <initial>;
b) if no intializatoin is provided, the system/ compiler
will set it to 0 if nnumberic, '\0' if alopa or nullptr

To access static data members:
a) use the class prefix from friend functions or 
b) use a static function: these functions can only access static data members
static data members
this is: static functions can access static data mambers only

Static functions and data members exist(can be accessed) even if 
ther is no object of the class defined

Example:
Write a program to:
Define a class studentInfo with the following data members
a) id; an integer >0
b) gpa: a float [0,4];
c) name: a variable size c stirng (char *)
d) counter: static int data member
e) show: a friend function to cout the object' state
f) a static function to access teh counter
g) display: a non-function to replicate show()
The any constructor intializes teh name to nullptr, and increase
the counter by one.
The destructur releases the memeory assigned to name(if any)
and decreases the counter by one.
1) implement inline
2) ICA-4-11-2033 due 4/12 by noon.
---Re organize the code written in class, now in .h and .cpp file. Read teh data from an input file, and sort by id before diplaying the data

 */

class studentInfo {
  private:
  int id;
  float gpa;
  char * name;
  public:
  int getId() const { return id; }
  float getGPA() const { return gpa; }
  char * getName() const { return name; }

  bool setId(int i ) {
    if (i <= 0) 
      return false;
    id = i;
    return true;
  }
  bool setGPA(float g) {
    if (g < 0 || g > 4)
      return false;
    gpa = g;
    return true;
  }
  void setName(const char * s) {
    if (name != nullptr) 
      delete[] name;
    int i = 0;
    while (s[i++] != '\0');
    name = new char[i];
    while (i >= 0) {
      name[i--] = s[i];
    }
  }

  static int getCounter() { return counter; }
  studentInfo() {
    name = nullptr;
    counter++;
  }
  studentInfo(int i, float g, const char * s) {
    setId(i);
    setGPA(g);
    name = nullptr;
    setName(s);
    counter++
  }
  ~studentInfo() {
    if (name != nullptr)
      delete[] name;
    counter--;
  }
};


//if we want to intialize the static data maber:
// a) we will use
int studentInfo::counter = 0;
//b) if no initializatoin is providedm the system 
// will initialize it(with the first object)

void diplay(studentInfo &o) {
  cout << setw(5) << studentInfo::counter << "\t" 
    << setw(10) << o.id << "\t" << setw(5) << fixed << setprecision(1) << o.gpa << "\t" <<
    setw(30) << o.name << endl;
}

void show(studentInfo &o) {
  cout << setw(5) << o.getCounter()  << "\t" 
    << setw(10) << o.getId() << "\t" << setw(5) << fixed << setprecision(1) << o.getGPA() << "\t" <<
    setw(30) << o.getName() << endl;
}

#include <iostream>
  using namespace std;

  int main() {
    tudentInfo * allStudents = new studentInfo[3];
    allStudents[0].setId(100);
    allStudents[0].setGpa(4.0);
    allStudents[0].setName("Homer Simpson");

    allStudents[1].setId(101);
    allStudents[1].setGpa(2.0);
    allStudents[1].setName("Karl Lewis");

    allStudents[2].setId(102);
    allStudents[2].setGpa(3.2);
    allStudents[2].setName("Johnny the sex god");
    for (int i = 0; i < 3; i++) {
      display(allstudents[i]);
      show(allStudents[i]);
    }
    return 0;  
  }
