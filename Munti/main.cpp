#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin ("munti.in");
ofstream fout ("munti.out");
int main()
{
    int n,v,p,x,y,im,nrim,am,nram,nrm,s;
    fin>>n;
    nrim=0; nram=0; nrm=0; p=0; s=0;
    im=-1;
    am=INT_MIN;
    for (int i=1;i<=n;i++)
    {
        fin>>v;
        if (v>0&&p==0)
            ++nrm;
        if (v>im)
        {
            im=n;
            x=0;
        }
        if (v==im)
            x++;
        s+=v;
        if (s>am)
        {
            am=s;
            y=0;
        }
        if (s==am)
            y++;
        if (v==0)
            s=0;
    }
    fout<<nrm<<'\n'<<im<<'\n'<<nrim<<'\n'<<am<<'\n'<<nram;
    return 0;
}
