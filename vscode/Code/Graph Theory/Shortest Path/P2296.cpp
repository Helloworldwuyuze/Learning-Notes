#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e4 + 10;
const int M = 2e5 + 10;

vector<int> g[N],r[N];
int n,m,x,y,s,t;
int dis[N],redis[N],ok[N];
bool vis[N];

void bfs(int d[],int st,vector<int> v[],int chk[]={0}){
	for(int i=1;i<=n;++i)	d[i]=INF;
	if(chk[s]==INF)	return ;
	d[st]=0;
	queue<int> q;
	q.push(st);
	while(q.size()){
		int x=q.front(); q.pop();
		for(int y:v[x])
			if(d[y]==INF&&chk[y]!=INF)	d[y]=d[x]+1, q.push(y);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)	cin>>x>>y, g[x].pb(y), r[y].pb(x);
	cin>>s>>t;
	bfs(redis,t,r,dis);
	for(int i=1;i<=n;++i)	ok[i]=redis[i];
	for(int i=1;i<=n;++i)
		for(int j:r[i])	if(redis[i]==INF)	ok[j]=INF;
	bfs(dis,s,g,ok);
	if(dis[t]==INF)	cout<<-1<<endl;
	else	cout<<dis[t]<<endl;
	return 0;
}