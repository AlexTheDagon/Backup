#include <iostream>
#include <cstdlib>
#define NM 200000
using namespace std;
int n,x[NM],y[NM],d,con,per;
int main()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
       cin>>x[i]>>y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    for(int i=0;i<n-1;++i)
    {
        if(x[i]==x[i+1])consec++;
        else
        {
            per=per+consec*(consec-1)/2;

        }
    }
    return 0;
}
