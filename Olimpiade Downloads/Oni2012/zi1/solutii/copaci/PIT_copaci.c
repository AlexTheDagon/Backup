#include<stdio.h>

unsigned char h[200005];
int n,i,j,k;
int nr=0;

int main()
{
freopen("copaci.in","r",stdin);
freopen("copaci.out","w",stdout);

scanf("%d",&n);
for (i=1;i<=n;i++) scanf("%d",&h[i]);

for (j=2;j<n;j++)
    {
        /*caut in stanga primul i cu h[i]>=h[j]*/
        i=j-1;
        while (0<i && h[i]<h[j])i--;
        /*caut in dreapta primul k cu h[j]<=h[k]*/
        k=j+1;
        while (k<=n && h[j]>h[k])k++;
        if (i>0 && k<=n && h[i]>h[j] && h[j]<h[k]) /*trebuie sa avem h[i]!=h[j] si h[j]!=h[k], putem avea insa h[i]==h[k]*/
            nr++;
    }
printf("%d",nr);
fclose(stdout);
fclose(stdin);
return 0;
}
