// Program to check if a string balanced parenthesis or not

#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else
        {
            if (st.empty() || st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
    }

    if (!st.empty())
    {
        return false;
    }

    return true;
}

// driver function

int main()
{
    string s = "(()(())";

    cout << isBalanced(s);

    return 0;
}