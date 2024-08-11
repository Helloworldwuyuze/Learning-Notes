#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int INF = 0x3f3f3f3f;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
typedef pair<int,int> PII;

int Next[M<<2], ver[M<<2], w[M<<2], head[N], tot=-1;
void add(int x,int y,int z){
	ver[++tot] = y;
	w[tot] = z;
	Next[tot] = head[x];
	head[x] = tot;
}
vector<int> g[N];
int n, m, s, t, x[M], y[M], ans;
bool col[N], vis[N];

void colored(int x,int fa){
	col[x] = !col[fa];
	vis[x] = true;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(!vis[y])	colored(y, x);
	}
}

int dep[N], cur[N];
bool bfs(){
	queue<int> q;
	for(int i=s;i<=t;++i)	dep[i] = INF;
	q.push(s), dep[s] = 0;
	while(q.size()){
		int x = q.front(); q.pop();
		cur[x] = head[x];
		if(x==t)	return true;
		for(int i=head[x];~i;i=Next[i]){
			int y=ver[i], z=w[i];
			if(z && dep[y] == INF){
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
	return false;
}
int dfs(int x,int flow){
	if(x==t || !flow)	return flow;
	int maxflow=0, f;
	for(int &i=cur[x];~i;i=Next[i]){
		int y=ver[i], z=w[i];
		if(dep[y] == dep[x] + 1 && (f=dfs(y, min(flow, z)))){
			maxflow += f, flow -= f;
			w[i] -= f, w[i^1] += f;
			if(flow == 0)	return maxflow;
		}
	}
	return maxflow;
}

int main(){
	freopen("c18.in","r",stdin);
	freopen("card18.in","w",stdout);
	memset(head,-1,sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x[i]>>y[i], g[x[i]].pb(y[i]), g[y[i]].pb(x[i]);
	colored(1, 0);
	for(int x=1;x<=n;++x)
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			if(col[x] != col[y] && x<y){
				int xx = x, yy = y;
				if(col[xx])	swap(xx,yy);
				add(xx, yy, 1), add(yy, xx, 0);
			}
		}
	s = 0, t = n + 1;
	for(int i=1;i<=n;++i)
		if(col[i])	add(i, t, 1), add(t, i, 0);
		else	add(s, i, 1), add(i, s, 0);
//	for(int i=s;i<=t;++i,cout<<endl)
//		for(int j=head[i];~j;j=Next[j])
//			cout<<ver[j]<<" "<<w[j]<<endl;
	while(bfs())	ans += dfs(s, INF);
	cout<<n<<" "<<m<<" "<<ans<<endl;
	for(int i=1;i<=m;++i)
		cout<<x[i]<<" "<<y[i]<<endl;
	return 0;
}
