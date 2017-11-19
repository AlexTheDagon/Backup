#include <iostream>
#include <math.h>
using namespace std;
int a,b,apa[10],apb[10],sem;
int main()
{
    cin>>a>>b;
    while(a>0)
    {
        apa[a%10]=1;
        a=a/10;
    }
    while(b>0)
    {
        apb[b%10]=1;
        b=b/10;
    }
    for(int cif=0;cif<=9;cif++)if(apa[cif]==1 && apb[cif]==1)sem=1;
    if(sem)cout<<"au cifre comune";
    else cout<<"Nu au cifre comune";
    return 0;
}
