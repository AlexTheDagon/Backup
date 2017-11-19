#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("palindrom3.in");
ofstream fout ("palindrom3.out");

int c[10],v[10];
int main()
{
    int n,uc,aux,nrc,contor,x,cm;
    fin>>n;
    nrc=0;
    cm=10;
    for (int i=0;i<=9;i++)
    {
        aux=n;
        contor=0;
        while (aux>0)
        {
            uc=aux%10;
            aux/=10;
            if (i==uc)
                contor++;
            v[i]=contor;
            if (uc<cm)
                cm=uc;
        }
        nrc+=contor;
    }
    x=1;
    for (int i=9;i>=0;i--)
    {
        if (v[i]/2>=1&&i!=cm)
            for (int j=1;j<=v[i]/2;j++)
            {
                c[x]=i;
                c[nrc-x+1]=i;
                x++;
            }
        if (i==cm)
            for (int j=1;j<=v[i];j++)
            {
                c[x]=i;
                x++;
            }
    }
    for (int i=0;i<=9;i++)
    {
        if (v[0]==0&&c[i]!=0)
            fout<<c[i];
        if (v[0]>0)
            if (c[i]!=0)
                fout<<c[i];
    }
    return 0;
}
