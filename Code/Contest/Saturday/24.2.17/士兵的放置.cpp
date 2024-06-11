#include<bits/stdc++.h>

using namespace std;

#define int unsigned long long
const int N = 5e5 + 10;
const int M = 2e5 + 10;
const int MOD = 1032992941;

int n,x,y,f[N][3],F[N][3];
vector<int> g[N];

int mod(int x){ return (x+MOD)%MOD;}
// 0 ¸¸Ç× 1 ×Ô¼º 2 ¶ù×Ó 

void dfs(int u,int fa){
	f[u][1]=F[u][0]=F[u][1]=F[u][2]=1; f[u][2]=N;
	for(int v:g[u]){
		if(v==fa)	continue;
		dfs(v,u);
		int tmp=min(f[v][0],min(f[v][1],f[v][2])), t=0;
		if(f[v][0]==tmp)	t+=F[v][0];
		if(f[v][1]==tmp)	t+=F[v][1];
		if(f[v][2]==tmp)	t+=F[v][2];
		f[u][1]+=tmp, F[u][1]=mod(mod(F[u][1])*mod(t));
		
		tmp=min(f[u][2]+min(f[v][1],f[v][2]),f[u][0]+f[v][1]), t=0;
		if(f[u][2]+f[v][1]==tmp)	t+=F[v][1];
		if(f[u][2]+f[v][2]==tmp)	t+=F[v][2];
		F[u][2]=mod(mod(F[u][2])*mod(t)); f[u][2]=tmp;
		if(f[u][0]+f[v][1]==tmp)	F[u][2]=mod(mod(F[u][2])+mod(mod(F[u][0])*mod(F[v][1])));
		
		f[u][0]+=f[v][2];
		F[u][0]=mod(mod(F[u][0])*mod(F[v][2]));
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i)	cin>>x>>y, g[x].push_back(y), g[y].push_back(x);
	dfs(1,0);
	if(f[1][1]<f[1][2])	cout<<f[1][1]<<endl<<F[1][1]<<endl;
	if(f[1][1]>f[1][2])	cout<<f[1][2]<<endl<<F[1][2]<<endl;
	if(f[1][1]==f[1][2])	cout<<f[1][1]<<endl<<mod(F[1][1]+F[1][2])<<endl;	
	return 0;
}
/*
6
1 2
1 3
1 5
1 4
5 6
*/
