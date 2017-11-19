#include <iostream>
#include <stdlib.h>
using namespace std;
int c,x,y;
int main()
{
    for(int i=1;i<=5;++i)
    {
        for(int j=1;j<=5;++j)
        {
            cin>>c;
            if(c)
            {
                cout<<abs(3-i)+abs(3-j);
            }
        }
    }
    return 0;
}
