#include <iostream>

using namespace std;
int config=0,n,a[30],impuscaturi[30],cmin[1<<20],fin=1;
void dp(int config_act,int config_pre)
{
    int dmg=0;
    for(int i=0;i<n;++i)if((config_act & (1<<i))==0)dmg+=a[i];
    if((cmin[config_act]>cmin[config_pre]+dmg || cmin[config_act]==0)&& config_pre!=fin)
    {
        cmin[config_act]=cmin[config_pre]+dmg;
        for(int i=1;i<=n;++i)
        {
            if(config_act|impuscaturi[i]!=config_act)
            {
                dp(config_act|impuscaturi[i],config_act);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        fin|=(1<<(i));
    }
    impuscaturi[1]=3<<(n-2)|1;
    impuscaturi[2]=1<<(n-1)|3;
    impuscaturi[3]=7;
    for(int i=4;i<=n;++i)impuscaturi[i]=impuscaturi[i-1]<<1;
    for(int i=1;i<=n;++i)
    {
        dp(impuscaturi[i],config);
    }
    cout<<cmin[fin];
    return 0;
}
///configuratiile impuscaturilor pe biti 00011100 inseamna ca balconul 4,5,6 au fost distruse
///mai am un sir care are impuscaturile si verific recursiv configuratiile
///impuscaturile sunt toate confugiuratiile binare ce au numa 3 impuscaturi
///un sir de n moduri de a impusca
///Sa verific ca--> nr_actual | impuscatura!=nr_actual
///Actualizez la fiecare pas costmin[nr_actual]+=costmin[nr_precedent]


///configuratie initiala
///impuscaturile
///ma opresc din mers daca costmin>costminactual
///cmin[act]=cmin[act]+nr_de_monstri_ramasi(care il verific cu :for(int i=0;i<n;++i)if(nr_act & (1<<i)==0))
