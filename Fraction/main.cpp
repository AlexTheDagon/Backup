#include <iostream>
using namespace std;
int n,fol[101000],lm,solm,sl,pos,ii;
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for(int i=n-1;i>0;--i)
    {
        if(sl>=i)break;
        for(int j=0;j<n*10;++j)fol[j]=0;
        ii=1;
        pos=0;
        while(!fol[ii] && ii!=0)
        {
            fol[ii]=pos++;
            ii=(ii%i)*10;
        }
        if(pos-fol[ii]>sl)
        {
            sl=pos-fol[ii];
            solm=i;
        }
    }
    cout<<solm;
    return 0;
}
