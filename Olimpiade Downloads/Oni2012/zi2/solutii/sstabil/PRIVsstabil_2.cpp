#include<stdio.h>
int a[1000005],b[1000005];
int n,i,j,r,p,k,s,t;

int main()
{
	freopen("sstabil.in","r",stdin);
	freopen("sstabil.out","w",stdout);
	scanf("%d\n",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=9; a[n+1]=9; b[0]=9;
	k=0; r=n;
	while (r>0)
	{
		j=r;  s=0;
		do
		{
			s=s+a[j];
			j--;
		}
		while (s<10);

        	p=r; t=a[p];

		while (s-t>9 || t+b[k]<10)
		{
			p--;
			t=t+a[p];
		}
		k++;
		b[k]=t;
		r=p-1;
	}
	for (i=k;i>=1;i--)printf("%d",b[i]);
	fclose(stdout);
	fclose(stdin);
	return 0;
}

