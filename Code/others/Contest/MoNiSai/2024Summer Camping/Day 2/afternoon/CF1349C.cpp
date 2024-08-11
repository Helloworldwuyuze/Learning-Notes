#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>

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
#define endl '\n'

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, t, x, y, p;
char c[N][N];
int b[N][N];
queue<PII> q;

void bfs(){
	while(q.size()){
		int x = q.front().fi, y = q.front().se;
		q.pop();
		for(int i=0;i<4;++i){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx<=0 || xx>n || yy<=0 || yy>m || b[xx][yy] != -1)	continue;
			b[xx][yy] = b[x][y] + 1, q.push(mk(xx, yy));
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>t;
	memset(b, -1, sizeof(b));
	for(int i=1;i<=n;++i)
		cin>>(c[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=0;k<4;++k){
				int x = i+dx[k], y = j+dy[k];
				if(x<=0 || x>n || y<=0 || y>m)	continue;
				if(c[x][y] == c[i][j]){
					b[i][j] = 0, q.push(mk(i, j));
					break;
				}
			}
	bfs();
//	for(int i=1;i<=n;++i,cout<<endl)
//		for(int j=1;j<=m;++j)
//			cout<<b[i][j]<<" ";
	while(t--){
		cin>>x>>y>>p;
//		cout<<c[x][y]<<" "<<b[x][y]<<" "<<p<<endl;
		if(p>=b[x][y] && b[x][y] != -1)	cout<<(char)(c[x][y]^(p-b[x][y]&1))<<endl;
		else	cout<<c[x][y]<<endl;
	}
	return 0;
}

