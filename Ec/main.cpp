#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("ec.in");
ofstream out("ec.out");
long long val[300005],x,n,m,a,b,c,d,delta;
char s;
double x1,x2,xx;
int ec1,ec2,sol1,sol2;
int main()
{
    in>>m>>n;
    for(int i=1;i<=m*m;++i)
    {
        in>>x;
        val[x+100000]=1;
    }
    for(int i=1;i<=n;++i)
    {
        in>>a;
        in>>s>>s;
        if(s=='^')
        {
            ++ec2;
            in>>s>>b>>s>>c>>s>>d;
            ///corect
            c-=d;
            delta=b*b-4*a*c;
            if(delta>=0)
            {
                xx=sqrt(delta);
                if(xx==(int)xx)
                {
                    if(a!=0)
                    {
                        x1=1.0*(-b+xx)/2/a;
                        x2=1.0*(-b-xx)/2/a;
                        if(x1==(int)x1 && x2==(int)x2 && val[(int)x1+100000] && val[(int)x2+100000])
                        {
                            ++sol2;
                            cout<<a<<" "<<b<<" "<<c<<" "<<x<<endl;
                        }
                    }
                    else
                    {
                        a=b;
                        b=c;
                        c=d;
                        c-=b;
                        if(a!=0)
                        {
                            if(1.0*c/a==c/a && val[c/a+100000])++sol2;
                        }
                    }
                }
            }
        }
        else
        {
            ++ec1;
            in>>b;
            if(s=='-')b*=(-1);
            in>>s>>c;
            c-=b;
            if(a!=0)
            {
                if(1.0*c/a==c/a && val[c/a+100000])++sol1;
            }
        }
    }
    out<<ec1<<" "<<sol1<<'\n';
    out<<ec2<<" "<<sol2;
    return 0;
}
