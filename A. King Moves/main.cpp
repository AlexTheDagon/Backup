#include <iostream>

using namespace std;
char x;
int y,sem,m;
int main()
{
    cin>>x>>y;
    m=8;
    if(x=='a' || x=='h')
    {
        m=m-3;
        sem++;
    }
    if(y==1 || y==8)
    {
        m=m-3;
        sem++;
    }
    if(sem==2)m++;
    cout<<m;
    return 0;
}
