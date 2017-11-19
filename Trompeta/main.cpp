#include <iostream>
#include <fstream>
using namespace std;
ifstream in("trompeta.in");
ofstream out("trompeta.out");
int a[1000001];
char x;
int n,m,cm,pmax,maxx;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>x;
        a[i]=x-'0';
    }
    cm=m;
    while(cm)
    {
        maxx=0;
        for(int i=pmax+1;i<=(n-cm+1);++i)
        {
            if(a[i]>maxx)
            {
                maxx=a[i];
                pmax=i;
            }
        }
        out<<maxx;
        --cm;
    }
    return 0;
}
