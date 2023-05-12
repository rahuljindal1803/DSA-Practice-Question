#include <iostream>
#include <string>

using namespace std;
int keypad(int num, string output[], string option[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int lastnumber = num % 10;
    int smallnumber = num / 10;
    string smalloutput[1000];
    int smallcount = keypad(smallnumber, smalloutput, option);
    string temp = option[lastnumber];

    int k = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < smallcount; j++)
        {
            output[k] = smalloutput[j] + temp[i];
            k++;
        }
    }
    return k;
}
int keypad(int num, string output[])
{
    string option[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypad(num, output, option);
}
int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
