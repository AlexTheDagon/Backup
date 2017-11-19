#include <iostream>

using namespace std;
long long a,b,n,cur,p;
int main()
{
    cin>>a>>b>>n;
    if(n==2)cout<<a+b<<" "<<a+a+b<<'\n';
    else
    {
        cout<<a+b<<" ";
        cur=3;
        while(cur<=n)
        {
            p=cur;
            cur=cur*2-1;
        }
        cout<<a*p+b;
    }
    return 0;
}
