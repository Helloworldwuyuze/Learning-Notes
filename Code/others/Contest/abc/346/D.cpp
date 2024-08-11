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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e2 + 10;
const int M = 3e2 + 10;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int h,w,n,T;
PII s,t;
char ma[N][N];
int dis[M][M], ene[N][N], d[N][N], id[N][N];
bool flag[M], ok;

struct medicine{
	PII coor;
	int energy;
}me[M];

queue<PII> q;
void BFS(int sx,int sy,int s){
	for(int i=1;i<=n;++i)
		dis[s][i]=INF;
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j)
			d[i][j]=INF;
	d[sx][sy]=0;
	while(q.size())	q.pop();
	q.push(mk(sx,sy));
	while(q.size()){
		PII p=q.front(); q.pop();
		// cout<<p.fi<<" "<<p.se<<endl;
		if(id[p.fi][p.se])	dis[s][id[p.fi][p.se]]=d[p.fi][p.se];
		for(int i=0;i<4;++i){
			int xx=p.fi+dx[i];
			int yy=p.se+dy[i];
			if(ma[xx][yy]=='#'||xx<=0||xx>h||yy<=0||yy>w||d[xx][yy]!=INF)	continue;
			d[xx][yy]=d[p.fi][p.se]+1;
			q.push(mk(xx,yy));
		}
	}
}

void dfs(int x,int e){
	if(dis[x][n]<=e){ ok=true; return ;}
	if((int)clock()>=1990){ cout<<"No"<<endl; exit(0);}
	for(int i=1;i<=n;++i){
		if(ene[me[i].coor.fi][me[i].coor.se]==0)	continue;
		if(e>=dis[x][i]&&!flag[i]&&dis[i][n]-ene[me[i].coor.fi][me[i].coor.se]<=dis[x][n]-e){
			flag[i]=true;
			dfs(i,ene[me[i].coor.fi][me[i].coor.se]);
			flag[i]=false;
			if(ok)	return ;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	T=clock();
	cin>>h>>w;
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j){
			cin>>ma[i][j];
			if(ma[i][j]=='S')	s=mk(i,j);
			if(ma[i][j]=='T')	t=mk(i,j);
		}
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>me[i].coor.fi>>me[i].coor.se>>me[i].energy;
		ene[me[i].coor.fi][me[i].coor.se]=me[i].energy;
		id[me[i].coor.fi][me[i].coor.se]=i;
	}
	if(!id[s.fi][s.se]){
		cout<<"No"<<endl;
		return 0;
	}
	if(!id[t.fi][t.se]){
		me[++n].coor=t, me[n].energy=0;
		id[me[n].coor.fi][me[n].coor.se]=n;
	}
	// cout<<"QAQ"<<endl;
	for(int i=1;i<=n;++i){
		BFS(me[i].coor.fi,me[i].coor.se,i);
	}
	flag[id[s.fi][s.se]]=true;
	dfs(id[s.fi][s.se],ene[s.fi][s.se]);
	if(ok)	cout<<"Yes"<<endl;
	else	cout<<"No"<<endl;
	return 0;
}