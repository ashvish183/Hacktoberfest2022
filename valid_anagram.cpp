#include <bits/stdc++.h>
using namespace std;
    bool isAnagram(string s, string t) {
        int i;
        map<char,int>mp1,mp2;
        for(i=0;i<s.length();i++)
            mp1[s[i]]++;
        for(i=0;i<t.length();i++)
            mp2[t[i]]++;
        for(auto i:mp1)
        {
            if(mp2.find(i.first)==mp2.end() || mp2.find(i.first)->second != i.second)
                return false;
        }
        for(auto i:mp2)
        {
            if(mp1.find(i.first)==mp1.end() || mp1.find(i.first)->second != i.second)
                return false;
        }
        return true;
    }
int main()
{
  string s,t;
  cin>>s>>t;
  if(isAnagram(s,t))
  cout<<"true";
  else
  cout<<"false";
}