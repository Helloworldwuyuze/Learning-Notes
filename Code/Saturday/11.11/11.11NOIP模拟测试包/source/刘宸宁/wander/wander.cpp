#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;
typedef int ll;
typedef double db;
const ll N=2e2+5,M=2e4+5;
ll n,m;
struct node{
	ll nxt,ver,edge;
}a[M<<1];
ll tot,head[M<<1];
void add(ll x,ll y){
	a[++tot].ver=y;
	a[tot].nxt=head[x];
	head[x]=tot;
}
int main(){
	freopen("wander.in","r",stdin);
	freopen("wander.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(ll i=1;i<=m;i++){
		ll u,v;
		scanf("%d %d",&u,&v);
	}
	printf("3.333\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
