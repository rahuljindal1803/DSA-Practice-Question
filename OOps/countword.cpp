#include <iostream>
using namespace std;
//count words in a given string
int total_words(char *str)
{
    int count = 0;
    int temp = 0;
    while (*str)
    {
        if (*str == ' ' || *str == '\n' || *str == '\t')
        {
            temp = 0;
        }
        else if (temp == 0)
        {
            temp = 1;
            count++;
        }
        ++str;
    }
    return count;
}
int main()
{
    char str[] = "acd   fsdf    efgfdg";
    cout << "Count of words in a string are: " << total_words(str);
    return 0;
}