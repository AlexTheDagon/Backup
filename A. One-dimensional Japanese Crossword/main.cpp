#include <iostream>

using namespace std;
int n,j,a[100],k,nr;
char c;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>c;
        if(c=='B')k++;
        else
        {
            if(k!=0)
            {
                ++j;
                ++nr;
                a[j]=k;
                k=0;
            }
        }
    }
    if(c=='B')
    {
        ++j;
        ++nr;
        a[j]=k;
        k=0;
    }
    if(nr>0)
    {
        cout<<nr<<'\n';
        for(int i=1;a[i]!=0;++i)cout<<a[i]<<" ";
    }
    else cout<<"0";
    return 0;
}
