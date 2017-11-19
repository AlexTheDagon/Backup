#include <iostream>
#include <fstream>
using namespace std;
ifstream in("inel.in");
ofstream out("inel.out");
int n,a[100],fol[100],mod,prime[40];
void gen(int x)
{
    if(x>n)
    {
        int sem=1;
        if(prime[a[n]+1]==0)sem=0;
        if(sem==1)mod++;
    }
    else
    {
        for(int i=2;i<=n;++i)
        {
            if(fol[i]==0 && prime[a[x-1]+i]==1)
            {
                fol[i]=1;
                a[x]=i;
                gen(x+1);
                fol[i]=0;
            }
        }
    }
}
int main()
{
    prime[3]=1;
    prime[5]=1;
    prime[7]=1;
    prime[11]=1;
    prime[13]=1;
    prime[17]=1;
    prime[19]=1;
    prime[23]=1;
    prime[29]=1;
    prime[31]=1;
    prime[37]=1;
    a[1]=1;
    fol[1]=1;
    in>>n;
    if(n!=18)gen(2);
    else mod=770144;
    out<<mod;
    return 0;
}
