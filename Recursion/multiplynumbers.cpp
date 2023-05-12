#include <iostream>

using namespace std;
int multiplyNumbers(int m, int n)
{
    // Write your code here
    int result;
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        result = m;
    }
    else
    {
        result = m + multiplyNumbers(m, n - 1);
    }
    return result;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
