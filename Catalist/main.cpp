#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define pb push_back
#define mp make_pair
#include <algorithm>
#define NM 10000
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
struct immput
{
    string idimm;
    string ownerimm;
    long long sumimm;
};
struct auuuput
{
    string ownerauuu;
    long long sumauuu;
};
struct tranzzz
{
    string idtranzzz;
    int nrimm,nrauuu,stimm,stauuu,ebun=1;
    long long timme;
    bool operator < (const tranzzz &other ) const
    {
        return timme<other.timme;
    }
};
immput imm[NM];
auuuput auuu[NM];
tranzzz tr[NM];
int n,indimm,indauuu,nuebun[NM],viz[NM],vizz[NM],nrn;
void citire()
{
    in>>n;
    nrn=n;
    for(int i=1;i<=n;++i)
    {
        long long sem=0,summ=0,sumu=0;
        tr[i].stimm=indimm+1;
        tr[i].stauuu=indauuu+1;
        in>>tr[i].idtranzzz>>tr[i].nrimm;
        for(int j=1;j<=tr[i].nrimm;++j)
        {
            in>>imm[indimm+j].idimm>>imm[indimm+j].ownerimm>>imm[indimm+j].sumimm;
            if(imm[indimm+j].sumimm<0)sem=1;
            summ+=imm[indimm+j].sumimm;
        }
        in>>tr[i].nrauuu;
        for(int j=1;j<=tr[i].nrauuu;++j)
        {
            in>>auuu[indauuu+j].ownerauuu>>auuu[indauuu+j].sumauuu;
            for(int jj=indauuu+1;jj<indauuu+j;++jj)if(auuu[j].ownerauuu==auuu[jj].ownerauuu)sem=1;
            if(auuu[indauuu+j].sumauuu<=0)sem=1;
            sumu+=auuu[indauuu+j].sumauuu;
        }
        indimm+=tr[i].nrimm;
        indauuu+=tr[i].nrauuu;
        in>>tr[i].timme;
        if(tr[i].timme<=0)sem=0;
        if(sem)tr[i].ebun=0;
        if(summ!=sumu)tr[i].ebun=0;
    }///citire
    sort(tr+1,tr+n+1);
    for(int i=1;i<=n;++i)
    {
        for(int ii=tr[i].stimm;ii<tr[i].stimm+tr[i].nrimm && tr[i].ebun==1;++ii)
        {
            if(imm[ii].ownerimm!="origin")
            {
                int ssem=0;
                for(int j=1;j<i && ssem==0;++j)
                {
                    for(int jj=tr[j].stauuu;jj<tr[j].stauuu+tr[j].nrauuu && ssem==0;++jj)
                    {
                        if(imm[ii].ownerimm==auuu[jj].ownerauuu && imm[ii].sumimm==auuu[jj].sumauuu && tr[j].ebun==1 && !vizz[jj])
                        {
                            vizz[jj]=1;
                            ssem=1;
                        }
                    }
                }
                tr[i].ebun=ssem;
            }
        }
        if(tr[i].ebun)
        {
            for(int ii=tr[i].stimm;ii<tr[i].stimm+tr[i].nrimm;++ii)
            {
                if(imm[ii].ownerimm!="origin")
                {
                    int ssem=0;
                    for(int j=1;j<i && ssem==0;++j)
                    {
                        for(int jj=tr[j].stauuu;jj<tr[j].stauuu+tr[j].nrauuu && ssem==0;++jj)
                        {
                            if(imm[ii].ownerimm==auuu[jj].ownerauuu && imm[ii].sumimm==auuu[jj].sumauuu && tr[j].ebun==1 && !viz[jj])
                            {
                                viz[jj]=1;
                                ssem=1;
                            }
                        }
                    }
                    tr[i].ebun=ssem;
                }
            }
        }
    }
    for(int i=1;i<NM-10;++i)vizz[i]=viz[i];
    for(int i=1;i<=n;++i)if(!tr[i].ebun)--nrn;
}
int main()
{
    citire();
    out<<nrn<<'\n';
    for(int i=1;i<=n;++i)
    {
        if(tr[i].ebun)
        {
            out<<tr[i].idtranzzz<<" "<<tr[i].nrimm<<" ";
            for(int j=tr[i].stimm;j<tr[i].stimm+tr[i].nrimm;++j)out<<imm[j].idimm<<" "<<imm[j].ownerimm<<" "<<imm[j].sumimm<<" ";
            out<<tr[i].nrauuu<<" ";
            for(int j=tr[i].stauuu;j<tr[i].stauuu+tr[i].nrauuu;++j)out<<auuu[j].ownerauuu<<" "<<auuu[j].sumauuu<<" ";
            out<<tr[i].timme<<'\n';
        }
    }
    return 0;
}
