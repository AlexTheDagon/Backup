#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("lss.in");
ofstream out("lss.out");
int poz[100005],a[100005],p,k,sem,secv[100005],ind;
long long cost[100005];
int main()
{
    in>>k>>p;
    for(int i=1;i<=p;++i)in>>poz[i];
    sort(poz+1,poz+p+1);
    for(int i=1;i<=p;++i)
    {
        a[i]=poz[i]%k;
        if(a[i]==0)a[i]=k;
    }
    for(int i=1;i<=p;++i)
    {
        if(a[i]==1)
        {
            sem=1;
            secv[i]=1;
            ind=i;
        }
        else
        {
            if(a[i]==a[i-1]+1 && sem)
            {
                ++secv[ind];
            }
            else sem=0;
        }
    }
    for(int i=p;i>0;--i)
    {
        cost[i]=cost[i+1]+a[i]-(p-i-secv[i+1]);
    }
    out<<cost[1];
    return 0;
}
