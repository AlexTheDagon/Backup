#include <iostream>

using namespace std;
int sem,k,n;
char a[8010];
int main()
{
    for(int i=0;i<8005;++i)a[i]='2';
    cin>>a;
    n=8005;
    for(int i=0;i<n;++i)if(a[i]=='2')n=i-1;
    for(int i=0;i<n && sem==0;i=i+8)
    {
        if((k==0 && a[i]=='0') || (k!=0 && a[i]!='0'))sem=1;
        else
        {
            if(a[i]=='0')k--;
            else
            {
                for(int j=i+7;a[j]!='1';--j)++k;
            }
        }
    }
    if(sem==1)cout<<"No";
    else cout<<"Yes";

    return 0;
}
