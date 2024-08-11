#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005],a2[100005];
int b[100005];
int c[100005];int n,q;
int lowbit(int x){return x&-x;}
void add(int x,int d){for(int i=x; i<=n; i+=lowbit(i))c[i]+=d;}
int sum(int x){int ans=0;for(int i=x; i; i-=lowbit(i))ans+=c[i];return ans;}
int tmp[100005],tmpp[100005],s[100005];
bool del[100005];
int main(){
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a2[i]=a[i];
		b[a[i]]=i;
		tmp[i]=tmpp[i]=sum(n)-sum(a[i])+1;
		add(a[i],1);
	}memset(c,0,sizeof c);
	long long ans=0;
	for(int i=n; i>=1; i--){
		s[i]=sum(a[i]);
		if(sum(a[i])>0)tmp[i]=1;
		add(a[i],1);
		ans+=tmp[i];
	}printf("%lld ",ans);
	while(q--){
		int x;
		scanf("%d",&x);
		int id=x;
		ans-=tmp[id];
		del[id]=1;
		for(int i=1; i<id; i++){
			if(!del[i]&&a[i]>a[id])s[i]--;
			if(s[i]==0&&!del[i]){
				ans-=tmp[i];
				ans+=tmpp[i];
				tmp[i]=tmpp[i];
			}
		}for(int i=id+1; i<=n; i++){
			if(!del[i]&&a[i]<a[id]){
				ans-=tmp[i];
				tmpp[i]--;
				tmp[i]=min(tmp[i],tmpp[i]);
				ans+=tmp[i];
			}
		}
		printf("%lld ",ans);
	}
	return 0;
}
