#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        int a[10];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ;
        }
        int key;
        cin >> key;
        int i;
        for (i = 0; i < n; i++)
        {
            if (key == a[i])
            {
                cout << "Found key at Index :" << i << endl;
                break;
            }
        }
        if (i == n)
        {
            cout << "the " << key << " not found";
        }
    }
    return 0;
}