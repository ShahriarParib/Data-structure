#include <iostream>
#include <cstring>
using namespace std;
void reverseString(char* str)
{
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end)
    {
        swap(*start, *end);
        start++;
        end--;
    }
}
bool isPalindrome(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    char original[100];
    strcpy(original, str);
    cout << "Original string: " << str << endl;
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    if (isPalindrome(original))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
