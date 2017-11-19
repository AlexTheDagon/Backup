#include <iostream>
#include <fstream>
#include <map>
#define NM 100005
using namespace std;
ifstream in("taietura.in");
ofstream out("taietura.out");
map<long long,int> m;
int n,sp[NM],rez[NM],poz[NM];
int main()
{
    in>>n;
    m[0]=1;
    poz[0]=1;
    for(int i=1;i<=n;++i)
    {
        in>>sp[i];
        sp[i]+=sp[i-1];
        if(m.find(sp[i])!=m.end())++m[sp[i]];
        else m[sp[i]]=1;
        poz[i]=m[sp[i]];
    }
    for(int i=0;i<=n;++i)
    {
        rez[i+1]-=(poz[i]-1);
        rez[i+1]+=m[sp[i]]-poz[i];
    }
    for(int i=1;i<=n;++i)
    {
        rez[i]+=rez[i-1];
        out<<rez[i]<<" ";
    }
    return 0;
}
