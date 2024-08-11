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
const int N = 1e6 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;

long long T, d, idx, root, lbt, f[N<<1], g[N<<1];
char s[N];
struct node{
	long long ls, rs, d;
	bool is;
}pnt[N<<1];

void dfs(int &p,int x){
	if(s[x] == '0' && x == d)	return ;
	if(!p)	p = ++idx;
	if(x == lbt && s[x] == '0'){
		pnt[p] = {0, 0, d-x, true};
		return ;
	}
	if(s[x] == '1'){
		s[x] = '0';
		pnt[p] = {0, 0, d-x+1, true};
		return ;
	}
	if(x == d)	return ;
	if(s[x+1] == '1')
		dfs(pnt[p].ls, x+1), dfs(pnt[p].rs, x+1);
	else{
		dfs(pnt[p].ls, x+1);
		pnt[p].rs = ++idx, pnt[pnt[p].rs] = {0, 0, d-x-1, true};
	}
	pnt[p].d = max(max(pnt[pnt[p].ls].d, pnt[pnt[p].rs].d)+1, pnt[p].d);
	pnt[p].is = (pnt[pnt[p].ls].d == pnt[pnt[p].rs].d) && pnt[pnt[p].ls].is && pnt[pnt[p].rs].is;
}

signed main(){
//	freopen("oldqueen.in","r",stdin);
//	freopen("oldqueen.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	f[1] = 1;
	for(int i=2;i<=1000000;++i)
		f[i] = 1ll*(f[i-1]+1)*(f[i-1]+1)%MOD;
	while(T--){
		cin>>d;
		cin>>(s+1);
		for(int i=d;i;--i)
			if(s[i] == '1'){
				lbt = i;
				break;
			}
		dfs(root, 1);
//		for(int i=1;i<=idx;++i)
//			cout<<i<<" "<<pnt[i].ls<<" "<<pnt[i].rs<<" "<<pnt[i].d<<" "<<pnt[i].is<<endl;
		for(int i=idx;i;--i){
			if(pnt[i].is)	g[i] = f[pnt[i].d];
			else	g[i] = 1ll*(g[pnt[i].ls]+1)*(g[pnt[i].rs]+1)%MOD;
//			cout<<i<<" "<<g[i]<<endl;
		}
		cout<<g[root]<<endl;
		for(int i=root;i<=idx;++i)
			pnt[i] = {0, 0, 0, false};
		idx = root = 0;
	}
	return 0;
}
/*
3
2
10
3
100
3
010
*/
