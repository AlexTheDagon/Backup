#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("puteri4.in");
ofstream out("puteri4.out");
long long t,x,y;
long long a,b,nr;
int main()
{
    in>>t;
    for(int teste=1;teste<=t;++teste)
    {
        in>>x>>y;
        nr=0;
        if(x==1)
        {
            nr=1;
            x=2;
        }
        for(int i=2;i<=70 && pow(y,1.0/i)>=2;++i)
        {
            a=pow(x,1.0/i);
            b=pow(y,1.0/i);
            if(a==1)++a;
            cout<<a<<" "<<b<<" "<<i<<endl;
            if(b>=a)nr+=(b-a+1);
        }
        out<<nr<<'\n';
    }
    return 0;
}
