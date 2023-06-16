// 11 // Round the given number to nearset multiple of 10.              // AWESOME
#include<iostream>
using namespace std;
int main()
{
    string str;
    cout << "\nEnter a number :  ";
    cin >> str;

    int x = stoi(str);          // Convert Numeric String to Integer
    while(1)
    {
        if(x % 10 > 5)
        {
            x = (x / 10) * 10;
            cout << endl << x + 10 << endl;
            break;
        }
        else if(x % 10 <= 5 && x > 0)
        {
            // x = (x / 10) * 10;
            // cout << endl << x << endl;
            cout << endl << (x / 10) * 10 << endl;
            break;
        }
    }
}