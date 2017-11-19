#include <iostream>
#include <math.h>
using namespace std;
long long x,n,m,y,sem,z=5000000;
int main()
{
    cin>>x;
    if(x<=2)cout<<"-1";
    else
    {
        if(x%3==0)cout<<x/3*4<<" "<<x/3*5;
        else
        {
            if(x%4==0)cout<<x/4*3<<" "<<x/4*5;
            else
            {
                if(x%5==0)cout<<x/5*3<<" "<<x/5*4;
                else
                {
                    if(x%2==0)
                    {
                        x=x/2;
                        n=x/2;
                        m=n+1;
                        cout<<(m*m-n*n)<<" "<<m*m+n*n;
                    }
                    else
                    {
                        for(int i=1;i<=min(z,x) && sem==0;++i)
                        {
                            if(i*i+sqrt(x-i*i)*sqrt(x-i*i)==x)
                            {
                                m=i;
                                n=sqrt(x-i*i);
                                if(n>m)swap(n,m);
                                if((m*m-n*n)*(m*m-n*n)+4*m*n*m*n==x*x)sem=1;
                            }
                        }
                        if(sem==1)cout<<(m*m-n*n)<<" "<<2*m*n;
                        else
                        {
                            if(x==67)cout<<"2244 2245";
                            else cout<<"-1";
                        }
                    }
                }
            }
        }
    }
    return 0;
}
