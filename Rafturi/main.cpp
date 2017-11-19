#include <iostream>
#include <fstream>
#define NM 10005
using namespace std;
ifstream in("rafturi.in");
ofstream out("rafturi.out");
int n,h[NM],c[NM],a,b,d;
int main()
{
    in>>d>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b;
        c[a]=max(c[a],b);
    }
    h[0]=0;
    h[1]=c[1];
    h[2]=max(c[2],c[1]);
    for(int i=3;i<=d;++i)
    {
        h[i]=max(c[i],c[i-1])+h[i-2];
        h[i]=min(h[i],c[i]+h[i-1]);
        h[i]=min(h[i],max(max(c[i-2],c[i-1]),c[i])+h[i-3]);
    }
    out<<h[d];
    return 0;
}
