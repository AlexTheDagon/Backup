#include <iostream>

using namespace std;
char c[100001];
int n;
int cond(char x)
{
    if(x=='1' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6' || x=='7' || x=='8' || x=='9' || x=='0')return 1;
    return 2;
}
int main()
{
    cin>>c;
    for(int i=0;cond(c[i])==1;++i)
    {
        ++n;
        cout<<c[i];
    }
    for(int i=n-1;i>=0;--i)cout<<c[i];
    return 0;
}
