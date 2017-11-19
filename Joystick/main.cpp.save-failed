#include <iostream>

using namespace std;

int a,b,aux,minute;
int main()
{
    cin>>a>>b;
    if(a!=1 || b!=1)
    {
    while(a>0 && b>0)
        {
            if(a>b)
            {
                aux=a;
                a=b;
                b=aux;
            }
            ++a;
            b-=2;
            minute++;
        }
    }
    cout<<minute;
    return 0;
}
