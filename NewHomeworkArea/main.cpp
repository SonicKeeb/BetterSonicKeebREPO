#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {

    string movie, location;
    double adultprice, childprice, profit, adult, child;

    profit = .20;
    adultprice= 11.75;
    childprice = 6.55;

    cout<< "Please enter the movie title: ";
    getline(cin, movie);
    cout<< "Movie title is "<< movie << endl;

    cout<< "Please enter the number if adult tickets sold: ";
    cin>> adult;
    cout<< "Number of adult tickets sold is "<< adult << endl;

    cout<< "Please enter the number if child tickets sold: ";
    cin>> child;
    cout<< "Number of child tickets sold is "<< child << endl;

    cout<< "Please enter the theater's location: ";
    cin.ignore();
    getline(cin,location);
    cout<< "Theater location is "<< location << endl;

    cout<< "Gross profit is "<< (adultpriceadult)+(childpricechild)<<endl;
    cout << "Net profit is " << (((adultpriceadult)+(childpricechild))profit)<<endl;
    cout << setprecision (2)<<"Distributor profit is " <<((adultpriceadult)+(childpricechild)- (((adultpriceadult)+(childpricechild))profit)) <<endl;



    return 0;
}
