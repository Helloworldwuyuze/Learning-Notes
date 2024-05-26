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

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e5 + 10;

int n,x,y,xx,yy;
int w[N][N];
const int dx[]={0,1,0,-1,1,1,-1,-1};
const int dy[]={1,0,-1,0,-1,1,-1,1};
bool vis[N][N];
vector<bool> maxx, minn;
int cnt=-1, r=0, v=0;

void dfs(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<8;++i){
        xx=x+dx[i], yy=y+dy[i];
        if(xx<=0||xx>n||yy<=0||yy>n)    continue;
        if(w[xx][yy]>w[x][y])   maxx[cnt]=true;
        if(w[xx][yy]<w[x][y])   minn[cnt]=true;
        if(vis[xx][yy]) continue;
        if(w[xx][yy]==w[x][y])  dfs(xx,yy);
    }
}

queue<PII> q;
void bfs(int s,int t){
    q.push(mk(s,t));
    vis[s][t]=true;
    while(q.size()){
        int x=q.front().fi, y=q.front().se; q.pop();
        for(int i=0;i<8;++i){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<=0||xx>n||yy<=0||yy>n)    continue;
            if(w[xx][yy]>w[x][y])   maxx[cnt]=true;
            else if(w[xx][yy]<w[x][y])  minn[cnt]=true;
            if(w[xx][yy]==w[x][y]&&!vis[xx][yy])    q.push(mk(xx,yy)), vis[xx][yy]=true;
        }
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    // memset(maxx,-1,sizeof(maxx)), memset(minn,-1,sizeof(minn));
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>w[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(!vis[i][j])  ++cnt, maxx.pb(false), minn.pb(false), bfs(i,j);
    for(int i=0;i<=cnt;++i)
        if(maxx[i]&&minn[i])  continue;
        else if(!maxx[i]&&!minn[i]) ++v, ++r;
        else if(!maxx[i])   r++;
        else    v++;
    cout<<r<<' '<<v<<endl;
	return 0;
}

