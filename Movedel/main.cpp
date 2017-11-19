#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("movedel.in");
ofstream out("movedel.out");
int n,m,poz[2005],ciur[200010],parc,ind,pozr;
vector <int> p;
int main()
{
    in>>n>>m;
    for(int i=1;i<=200000;++i)ciur[i]=1;
    for(int i=2;i<=200000;++i)
    {
        if(ciur[i]==1)
        {
            p.pb(i);
            for(int j=i+i;j<=200000;j+=i)ciur[j]=0;
        }
    }
    ind=1;
    pozr=n;
    for(int i=0;pozr;++i)
    {
        parc=p[i]%n;
        while(parc)
        {
            --parc;
            --ind;
            if(ind<1)ind=n;
        }
        if(poz[ind]==0)--pozr;
        if(!pozr)cout<<i;
        poz[ind]=1;
    }
    out<<"a";
    for(int i=2;i<=n;++i)out<<"b";
    out<<'\n';
    for(int i=1;i<=n;++i)
    {
        if(i==ind)out<<"a";
        else out<<"c";
    }
    return 0;
}
