#include <iostream>

using namespace std;
char a[2005],c;
int d,s,n,mij;
int main()
{
    cin>>n;
    if(n>2)
    {
        if(n%2==0)
        {
            mij=n/2;
            for(int i=1;i<=n;++i)
            {
                cin>>c;
                if(i%2==0)
                {
                    ++d;
                    a[mij+d]=c;
                }
                else
                {
                    a[mij-s]=c;
                    ++s;
                }
            }
        }
        else
        {
            mij=n/2+1;
            for(int i=1;i<=n;++i)
            {
                cin>>c;
                if(i%2==1)
                {
                    a[mij+d]=c;
                    ++d;
                }
                else
                {
                    ++s;
                    a[mij-s]=c;
                }
            }
        }
        for(int i=1;i<=n;++i)cout<<a[i];
    }
    else
    {
        cin>>a;
        cout<<a;
    }
    return 0;
}
