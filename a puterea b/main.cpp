#include <iostream>

using namespace std;
long long a,p;
long long put(long long x,long long putere)
{
    if(putere>1)
    {
        cout<<x<<" "<<putere<<endl;
        if(putere%2==0)return put(x*x,putere/2);
        return put(x*x,putere/2)*x;
    }
    return x;
}
int main()
{
    cin>>a>>p;
    if(p!=0)cout<<put(a,p);
    else cout<<"1";
    return 0;
}
