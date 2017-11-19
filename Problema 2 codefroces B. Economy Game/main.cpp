#include <iostream>

using namespace std;
int n,sem;
int main()
{
    cin>>n;
    if(n>=1234567)
    {
        for(int i=0;i<=n/1234567 && sem==0;++i)
        {
            for(int j=0;j<=(n-i*1234567)/123456 && sem==0;++j)
            {
                for(int k=0;k<=(n-i*1234567-j*123456)/1234 && sem==0;++k)
                {
                    if((n-i*1234567-j*123456)%1234==0)sem=1;
                }
            }
        }
    }
    else
    {
        if(n>=123456)
        {
            for(int i=0;i<=n/123456 && sem==0;++i)
            {
                for(int j=0;j<=(n-i*123456)/1234 && sem==0;++j)
                {
                    if((n-i*123456)%1234==0)sem=1;
                }
            }
        }
        else
        {
            if(n%1234==0)sem=1;
        }
    }
    if(sem==1)cout<<"YES";
    else cout<<"NO";
    return 0;
}
