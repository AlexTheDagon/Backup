#include <iostream>

using namespace std;
char x;
int n,m,sem;
int main()
{
    cin>>n>>m;
    for(int  i=1;i<=n*m;++i)
    {
        cin>>x;
        if(x=='C' || x=='M' || x=='Y')sem=1;
    }
    if(sem==1)cout<<"#Color";
    else cout<<"#Black&White";
    return 0;
}
