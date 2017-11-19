#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int s,x1,x2,t1,t2,p,d,tren,jos;
int main()
{
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    jos=abs(x1-x2)*t2;
    if(x1>x2)
    {
        if(d==-1)
        {
            tren=s+p+s-x2;
        }
        else
        {
            tren=s-p+s-x2;
        }
    }
    else
    {
        if(d==-1)
        {
            tren=p+x2;
        }
        else
        {
            tren=s-p+s+x2;
        }
    }
    tren=tren*t1;
    cout<<min(tren,jos);
    return 0;
}
