#include <iostream>

using namespace std;

int main()
{
    cout<<"Va rugam sa introduceti distanta,numarul de saptamani si zile pe care a parcurs nava.";
    int a,b,d,v,t;
    cin>>a,b,d;
    if (a!=0)
        {
        b=b+a*7;
        }
        else b=b+0;
    t=84400*b;
    d=d*1000;
    v=d/t;
    cout<<v<<" m/s";
    return 0;
}
