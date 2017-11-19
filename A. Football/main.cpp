#include <iostream>

using namespace std;
int sem,c1,c0;
char a[111];
int main()
{
    for(int i=0;i<=105;++i)a[i]='2';
    cin>>a;
    for(int i=0;a[i]!='2';++i)
    {
        if(a[i]=='0')
        {
            c1=0;
            c0++;
        }
        else
        {
            c0=0;
            c1++;
        }
        if(c1>=7 || c0>=7)sem=1;
    }
    if(sem==1)cout<<"YES";
    else cout<<"NO";
    return 0;
}
