#include <iostream>
#define inf (1<<30)
using namespace std;
long long dmin[10005];
long long dist[10005],d;
long long l1,l2,l3,c1,c2,c3,st,fin,n;
int main()
{
    cin>>l1>>l2>>l3>>c1>>c2>>c3;
    cin>>n>>st>>fin;
    if(st>fin)swap(fin,st);
    for(int i=2;i<=n;++i)cin>>dist[i];
    for(int i=st+1;i<=fin;++i)
    {
        dmin[i]=inf;
        for(int k=i-1;k>=st && (dist[i]-dist[k])<=l3;--k)///de verificat daca e < sau <=
        {
            d=dist[i]-dist[k];
            if(d<=l1)dmin[i]=min(dmin[i],dmin[k]+c1);
            else
            {
                if(d<=l2)dmin[i]=min(dmin[i],dmin[k]+c2);
                else dmin[i]=min(dmin[i],dmin[k]+c3);
            }
        }
    }
    cout<<dmin[fin];
    return 0;
}
