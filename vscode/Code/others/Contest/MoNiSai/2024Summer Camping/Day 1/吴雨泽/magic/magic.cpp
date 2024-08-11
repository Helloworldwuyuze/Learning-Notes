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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int x, y, f[N], n, m, k;

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)	f[i] = INF;
	f[k] = 0;
	for(int i=1;i<=m;++i){
		cin>>x>>y;
		int tmpx = f[x];
		if(f[x] >= f[y]-1)	f[x] = f[y]-1;
		if(f[y] >= tmpx-1)	f[y] = tmpx-1;
		++f[x], ++f[y];
	}
	for(int i=1;i<=n;++i)
		if(f[i] >= INF/2)	cout<<-1<<" ";
		else		cout<<f[i]<<" ";
	cout<<endl;
	return 0;
}

