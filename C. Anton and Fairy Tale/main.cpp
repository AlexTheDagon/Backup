#include <iostream>
#include <math.h>
using namespace std;
long long n,m,zile,a;
int main()
{
    cin>>n>>m;
    if(n>m)
    {
        zile=m;
        a=sqrt(2*n);
        a-=5;
        if(a<0)a=0;
        zile+=a;
        n-=(a*(a+1)/2+m);///finalul celei de a m+a zi
        ///bine
        ///in ziua zile am consumat a+m graunte si au mai ramas n in depozit
        if(n>0)
        {
            ++zile;
            ++a;
            while(n>0)
            {
                n+=m;
                n=n-a-m;
                ++a;
                ++zile;
            }
            --zile;
        }
        cout<<zile;
    }
    else cout<<n;
    return 0;
}
