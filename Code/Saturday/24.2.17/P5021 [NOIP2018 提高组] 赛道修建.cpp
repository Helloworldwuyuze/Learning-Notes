#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int N = 5e4 + 10;
const int M = 5e4;
const int MOD = 1032992941;
typedef pair<int,int> PII;

int n,m,x,y,z;
vector<PII> v[N];
int l,r,id,d[N];
multiset<int> s[N];

void dfs1(int x,int fa){
	for(PII y:v[x]){
		if(y.fi==fa)	continue;
		d[y.fi]=d[x]+y.se;
		dfs(y.fi,x);
	}
	if(d[x]>r)	r=d[x], id=x;
}

int dfs(int x,int fa){
	s[x].clear();
	for(PII y:v[x]){
		
	}
}

bool check(int x){
	ans=0;
	dfs(1,0);
	return ans>=m;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;++i)	cin>>x>>y>>z, g[x].pb(mk(y,z)), g[y].pb(mk(x,z));
	dfs1(1,0); r=0; dfs2(id,0);
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))	l=mid;
		else	r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
