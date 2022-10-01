#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int p[n],a,b,c,s;
	     s=0;
	    a[0]=0;
	    b[0]=0;
	    for(int i=1;i<=n;i++){
	        cin>>p[i];
	       }
	   for(int i=1;i<n;i++){
	        s=s+a[i];
	       b[i]=a[i];
	       a[i]=s;
	       c=a[i+1]-b[i];
	       if(c>0)
	            b[i+1]=b[i]+b[i+1]+c;
	       else
	            b[i+1]=b[i]+b[i+1];
	   }
	    cout<<b<<endl;
	}
	return 0;
}
