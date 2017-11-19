#include <iostream>

using namespace std;
int a,b,h1,h2,k;
int main()
{
    cin>>h1>>h2>>a>>b;
    if(a>b)
    {
        h1=h1+8*a;
        while(h1<h2)
        {
            h1=h1-12*b;
            h1=h1+12*a;
            ++k;
        }
    }
    else
    {
        if((h1+8*a)>=h2)k=0;
        else k=-1;
    }
    cout<<k;

    return 0;
}
