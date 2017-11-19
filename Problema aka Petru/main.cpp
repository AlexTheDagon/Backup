#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,x,a[10005],dr,st,mid,l1,l2,sem;
int main()
{
    in>>x>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    st=0;
    dr=n+1;
    while(dr-st>1)
    {
        mid=(dr+st)/2;
        if(a[mid]>=x)dr=mid;
        else st=mid;
    }
    l1=dr;
    st=0;
    dr=n+1;
    while(dr-st>1)
    {
        mid=(dr+st)/2;
        if(a[mid]<=x)st=mid;
        else dr=mid;
    }
    l2=dr-1;
    if(a[l1]!=x)out<<"-1"<<'\n';
    else out<<l1<<" "<<l2<<'\n';
    return 0;
}
