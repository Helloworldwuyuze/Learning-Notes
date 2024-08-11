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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MAXH = 30;

int n, a[N], pre[N], suf[N], ans;
PII b[N];

int t[N<<5][2], w[N<<5], idx, root[N];
void update(int p,int q,int x){
	p = root[p] = ++idx, q = root[q];
	for(int i=MAXH;i>=0;--i){
		t[p][(x>>i)&1] = ++idx, t[p][((x>>i)&1)^1] = t[q][((x>>i)&1)^1];
		w[p] = w[q] + 1;
		p = t[p][(x>>i)&1], q = t[q][(x>>i)&1];
	}
	w[p] = w[q] + 1;
}
int query(int l,int r,int x){
	int ans = 0, p = root[r], q = root[l];
	for(int i=MAXH;i>=0;--i){
		// cout<<p<<" "<<q<<" "<<w[t[p][((x>>i)&1)^1]]<<" "<<w[t[q][((x>>i)&1)^1]]<<endl;
		if(w[t[p][((x>>i)&1)^1]] - w[t[q][((x>>i)&1)^1]] > 0)	ans += (1<<i), p = t[p][((x>>i)&1)^1], q = t[q][((x>>i)&1)^1];
		else	p = t[p][(x>>i)&1], q = t[q][(x>>i)&1];
	}
	// cout<<l<<" "<<r<<" "<<x<<" "<<ans<<endl;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	int fir = 0, lst = n+1;
	pre[lst] = n, suf[fir] = 1;
	for(int i=1;i<=n;++i)	cin>>a[i], update(i, i-1, a[i]), pre[i] = i-1, suf[i] = i+1, b[i] = mk(a[i], i);
	sort(b+1, b+1+n);
	for(int i=1;i<=n;++i){
		int l = pre[b[i].se], r = suf[b[i].se];
		suf[l] = r, pre[r] = l;
		if(l != fir)	ans = max(ans, query(pre[l], r-1, a[b[i].se]));
		if(r != lst)	ans = max(ans, query(l, suf[r]-1, a[b[i].se]));
	}
	cout<<ans<<endl;
	// for(int i=1;i<=idx;++i)
	// 	cout<<i<<" "<<t[i][0]<<" "<<t[i][1]<<" "<<w[i]<<endl;
	
	return 0;
}	