#include<cstdio>
#include<bitset>
using namespace std;
int H,W,Q,i,j,n,I,J,N,cnt[4010],poz,m1,m2,m3,m4;
int euclid(int a, int b){
	int c;
	while(b){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
    freopen("intersectii.in","r",stdin);
    freopen("intersectii.out","w",stdout);
    scanf("%d%d%d",&W,&H,&Q);
	for(i=1;i<W;++i)
		for(j=1;j<H;++j){
			m1=i+j-euclid(i,j);
			m2=i+H-j-euclid(i,H-j);
			m3=W-i+H-j-euclid(W-i,H-j);
			m4=W-i+j-euclid(W-i,j);
			cnt[m1]++;cnt[m2]++;cnt[m3]++;
			cnt[m4]++;
		}
	poz=W+H;
	//for(i=1;i<=poz;++i) cnt[i]+=cnt[i-1];
    for(;Q;Q--)
    {
        scanf("%d",&i);
		if(i>poz) printf("0\n");
        else printf("%d\n",cnt[i]);
    }
    return 0;
}
