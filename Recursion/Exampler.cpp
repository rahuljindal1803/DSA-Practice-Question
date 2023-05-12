#include <iostream>
using namespace std;
int main()
{
    char c;
    int rollno, phy, chem, maths, english, cs, total;
    cout << "Enter thwe name of the student: ";
    c = cin.get();
    while (c != '\n')
    {
        c = cin.get();
    }
    cout << "Enter the roll number: ";
    cin >> rollno;

    cout << '\t' << "ACADEMIC PERFORMANCE";
    cout << c << endl;
}