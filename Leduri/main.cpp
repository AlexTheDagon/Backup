#include <iostream>
#include <fstream>
using namespace std;
ifstream in("leduri.in");
ofstream out("leduri.out");
int n,l[100005],model[100005],mod,a[100005];
int led();
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>l[i];
    }
    for(int i=1;i<=n;++i)in>>model[i];
    mod=led();
    l[1]=1-l[1];
    l[2]=1-l[2];
    mod=min(mod,led()+1);
    out<<mod;
    return 0;
}
int led()
{
    int c=0;
    for(int i=1;i<=n;++i)a[i]=l[i];
    for(int i=1;i<=n;++i)
    {
        if(model[i]!=a[i])
        {
            a[i]=model[i];
            a[i+1]=1-a[i+1];
            a[i+2]=1-a[i+2];
            ++c;
            if(i==n)return 1<<30;
        }
    }
    return c;
}
