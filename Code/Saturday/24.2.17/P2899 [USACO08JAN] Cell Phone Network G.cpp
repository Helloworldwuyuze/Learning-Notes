#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n,x,y,f[N][3],w[N];
bool flag[N];
vector<int> g[N];

void dfs(int u,int fa){
	bool fl=false;
	int minn=0x3f3f3f3f;
	for(int v:g[u]){
		if(v==fa)	continue;
		dfs(v,u);
		if(f[v][1]>f[v][0])	f[u][0]+=f[v][0],minn=min(minn,f[v][1]-f[v][0]);
		else	fl=true, f[u][0]+=f[v][1];
		f[u][1]+=min(f[v][2],min(f[v][1],f[v][0]));
		f[u][2]+=min(f[v][0],f[v][1]);
	}
	if(!fl)	f[u][0]+=minn;
	++f[u][1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i)	cin>>x>>y, g[x].push_back(y), g[y].push_back(x);
	dfs(1,0);
	cout<<min(f[1][1],f[1][0])<<endl;
	return 0;
}
