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
const int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MAXN = (1ll<<31)-1;

int n, a[N], m, l, r, minn, b[N], cnt;
int ls[N<<5], rs[N<<5], sum[N<<5], idx, root[N];
void update(int &p,int q,int l,int r,int x,int k){
	p = ++idx;
	ls[p] = ls[q], rs[p] = rs[q], sum[p] = sum[q];
	if(l == r)	return (void)(++sum[p]);
	int mid = l+r>>1;
	if(x <= mid)	update(ls[p], ls[q], l, mid, x, k);
	else	update(rs[p], rs[q], mid+1, r, x, k);
	sum[p] = sum[ls[p]] + sum[rs[p]];
}
int kth(int p,int q,int l,int r,int k){
//	cout<<"KTH! "<<p<<" "<<q<<' '<<l<<" "<<r<<" "<<k<<" "<<sum[p]<<" "<<sum[q]<<endl; 
	if(sum[p] - sum[q] < k)	return -1;
	if(l == r)	return l;
	int mid = l+r>>1;
	if(sum[ls[p]]-sum[ls[q]] >= k)	return kth(ls[p], ls[q], l, mid, k);
	else	return kth(rs[p], rs[q], mid+1, r, k - sum[ls[p]] + sum[ls[q]]);
}

signed main(){
//	freopen("electric.in","r",stdin);
//	freopen("electric.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	int T; cin>>T;
//	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>a[i], update(root[i], root[i-1], 0, MAXN, a[i], 1);
		cin>>m;
		while(m--){
			cin>>l>>r;
			minn = INF, cnt = 0;
			for(int i=1;i<=32;++i){
				int tmp = kth(root[r], root[l-1], 0, MAXN, i);
				if(tmp == -1)	break;
				b[++cnt] = tmp;
			}
			for(int i=1;i<=cnt;++i)
				for(int j=i+1;j<=cnt;++j)
					minn = min(minn, b[i]|b[j]);
			cout<<minn<<endl;
		}
//		for(int i=1;i<=idx;++i)	cout<<i<<" "<<ls[i]<<" "<<rs[i]<<" "<<sum[i]<<endl;
//		for(int i=1;i<=n;++i)	root[i] = 0;
//		for(int i=1;i<=idx;++i)	ls[i] = rs[i] = sum[i] = 0;
//		idx = 0;
//	}
	return 0;
}
/*
1
5
6 1 3 2 1
4
1 2
2 3
2 4
2 5
*/
