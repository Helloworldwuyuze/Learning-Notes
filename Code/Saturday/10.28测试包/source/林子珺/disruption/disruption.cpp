#include <bits/stdc++.h>
using namespace std;

const int N=5e4+10;
int n,m;
struct edge{
	int v,nxt;
	int mdis;
}e[N*2];
int head[N],cnt=2;
void add(int u,int v){
	e[cnt].v=v;
	e[cnt].mdis=0x3f3f3f3f;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}

int p,q,r;
bool dfs(int u,int fa){
	if(u==q){
		return 1;
	}
	for(int i=head[u];i;i=e[i].nxt){
		if(e[i].v==fa)continue;
		bool re=dfs(e[i].v,u);
		if(re){
			e[i].mdis=min(e[i].mdis,r);
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("disruption.in","r",stdin);
	freopen("disruption.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int p,q;
		cin>>p>>q;
		add(p,q),add(q,p);
	}
	for(int i=1;i<=m;i++){
		cin>>p>>q>>r;
		dfs(p,0);
	}
	for(int i=2;i<cnt;i+=2){
		cout<<min(e[i].mdis,e[i+1].mdis)<<endl;
	}
	return 0;
}
