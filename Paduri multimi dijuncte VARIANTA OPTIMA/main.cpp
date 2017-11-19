#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("disjoint.in");
ofstream out("disjoint.out");
int n,m,a,b,c,p[NM];
int parinte(int nod)
{
    if(p[nod]==nod)return nod;
    return p[nod]=parinte(p[nod]);
}
void unire(int x,int y)
{
    p[parinte(x)]=parinte(y);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)p[i]=i;
    for(int i=1;i<=m;++i)
    {
        in>>c>>a>>b;
        if(c==1)unire(a,b);
        else
        {
            if(parinte(a)==parinte(b))out<<"DA"<<'\n';
            else out<<"NU"<<'\n';
        }
    }
    return 0;
}
