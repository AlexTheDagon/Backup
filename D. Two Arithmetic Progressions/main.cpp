#include <iostream>

using namespace std;
long long nr,r1,r2,a1,a2,L,R,mc,maxx,minn,i;
int main()
{
    cin>>r1>>a1>>r2>>a2>>L>>R;
    maxx=max(r1,r2);
    minn=r1+r2-maxx;
    mc=maxx;
    while(mc%minn!=0)mc=mc+maxx;
    i=max(L,max(a1,a2));
    while((i-a1)%r1!=0 && (i-a2)%r2!=0 && i<=R)++i;
    while(i<=R)
    {
        if((i-a1)%r1==0 && (i-a2)%r2==0)nr++;
        i=i+mc;
    }
    cout<<nr;
    return 0;
}
