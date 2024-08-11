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

int T, n, m;
int blk[N], l[N], r[N], a[N], b[N], nn, x, y, z, cnt;

void init(){
	nn = 1250;
	for(int i=1;i<=n;++i){
		blk[i] = (i-1)/nn+1;
		l[blk[i]] = (blk[i]-1)*nn+1;
		r[blk[i]] = min(blk[i]*nn, n);
		b[i] = a[i];
	}
	cnt = blk[n];
	for(int i=1;i<=cnt;++i)
		sort(a+l[i], a+1+r[i]);
}
int query(int left,int right,int x){
	int bl = blk[left], br = blk[right], ans = 0;
	if(bl == br){
		for(int i=left; i<=right; ++i)
			ans += b[i] <= x;
		return ans;
	}
	for(int i=left;i<=r[bl];++i)
		ans += b[i] <= x;
	for(int i=l[br];i<=right;++i)
		ans += b[i] <= x;
	for(int i=bl+1; i<br; ++i){
		if(a[r[i]]<=x){ ans += (r[i]-l[i]+1); continue;}
		int lo = upper_bound(a+l[i], a+1+r[i], x) - a;
		ans += lo - l[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	for(int t = 1; t <= T; ++t){
		cout<<"Case "<<t<<":"<<endl;
		cin>>n>>m;
		for(int i=1;i<=n;++i)	cin>>a[i];
		init();
		for(int i=1;i<=m;++i)
			cin>>x>>y>>z, cout<<query(x+1,y+1,z)<<endl;
	}
	return 0;
}