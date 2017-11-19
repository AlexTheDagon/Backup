#include <iostream>

using namespace std;
long long a,b,c,n;
int main()
{
    cin>>n;
    if(n>2)
    {
        a=1;
        b=1;
        for(int i=1;i<=n-2;++i)
        {
            c=a+b;
            a=b;
            b=c;
        }
        cout<<2*c;
    }
    else
    {
       cout<<"2";
    }
    return 0;
}
