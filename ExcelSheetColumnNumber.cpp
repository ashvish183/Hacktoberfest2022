//QUESTION- Convert column title in excel to respective column number.

#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
        int ans=0;
        int p=0;
        int len=columnTitle.length();

        for(int i=len-1; i>=0; i--)
        {
            char x= columnTitle[i];
            int y= (int)(pow(26,p))*(x-64); //A=65
            ans+=y;
            p++;

        } 

        return ans;
    }

int main()
{
    string s;
    cin>> s;

    cout<<titleToNumber(s);
}