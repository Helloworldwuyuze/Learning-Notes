#include<bits/stdc++.h>
#define pr printf("\n")
#define pp printf(" ")
#define INF 0x3f3f3f3f
using namespace std;//10 2 OJIJOIOIIJ
typedef long long ll;
const ll N=5e4+5;
struct node{
	ll ver,nxt,edge;
}a[N],b[N];
ll heada[N],tota,headb[N],totb;
void adda(ll x,ll y,ll z){
	a[++tota].ver=y;
	a[tota].edge=z;
	a[tota].nxt=heada[x];
	heada[x]=tota;
}
void addb(ll x,ll y,ll z){
	b[++totb].ver=y;
	b[totb].edge=z;
	b[totb].nxt=headb[x];
	headb[x]=totb;
}
ll n,m,minn=INF;
pair<ll,ll> pi[N];
int t[N],can[N],cnt;
void dfs(ll root,ll flagu,ll flagv,ll fa,ll d){
	t[root]=1;
	
	if(d==1){
		for(ll i=heada[root];i;i=a[i].nxt){
			ll v=a[i].ver;
			if((root==flagu&&v==flagv)||(root==flagv&&v==flagu)||v==fa) continue;
			dfs(v,flagu,flagv,root,1);
	//		can[++cnt]=v;
		}
		if(flagu==root) dfs(root,flagu,flagv,-1,2);
	}
	else{
//		printf("114 %d\n",t[6]);
		for(ll i=heada[root];i;i=a[i].nxt){
			ll ne=a[i].ver;
			if(ne!=flagv)
			for(ll j=headb[ne];j;j=b[j].nxt){
				ll v=b[j].ver;
//				cout<<v<<endl;
				if(!t[v]) minn=min(minn,b[j].edge);
			}
			if((root==flagu&&ne==flagv)||(root==flagv&&ne==flagu)||ne==fa) continue;
			
			dfs(ne,flagu,flagv,root,2);
		}
	}
}
int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<n;i++){
		ll u,v;
		scanf("%lld %lld",&u,&v);
		pi[i].first=u,pi[i].second=v;
		adda(u,v,0);
		adda(v,u,0);
	}
	for(ll i=1;i<=m;i++){
		ll u,v,z;
		scanf("%lld %lld %lld",&u,&v,&z);
		addb(u,v,z);
		addb(v,u,z);
	}
	for(ll i=1;i<n;i++){
		memset(t,0,sizeof(t));
		memset(can,0,sizeof(can));
		cnt=0;
		minn=INF;
		if(pi[i].first>pi[i].second) swap(pi[i].first,pi[i].second);
		dfs(pi[i].first,pi[i].first,pi[i].second,-1,1);
		printf("%lld\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6 3 
1 2 
1 3 
4 1 
4 5 
6 5 
2 3 7 
3 6 8 
6 4 5
*/

