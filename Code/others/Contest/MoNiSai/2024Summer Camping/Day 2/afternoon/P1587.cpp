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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MAXN = 1e9;

int n, a[N], m, l, r;

int root[N], s[N<<5], idx, ls[N<<5], rs[N<<5];
void update(int &p,int q,int l,int r,int x,int k){
	p = ++idx, s[p] = s[q] + k;
	ls[p] = ls[q], rs[p] = rs[q];
	if(l == r)	return ;
	int mid = l+r>>1;
	if(x<=mid)	update(ls[p], ls[q], l, mid, x, k);
	else	update(rs[p], rs[q], mid+1, r, x, k);
}
int query(int p,int l,int r,int left,int right){
	if(!p)	return 0;
	if(left <= l && r <= right)	return s[p];
	int mid = l+r>>1, res = 0;
	if(left <= mid)	res += query(ls[p], l, mid, left, right);
	if(right > mid)	res += query(rs[p], mid+1, r, left, right);
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i], update(root[i], root[i-1], 1, MAXN, a[i], a[i]);
	cin>>m;
//	for(int i=1;i<=n;++i)
//		cout<<query(root[i], 1, MAXN, 1, 2)<<" ";
//	cout<<endl;
	while(m--){
		cin>>l>>r;
		int ans = 1;
		while(true){
			int tmp = query(root[r], 1, MAXN, 1, ans) - query(root[l-1], 1, MAXN, 1, ans);
//			cout<<tmp<<" ";
			if(tmp >= ans)	ans = tmp+1;
			else	break; 
		}
		cout<<ans<<endl;
	}
	return 0;
}

