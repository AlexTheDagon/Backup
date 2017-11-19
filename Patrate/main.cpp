#include <iostream>
#include <fstream>
#include <stdlib.h>
#define x first
#define y second
using namespace std;
ifstream in("patrate.in");
ofstream out("patrate.out");
pair<int,int> p[50005];
int n,l,imin=1<<20,jmin=1<<20,imax,jmax;
int dist(int x1,int y1,int x2,int y2)
{
    return max(abs(x1-x2),abs(y1-y2));
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>p[i].x>>p[i].y;
        imin=min(p[i].x,imin);
        jmin=min(p[i].y,jmin);
        imax=max(imax,p[i].x);
        jmax=max(p[i].y,jmax);
    }
    return 0;
}
