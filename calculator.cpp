#include <iostream>
using namespace std;
int main ()
{
    char a;
    int b, c;
    cout<<"Enter the operation"<<endl;
    cin>>a;
    cout<<"Enter the no.s"<<endl;
    cin>>b>>c;
    if (a=='+')
    {
        cout<<b+c;
    }
    else if (a=='-')
    {
        cout<<b-c;
    }
    else if (a=='*')
    {
        cout<<b*c;
    }
    else if (a=='/')
    {
        cout<<b/c;
    }
    else if (a!='+' && a!='-' && a!='*' && a!='/')
    { 
        cout<<"Invalid Operator";
    }
    return 0;
}
