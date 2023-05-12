#include <iostream>
using namespace std;
#include "StackUsingLL.cpp"

int main()
{
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    cout << s1.getsize() << endl;
    cout << s1.isEmpty() << endl;
}