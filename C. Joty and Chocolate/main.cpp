#include <iostream>

using namespace std;
long long n,a,b,p,q,d=2,x=1,ca,cb;
int main()
{
    cin>>n>>a>>b>>p>>q;
    ca=a;
    cb=b;
    while(ca>1 || cb>1)
    {
        if(ca%d==0 || cb%d==0)
        {
            if(ca%d==0)ca=ca/d;
            if(cb%d==0)cb=cb/d;
            x=x*d;
        }
        else ++d;
    }
    cout<<(n/a*p)+(n/b*q)-(n/x*min(p,q));
    return 0;
}
