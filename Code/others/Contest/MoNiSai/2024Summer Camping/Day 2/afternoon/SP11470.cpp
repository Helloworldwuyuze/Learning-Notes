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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, pre[N], T;

int root[N], idx, tag[N<<5], ls[N<<5], rs[N<<5], s[N<<5];

void update(int &p, int q, int l, int r, int left, int right, int k){
	if(!p)	p = ++idx;
	tag[p] = tag[q], ls[p] = ls[q], rs[p] = rs[q], s[p] = s[q];
//	cout<<"UPDATE!"<<" "<<p<<" "<<q<<" "<<l<<" "<<r<<" "<<left<<" "<<right<<" "<<k<<" "<<tag[p]<<endl;
	if(left<=l && r<=right)	return (void)(tag[p] += k);
	int mid = l+r>>1;
	if(left <= mid)	update(ls[p], ls[q], l, mid, left, right, k);
	if(right > mid)	update(rs[p], rs[q], mid+1, r, left, right, k);
	s[p] = s[ls[p]] + s[rs[p]] + tag[ls[p]]*(mid-l+1) + tag[rs[p]]*(r-mid);
}
int query(int p, int l, int r, int left, int right){
	if(!p)	return 0;	
//	cout<<"QUERY! "<<p<<" "<<l<<" "<<r<<" "<<left<<" "<<right<<" "<<tag[p]<<" "<<min(right, r)<<" "<<max(left, l)<<endl;
	if(left <= l && r <= right)	return s[p]+tag[p]*(r-l+1);
	int mid = l+r>>1, res = 0;
	if(left <= mid)	res += query(ls[p], l, mid, left, right);
	if(right > mid)	res += query(rs[p], mid+1, r, left, right);
	return res+tag[p]*(min(right, r) - max(left, l) + 1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>pre[i], pre[i] += pre[i-1];
	while(m--){
		char op; int l, r, d, t;
		cin>>op;
		switch(op){
			case 'C':{ cin>>l>>r>>d, update(root[T+1], root[T], 1, n, l, r, d); ++T; break; }
			case 'Q':{ cin>>l>>r; cout<<query(root[T], 1, n, l, r)+pre[r]-pre[l-1]<<endl; break; }
			case 'H':{ cin>>l>>r>>t; cout<<query(root[t], 1, n, l, r)+pre[r]-pre[l-1]<<endl; break; }
			case 'B':{ cin>>t; T = t; break; }
		}
	}
	return 0;
}

