#include <iostream>
using namespace std;
#include "student.cpp"
int main()
{
    student s1;
    student s2;
    student *s3 = new student;
    //s1.age = 24;
    s1.rollnumber = 21;

    //s2.age = 23;
    s2.rollnumber = 22;
    //(*s3).age = 24;
    // cout << s1.getAge() << endl;
    //s3->rollnumber = 23;
    //cout << s1.age << endl;
    //cout << s2.rollnumber << endl;
    //cout << (*s3).age << endl;
    //cout << s3->rollnumber << endl;

    s1.setAge(20, 123);
    s2.setAge(24, 123);

    s1.display();
    s2.display();
}
