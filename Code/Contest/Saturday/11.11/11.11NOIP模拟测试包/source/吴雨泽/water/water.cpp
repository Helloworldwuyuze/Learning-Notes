#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<set>
#include<vector>

using namespace std;

const int N = 1e2 + 10;
const int M = 1e4 + 10;
#define endl '\n'
#define int long long
const int INF = 0x3f3f3f3f;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int t;
int n,m,a[N][N],minn,ans,xx,yy,hh;
bool flag=true,vis[N][N];

struct node{
	int h,x,y;
	bool operator <(const node &o) const{ return h<o.h;}
};
priority_queue<node> q;
queue<node> d;

void dfs(int x,int y,int h){
	vis[x][y]=true;
	d.push(node{h,x,y});
	for(int i=0;i<4;++i){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(vis[xx][yy])	continue;
		if(a[xx][yy]<a[x][y]){
			flag=false;
			continue;
		}
		else if(a[xx][yy]>a[x][y])	minn=min(minn,a[xx][yy]);
		else	dfs(xx,yy,h);
	}
}

signed main(){
//	freopen("water.in","r",stdin);
//	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=m+1;++j)	a[i][j]=0;
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)	cin>>a[i][j], q.push(node{-a[i][j],i,j});
		while(!q.empty()){
			node p=q.top(); q.pop();
			int x=p.x, y=p.y, h=-p.h;
			if(vis[x][y]){
				if(-q.top().h>h)	memset(vis,0,sizeof(vis));
				continue;
			}
			flag=true; minn=INF;
			dfs(x,y,h);
			if(flag)	ans+=d.size()*(minn-h);
			while(d.size()){
				node b=d.front(); d.pop();
				xx=b.x, yy=b.y, hh=b.h;
				if(flag)	q.push(node{-minn,xx,yy}), a[xx][yy]=minn;
			}
			if(-q.top().h>h)	memset(vis,0,sizeof(vis)); 
		}
		cout<<ans<<endl;
	}
	return 0;
}
