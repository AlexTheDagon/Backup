#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("cutit.in");
ofstream out("cutit.out");
vector <int> l;
int leg[85][85],nrleg,nrnod,ultnod=1,k,legcur;
int main()
{
    in>>k;
    while(k)
    {
        legcur=0;
        l.clear();
        l.pb(1);
        while(2*legcur+1<=k)
        {
            ++nrnod;
            ++ultnod;
            for(auto i:l)
            {
                ++nrleg;
                leg[i][ultnod]=1;
            }
            l.pb(ultnod);
            legcur=legcur*2+1;
        }
        k-=legcur;
    }
    out<<nrnod+1<<" "<<nrleg<<'\n';
    for(int i=1;i<=80;++i)
    {
        for(int j=1;j<=80;++j)
        {
            if(leg[i][j])out<<i<<" "<<j<<'\n';
        }
    }
    return 0;
}
