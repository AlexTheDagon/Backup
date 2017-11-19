#include <iostream>

using namespace std;
char a,b;
int n,k;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        if(a==b)k++;
        b=a;
    }
    cout<<k;
    return 0;
}
