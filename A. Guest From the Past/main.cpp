#include <iostream>

using namespace std;
long long n,a,b,c,p1,p2,r1,r2;
int main()
{
    cin>>n>>a>>b>>c;
    if(n>=a || n>=b)
    {
        p1=(n-b)/(b-c)+1;
        p2=n/a;
        r1=(n-(b-c)*(p1-1)-b)/a;
        r2=((n-n/a*a)-b)/(b-c)+1;
        p1+=r1;
        if(r1<0)p1-=r1;
        p2+=r2;
        if(r2<0)p2-=r2;
        cout<<p1<<" "<<p2<<" "<<r1<<" "<<r2;
        cout<<max(p1,p2);
    }
    else cout<<"0";
    return 0;
}

