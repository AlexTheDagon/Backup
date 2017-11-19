#include <iostream>
#include <algorithm>
using namespace std;
int n,k,a[101],l,sol,x,y;
char p[100],pass[100];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>p;
        for(l=0;p[l]!=(char)0;++l);
        a[i]=l;
    }
    cin>>pass;
    for(l=0;pass[l]!=(char)0;++l);
    sol=l;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)///verif
    {
        if(a[i]<sol)++x;
        if(a[i]<=sol)++y;
    }
    x=x/k*(k+5)+x%k;
    ++x;
    --y;
    y=y/k*(k+5)+y%k;
    ++y;
    cout<<x<<" "<<y;
    return 0;
}
