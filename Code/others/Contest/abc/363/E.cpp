#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, k, a[N][N], res;
priority_queue<PIII, vector<PIII>, greater<PIII> > q;
bool inst[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	for(int i=1;i<=n;++i){
		if(!inst[i][1])	q.push(mk(a[i][1], mk(i, 1))), inst[i][1] = true;
		if(!inst[i][m])	q.push(mk(a[i][m], mk(i, m))), inst[i][m] = true;
	}
	for(int j=2;j<m;++j){
		if(!inst[1][j])	q.push(mk(a[1][j], mk(1, j))), inst[1][j] = true;
		if(!inst[n][j])	q.push(mk(a[n][j], mk(n, j))), inst[n][j] = true;
	}
	for(int i=1;i<=k;++i){
		// cout<<"###"<<i<<"###"<<endl;
		while(q.size() && q.top().fi <= i){
			int x = q.top().se.fi, y = q.top().se.se;
			q.pop(); ++res;
			// cout<<x<<" "<<y<<endl;
			for(int j=0;j<4;++j){
				int xx = x+dx[j];
				int yy = y+dy[j];
				if(inst[xx][yy]||xx<=0||yy<=0||xx>n||yy>m)	continue;
				q.push(mk(a[xx][yy], mk(xx, yy))); inst[xx][yy] = true;
			}
		}
		cout<<n*m-res<<endl;
	}
	return 0;
}