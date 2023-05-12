#include <iostream>
using namespace std;
#include "pair2.cpp"

int main()
{ /*
     pairs<int, pairs<int, int>> p1;
     p1.setX(10);
     pairs<int, int> p2;
     p2.setX(20);
     p2.setY(30);

     p1.setY(p2);

     cout << p1.getX() << " " << p1.getY().getX() << " " << p1.getY().getY() << endl;
 */
    pairs<pairs<int, int>, int> p2;
    p2.setY(10);
    pairs<int, int> p4;
    p4.setX(5);
    p4.setY(16);
    p2.setX(p4);

    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;
}