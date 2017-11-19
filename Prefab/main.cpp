#include <iostream>

using namespace std;
int a,b,x,y;
int main()
{
    cin>>a>>b>>x>>y;
    if(x>y)swap(x,y);
    if(a>b)swap(a,b);
    if(x<=a && y<=b)cout<<"0";
    else
    {
        if(a>x && y>b)cout<<(y-b)*x/2;
        else cout<<(x-b)*y/2;
    }
    return 0;
}
