#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define il inline
#define N 200005
il ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int sum[3][N],n,k,que[N],tot;
char s[N];
int main() {
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) sum[0][i]=sum[0][i-1]+(s[i]=='J');
	for(int i=1;i<=n;i++) {
		sum[1][i]=sum[1][i-1]+(s[i]=='O');
		if(s[i]=='O') que[++tot]=i;
	}
	for(int i=1;i<=n;i++) sum[2][i]=sum[2][i-1]+(s[i]=='I');
	if(tot<k) {
		printf("-1\n");
		return 0;
	}
	int ans=1e9;
	for(int i=1;i+k-1<=tot;i++) {
		if(sum[0][que[i]-1]<k||(sum[2][n]-sum[2][que[i+k-1]])<k) continue;
		int l=1,r=que[i]-1,best=0,tmp=sum[0][que[i+k-1]]-sum[0][que[i]-1]+sum[2][que[i+k-1]]-sum[2][que[i]-1];
		while(l<=r) {int mid=(l+r)>>1;if(sum[0][que[i]-1]-sum[0][mid-1]>=k) {l=mid+1;best=mid;}else r=mid-1;}
		tmp+=sum[1][que[i]-1]-sum[1][best-1]+sum[2][que[i]-1]-sum[2][best-1]+sum[0][que[i]]-sum[0][best-1]-k;
		l=que[i+k-1]+1,r=n,best=n+1;
		while(l<=r) {int mid=(l+r)>>1;if(sum[2][mid]-sum[2][que[i+k-1]]>=k) {r=mid-1;best=mid;}else l=mid+1;}
		tmp+=sum[0][best]-sum[0][que[i+k-1]]+sum[1][best]-sum[1][que[i+k-1]]+sum[2][best]-sum[2][que[i+k-1]]-k;
		ans=min(ans,tmp);
	}
	if(ans>=n) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}

