#include <iostream>

using namespace std;
int n,x;
char a[102];
int main()
{
    cin>>x;
    for(int i=1;i<=x;++i)
    {
        n=0;
        cin>>a;
        for(int i=0;a[i]-'a'>=0 && a[i]-'z'<=0;++i)++n;
        if(n>10)cout<<a[0]<<n-2<<a[n-1];
        else for(int i=0;i<n;++i)cout<<a[i];
        cout<<endl;
    }
    return 0;
}
