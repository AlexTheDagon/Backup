#include <iostream>

using namespace std;
int n,sem,x;
char a[200005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(x%2==0 && x>0)a[i]='p';
        else if(x%2==1)a[i]='i';
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]=='i' && a[i+1]=='i')
        {
            a[i]='p';
            a[i+1]='p';
        }
        else
        {
            if(a[i]=='i' && a[i+1]=='p' && a[i+2]=='i')
            {
                a[i]='p';
                a[i+2]='p';
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]=='i')sem=1;
    }
    if(sem==1)cout<<"NO";
    else cout<<"YES";
    return 0;
}
