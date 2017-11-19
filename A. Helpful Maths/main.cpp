#include <iostream>

using namespace std;
char a[101];
int b1,b2,b3;
int main()
{
    cin>>a;
    for(int i=0;i<=100;++i)
    {
        if(a[i]=='1')++b1;
        else
        {
            if(a[i]=='2')++b2;
            else
            {
                if(a[i]=='3')++b3;
            }
        }
    }
    for(int i=0;i<=100;i=i+2)
    {
        if(b1>0)
        {


                a[i]='1';
                b1--;

        }
        else
        {
            if(b2>0)
            {


                    a[i]='2';
                    b2--;

            }
            else
            {


                    a[i]='3';
                    b3--;

            }
        }
    }
    for(int i=0;i<100 && a[i]!=(char)0;++i)cout<<a[i];
    return 0;
}
