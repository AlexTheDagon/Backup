#include <iostream>
#include <fstream>
#include <vector>
#define NM 1005
#define pb push_back
using namespace std;
ifstream in("flori.in");
ofstream out("flori.out");
int n,k,vizf[NM],vizg[NM],floare,p[NM];
vector<int> flori[NM],fetita[NM];
int father(int nod)
{
    if(p[nod]==nod)return nod;
    return p[nod]=father(p[nod]);
}
void unire(int x,int y)
{
    p[father(x)]=father(y);
}
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        p[i]=i;
        for(int j=1;j<=k;++j)
        {
            in>>floare;
            flori[floare].pb(i);
            fetita[i].pb(floare);
        }
    }
    return 0;
}
