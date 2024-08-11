#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,a[N];
struct Input{int u,v;}b[N];
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){scanf("%d%d",&b[i].u,&b[i].v);a[b[i].u]++,a[b[i].v]++;}
	ll sum=1ll*n*(n-1)*(n-2)/6,ans=0;
	for(int i=1;i<=m;i++) ans+=0ll+1ll*2*n-a[b[i].u]-a[b[i].v]-2+0ll;
	printf("%lld",sum-ans/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

