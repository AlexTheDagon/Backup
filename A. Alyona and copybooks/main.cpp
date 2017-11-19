#include <iostream>

using namespace std;
long long n,a,b,c,s;
int main()
{
    cin>>n>>a>>b>>c;
    if(n%4==0)s=0;
    else
    {
        if(n%4==1)
        {
            s=min(3*a,min(b+a,c));
        }
        else
        {
            if(n%4==2)s=min(a+a,min(b,2*c));
            else s=min(a,min(3*c,b+c));
        }
    }
    cout<<s;
    return 0;
}
