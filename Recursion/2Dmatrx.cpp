#include <iostream>
using namespace std;
int main()
{
    int r1, c1, r2, c2, i, j, k, a[10][10], b[10][10], multi[10][10];
    cout << "enter rows amd column for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and column for second matrix: ";
    cin >> r2 >> c2;

    while (r1 != c2)
    {
        cout << " Matrices cannot be multiplied";
        cout << "enter new Matrices:  ";
        cout << "enter rows amd column for first matrix: ";
        cin >> r1 >> c1;
        cout << "Enter rows and column for second matrix: ";
        cin >> r2 >> c2;
    }
    cout << "Enter element of matix 1: " << endl;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter element of matix 2: " << endl;
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            cin >> b[i][j];
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            multi[i][j] = 0;
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                multi[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << endl
         << "output matrix:" << endl;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            cout << multi[i][j] << " ";
            if (j == c2 - 1)
            {
                cout << endl;
            }
        }
    }
    return 0;
}