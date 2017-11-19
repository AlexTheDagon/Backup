#include <iostream>
#define NM 100
using namespace std;
int a[NM],b[NM],i,j,n,sem,sem2,k;
int f(int c,int b)
{
    if(c<=b && sem2==1)
    {
        if(a[i]!=a[j])sem=1;
        else sem2=0;
        f(c+1,b-1);
    }
    return sem;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>i>>j;
    if(f(i,j)==0)cout<<"Da";
    else cout<<"Nu";
    return 0;
}
