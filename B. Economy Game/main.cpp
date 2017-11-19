#include <iostream>

using namespace std;
int n,x1,x2,sem;
char a[100];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>x1>>x2;
        if(x1>=2400 && x2>x1)sem=1;
    }
    if(sem==1)cout<<"YES";
    else cout<<"NO";
    return 0;
}
