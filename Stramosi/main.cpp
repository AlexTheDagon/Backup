#include <iostream>
#include <fstream>
using namespace std;
ifstream in("stramosi.in");
ofstream out("stramosi.out");
int n,m,pre[20][250050],nod,t,l[250050];

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)in>>pre[0][i];
    for(int p=1;p<20;++p)
        for(int i=1;i<=n;++i)
            pre[p][i]=pre[p-1][pre[p-1][i]];
    ///bine
    while(m)
    {
        --m;
        in>>nod>>t;
        for(int i=20;i>=0;--i)
            if(t&(1<<i))nod=pre[i][nod];
        out<<nod<<'\n';
    }
    return 0;
}
/**
pre[i][j]=al 2^i lea stramos a lui j
pre[i][j]=pre[i-1][pre[i-1][j]];
Face reprezentarea binara
10011 fac saluti de 2^0,2^1 si 2^4
**/
