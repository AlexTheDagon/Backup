#include<stdio.h>
int s[5000],W,H,Q,i,j,x,y,r,k;
int main()
{
freopen("intersectii.in","r",stdin);
freopen("intersectii.out","w",stdout);
scanf("%d%d%d",&W,&H,&Q);
for (i=1;i<=W-1;i++)
    {
    if (i<W && i<H)s[i]++;
    for (j=i+1;j<=H-1;j++)
        {
            x=i; y=j; while (y){r=x%y; x=y; y=r;}
            s[i+j-x]++;
            if(i<H && j<W)s[i+j-x]++;
        }
    }
for (i=1;i<=Q;i++)
    {
    scanf("%d",&k);
    printf("%d\n",4*s[k]);
    }
fclose(stdout);
fclose(stdin);
return 0;
}
