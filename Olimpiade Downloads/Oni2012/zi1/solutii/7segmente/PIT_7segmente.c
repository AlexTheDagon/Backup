// sursa 100 p - PIT-RADA VASILE

#include<stdio.h>
#include<string.h>

char s[30];
int p,w,pc,i,prest,j,ok,ok2;
int x[10]={0,2,5,5,4,5,6,3,7,6};

int main()
{
freopen("7segmente.in","r",stdin);
freopen("7segmente.out","w",stdout);

scanf("%s %d",s,&p);
w=strlen(s);
pc=0;
for (i=0;i<w;i++)
    pc+=x[s[i]-'0'];
printf("%d ",pc);
prest=p;
ok=0;ok2=1;
for (i=0;i<w;i++)
    {
     for (j=(s[i]-'0')*ok2+9*(1-ok2);j>0;j--)
        if (x[j]+(w-i-1)*2<=prest)
            break;
     if (j>0){ok=1;printf("%d",j);}
     if (j==0 && ok==1)printf("%d",j);
     if (j<s[i]-'0')ok2=0;
     prest-=x[j];
    }
fclose(stdin);
fclose(stdout);
return 0;
}
