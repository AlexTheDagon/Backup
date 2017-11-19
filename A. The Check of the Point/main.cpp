#include <iostream>

using namespace std;
int a,x,y;
int main()
{
    cin>>a>>x>>y;
    if(x<a && 0<x && y<a && y>0)cout<<"0";
    else
    {
        if((a==x && 0<=y && y<=a)||(a==y && 0<=y && y<=a))cout<<"1";
        else cout<<"2";
    }
    return 0;
}
