#include <iostream>

using namespace std;
long long x,n;
int main()
{
    cin>>n;
    x=1;
    for(int i=1;i<=n;++i)
    {
        x=(long long)x*i;
    }
    n=(1<<30);
    cout<<n<<endl;
    cout<<x<<endl;
    if(x<n)cout<<"E mai mic";
    else cout<<"e mai mare";
    return 0;
}
