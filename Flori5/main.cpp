#include <iostream>
#include <fstream>
using namespace std;
ifstream in("flori5.in");
ofstream out("flori5.out");
long long n,m,x,y,k,a[100001],c[100001],p[100001],pprim,cprim,copie;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        c[i]=c[i-1]+a[i]%k;
        p[i]=p[i-1]+a[i]/k;
    }
    in>>m;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y;
        if(x!=y)
        {
            pprim=p[y]-p[x-1];
            cprim=c[y]-c[x-1];
            copie=pprim;
            if(pprim>cprim)
            {
                pprim=pprim-((pprim-cprim)/(k+1));
                if((copie-cprim)%k!=0)pprim--;
            }
            out<<pprim<<'\n';
        }
        else out<<a[x]/(k+1)<<'\n';
    }
    return 0;
}
