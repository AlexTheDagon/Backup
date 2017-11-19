#include <iostream>

using namespace std;
long long l1,l2,r1,r2,k,n;
int main()
{
    cin>>l1>>r1>>l2>>r2>>k;
    if(r1<l2 || r2<l1)n=0;
    else{if(l1<=l2 && r1>=r2)
    {
        if(k<=r2 && k>=l2)n=r2-l2;
        else n=r2-l2+1;

    }
    else
    {
        if(l1<=r2 && l2<=l1 && r1>r2)
        {
            if(l1<=k && r2>=k)n=r2-l1;
            else n=r2-l1+1;

        }
        else
        {
            if(l1<=l2 && l2<=r1)
            {
                if(l2<=k && r1>=k)n=r1-l2;
                else n=r1-l2+1;

            }
            else
            {
                if(k<=r1 && k>=l1)n=r1-l1;
                else n=r1-l1+1;

            }
        }
    }}
    cout<<n;
    return 0;
}
