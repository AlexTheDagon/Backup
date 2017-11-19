#include <iostream>

using namespace std;
int a[4],b[4],sa[4],sb[4],k;
pair <int,int> pr[10000];
int main()
{
    for(int i=1;i<=3;++i)
    {
        cin>>a[i]>>b[i];
        sa[i]-=a[i];
        sb[i]-=b[i];
        for(int j=1;j<=3;++j)
        {
            if(j!=i)
            {
                sa[j]+=a[i];
                sb[j]+=b[i];
            }
        }
    }
    cout<<"3"<<'\n';
    for(int i=1;i<=3;++i)cout<<sa[i]<<" "<<sb[i]<<endl;

    return 0;
}
