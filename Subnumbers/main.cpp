#include <iostream>

using namespace std;
int ciur[100000],a,b,spec,nr[10],cif,aux,nou,sem,p;
int main()
{
    for(int i=1;i<=100000;++i)ciur[i]=1;
    for(int i=2;i<=100000;++i)
        if(ciur[i]==1)
            for(int j=i+i;j<=100000;j+=i)ciur[j]=0;
    //bine
    cin>>a>>b;
    if(a>100000)cout<<"0";
    else
    {
        b=min(b,10000);
        for(int n=a;n<=b;++n)
        {
            aux=n;
            cif=0;
            while(aux)
            {
                nr[++cif]=aux%10;
                aux/=10;
            }
            sem=1;
            for(int i=1;i<(1<<(cif)) && sem;++i)
            {
                p=1;
                nou=0;
                for(int j=0;j<cif;++j)
                {
                    if(i&(1<<j))
                    {
                        nou=nou+p*(nr[j+1]);
                        p*=10;
                    }
                }
                if(!ciur[nou])sem=0;
            }
            if(sem)++spec;
        }
        cout<<spec;
    }
    return 0;
}
