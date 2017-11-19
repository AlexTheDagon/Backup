#include<stdio.h>
int s[5000],W,H,Q,i,j,x,y,r,k,H12,W12,H2,W2;
int main()
{
freopen("intersectii.in","r",stdin);
freopen("intersectii.out","w",stdout);
scanf("%d%d%d",&W,&H,&Q);
W2=W/2; H2=H/2;
H12=(H-1)/2;
W12=(W-1)/2;
for (i=1;i<=W12;i++)
    for (j=1;j<=H12;j++)
        {
        x=i; y=j;while (y){r=x%y;x=y;y=r;}
        s[i+j-x]+=4;
        x=W-i; y=j;while (y){r=x%y;x=y;y=r;}
        s[W-i+j-x]+=4;
        x=i; y=H-j;while (y){r=x%y;x=y;y=r;}
        s[i+H-j-x]+=4;
        x=W-i; y=H-j;while (y){r=x%y;x=y;y=r;}
        s[W-i+H-j-x]+=4;
        }
if (W%2==0)
    for (j=1;j<=H12;j++)
        {
        x=W2; y=j;while (y){r=x%y;x=y;y=r;}
        s[W2+j-x]+=4;

        x=W2; y=H-j;while (y){r=x%y;x=y;y=r;}
        s[W2+H-j-x]+=4;
        }

if (H%2==0)
    for (i=1;i<=W12;i++)
        {
        x=i; y=H2;while (y){r=x%y;x=y;y=r;}
        s[i+H2-x]+=4;

        x=W-i; y=H2;while (y){r=x%y;x=y;y=r;}
        s[W-i+H2-x]+=4;
        }
if (W%2==0  &&  H%2==0)
    {
    x=W2; y=H2; while (y){r=x%y; x=y; y=r;}
    s[W2+H2-x]+=4;;
    }
for (i=1;i<=Q;i++)
    {
    scanf("%d",&k);
    printf("%d\n",s[k]);
    }
fclose(stdout);
fclose(stdin);
return 0;
}
