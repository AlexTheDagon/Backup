#include <iostream>
#include <string.h>
using namespace std;
char P[1000],T[1000],S[2000];
int Z[2000];
int n,m;

void calculZ(int m,char S[], int Z[])
{
    int L,R,kp,beta;
    Z[1]=0;
    L=R=1;
    for (int k=2;k<=m;k++)
        if (S[k]!=S[1])
            Z[k]=0;
        else
            if (k>R)
            {
                Z[k]=1;
                while (S[k+Z[k]]==S[1+Z[k]])
                    Z[k]++;
                L=k;
                R=k+Z[k]-1;
            }
            else
            {
                kp=k-(L-1);
                beta=R-(k-1);
                Z[k]=min(Z[kp],beta);
                while (S[k+Z[k]]==S[1+Z[k]])
                    Z[k]++;
                if (k+Z[k]-1>R)
                {
                    L=k;
                    R=k+Z[k]-1;
                }
            }
}

int main()
{
    cin>>P;
    cin>>T;
    strcpy(S+1,P);
    strcat(S+1,"*");
    strcat(S+1,T);
    n=strlen(P);
    m=strlen(S+1);
    calculZ(m,S,Z);
    for (int i=1;i<=m;i++)
        cout<<S[i]<<" ";
    cout<<"\n";
    for (int i=1;i<=m;i++)
        cout<<Z[i]<<" ";
    return 0;
}
