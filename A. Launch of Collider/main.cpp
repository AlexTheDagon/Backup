#include <iostream>

using namespace std;
int n,t=1000000000,timp[200000],sem;
char a[200000];
int main()
{
    cin>>n;
    cin>>a;
    for(int i=0;i<n;++i)
    {
        cin>>timp[i];
    }
    for(int i=0;i<n-1;++i)
    {
        if(a[i]=='R' && a[i+1]=='L')t=min(t,(timp[i+1]-timp[i])/2);
    }
    if(t!=1000000000)cout<<t;
    else cout<<"-1";
    return 0;
}
