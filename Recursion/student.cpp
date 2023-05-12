#include <iostream>
using namespace std;
class student
{
public:
    int rollnumber;

private:
    int age;

public:
    void display()
    {
        cout << age << " " << rollnumber << endl;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int a, int password)
    {
        if (password != 123)
        {
            return;
        }
        if (a < 0)
        {
            return;
        }
        age = a;
    }
};