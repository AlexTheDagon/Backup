#include <iostream>
#define NM 100005
using namespace std;
int a[NM],k,x,n,sol,c,d,st,fn;
int main()
{
    cin>>st>>fn;
    for(int i=1;i<=(fn-st+1);++i)
    {
        cin>>x;
        if(x!=a[k] || k==0)a[++k]=x;
    }
    sol=1;
    if(a[1]>a[2])d=1;
    else c=1;
    for(int i=3;i<=k;++i)
    {
        if((c==1 && a[i]<a[i-1])||(d==1 && a[i]>a[i-1]))
        {
            ++i;
            ++sol;
            if(a[i]<a[i-1])
            {
                d=1;
                c=0;
            }
            else
            {
                c=1;
                d=0;
            }
        }
    }
    cout<<sol;
    return 0;
}
