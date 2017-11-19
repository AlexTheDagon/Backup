#include <iostream>
#include <fstream>
using namespace std;
ifstream in("compus.in");
ofstream out("compus.out");
int m,sol,h,l,cmax,cmin,o;
int main()
{
    in>>m;
    for(int h=2;h<m;h+=2)
    {
        cmin=(2*m+h-6);
        if(cmin%16!=0)cmin+=16;
        cmin/=16;
        cmax=(m-h-3)/5;
        ///stabilit cmax si cmin
        while(2*cmin%3!=(m-h)%3)++cmin;
        while(2*cmax%3!=(m-h)%3 && cmax>0)--cmax;
        o=(cmax-cmin)/3+1;
        if(o>0 && cmax>=cmin)sol+=o;
    }
    out<<sol;
    return 0;
}
/**
cmin=(2m+h-6)/16
cmax=(m-h-3)/5;
o=(m-5c-h)/3;


(m-h)%3=0
5c%3=0
->2c%3=0
c%3=0;
c ii din 3 in 3

(m-h)%3=1
2c%3=1
->c%3=2
**/
