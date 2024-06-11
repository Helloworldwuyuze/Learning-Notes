#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int N=300+5,M=90000+5;
ll n,m,k,dpa[M][N],dpb[M][N],sa[M],sb[M];
struct node{
	ll l,r,c;
}a[M];
bool cmp(node x,node y){
	if(x.r==y.r)return x.l>y.l;
	else return  x.r<y.r;
}
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].c,&a[i].l,&a[i].r);
	sort(a+1,a+1+m,cmp);
	ll cnt=0;
	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++)dpa[i][j]=sa[j];
//		for(int j=n;j>=1;j--)dpb[i][j]=sb[j];
		//printf("%d %d %d\n",a[i].l,a[i].r,a[i].c);
		for(int j=a[i].l;j<=a[i].r;j++){//iÅ£³ÔjÅÉ 
			//if(a[i].l<=j&&j<=a[i].r)dpa[i][j]++;
			//dpa[i][j]=max(dpa[i][j],max(dpa[i-1][j],dpa[i][j-1]));
			//if(a[i].l<=j&&j<=a[i].r)
			dpa[i][j]=max(sa[j-1]+sb[j+1]+a[i].c,sa[j]);
			//printf("%d ",dpa[i][j]);
			
		}
		//puts("");
//		for(int j=a[i].r;j>=a[i].l;j--){
//			//if(a[i].l<=j&&j<=a[i].r)dpb[i][j]++;
//			//dpb[i][j]=max(dpb[i][j],max(dpb[i-1][j],dpb[i][j+1]));
//			//if(a[i].l<=j&&j<=a[i].r)
//			dpb[i][j]=max(sa[j-1]+sb[j+1]+a[i].c,dpb[i][j]);
//			//printf("%d ",dpb[i][j]);
//			
//		}
		for(int j=1;j<=n;j++)sa[j]=max(sa[j-1],dpa[i][j]);
		for(int j=n;j>=1;j--)sb[j]=max(sb[j+1],dpa[i][j]);
		//printf("%lld\n",sa[n]);
		//for(int j=1;j<=n;j++)printf("%d ",sb[j]);
		//puts("");puts("");
	}
	//
	printf("%lld\n",sa[n]);
	return 0;
}
/*
5 5
1 2 2
1 1 2
1 3 3
1 3 4
1 5 5

*/
