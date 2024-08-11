#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int l,r;
	int w;
	int lenth;
}a[47000];
int ans=0;
int pie[305];
bool cmp(node x,node y){
	if(x.lenth==y.lenth)return x.w>y.w;
	return x.lenth<y.lenth;
}
int kk=0;
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i].w,&a[i].l,&a[i].r);
		a[i].lenth=a[i].r-a[i].l+1;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=0;i<=301;++i)pie[i]=i;
	for(int i=1;i<=m;++i){
		if(pie[a[i].r]-pie[a[i].l-1]>0){
			ans+=a[i].w;
			kk=pie[a[i].r]-pie[a[i].l-1];
			for(int j=a[i].l;j<=a[i].r;++j)pie[j]=pie[j-1];
			for(int j=a[i].r+1;j<=n;++j)pie[j]-=kk;
//			for(int j=0;j<=n;++j)printf("%d ",pie[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
