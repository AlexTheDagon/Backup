#include <iostream>

using namespace std;
int y,a,sem;
int main()
{
    cin>>y;
    if((y%4==0 && y%100!=0) || (y%400==0))sem=1;
    a=1;
    do
    {
        if((y%4==0 && y%100!=0) || (y%400==0))++a;
        ++a;
        y++;
        if(a>7)a=a%7;
        if(a==1)
        {
            if(sem==1 && ((y%4==0 && y%100!=0) || (y%400==0)))sem=2;
            if(sem==0 && (y%4!=0 || (y%100==0 && y%400==0)))sem=2;
        }
    }
    while(sem!=2);
    cout<<y;
    return 0;
}
