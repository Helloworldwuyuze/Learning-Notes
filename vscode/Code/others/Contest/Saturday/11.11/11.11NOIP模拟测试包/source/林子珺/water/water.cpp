#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=110,H=1e4+10;
int n,m;
int h[N][N];

const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};

int cur;
bool vis[N][N];
int bz=0;
int dfs(int x,int y){
	if(x==n||x==1||y==m||y==1)bz=1;
	vis[x][y]=1;
	int ans=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&h[nx][ny]<cur){
			ans+=dfs(nx,ny);
		}
	}
	return ans;
}

signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		int mxh=0,mnh=0x3f3f3f3f3f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>h[i][j],mxh=max(mxh,h[i][j]),mnh=min(mnh,h[i][j]);
		for(int i=mnh;i<=mxh;i++){
			cur=i;
			memset(vis,0,sizeof(vis));
			int tmp=0;
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					if(!vis[x][y]&&cur>h[x][y]){
						bz=0;
						int re=dfs(x,y);
						if(!bz){
							ans+=re;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
