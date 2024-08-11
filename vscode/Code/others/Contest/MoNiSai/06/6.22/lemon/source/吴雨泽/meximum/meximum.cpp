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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 3e3 + 10;
const int M = 3e5 + 12;

int sum[M<<2];
void push_up(int p){ sum[p]=sum[p<<1]+sum[p<<1|1];}
void update(int p,int l,int r,int x,int k){
	if(l==r)    return (void)(sum[p]=k);
	int mid = l+r>>1;
	if(x<=mid)	update(p<<1, l, mid, x, k);
	else	update(p<<1|1, mid+1, r, x, k);
	push_up(p);
}
int query(int p,int l,int r){
	// cout<<"QUERY::"<<p<<" "<<l<<" "<<r<<endl;
	if(l==r)	return l;
	int mid = l+r>>1;
	if(sum[p<<1]==mid-l+1)	return query(p<<1|1, mid+1, r);
	else	return query(p<<1, l, mid);
}
int tag[M];
int n, a[N], ans;

void print(){
	for(int i=1;i<=10;++i)
		cout<<i<<" "<<sum[i]<<endl;
	for(int i=1;i<=10;++i)
		cout<<tag[i]<<" ";
	cout<<endl<<endl;
}

signed main(){
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i], ++a[i];
	int l = 1, r = 0;
	for(int len = 1; len<=n; ++len){
//		cerr<<len<<" "<<l<<" "<<r<<endl;
		if(len&1){
			if(++tag[a[++r]]==1)	update(1, 1, M-10, a[r], 1);
			ans += query(1, 1, M-10);
//			cout<<l<<" "<<r<<endl;
//			cout<<ans<<endl;
//			 print();
			while(r<n){
				if(++tag[a[++r]]==1)	update(1, 1, M-10, a[r], 1);
				if(--tag[a[l]]==0)	update(1, 1, M-10, a[l], 0); ++l;
//				cerr<<l<<" "<<r<<endl;
				ans += query(1, 1, M-10);
//				 cout<<ans<<endl;
				// print();
			}
		}else{
			if(++tag[a[--l]]==1)	update(1, 1, M-10, a[l], 1);
			ans += query(1, 1, M-10);
//			 cout<<l<<" "<<r<<endl;
//			 cout<<ans<<endl;
			// print();
			while(l>1){
				if(++tag[a[--l]]==1)	update(1, 1, M-10, a[l], 1);
				if(--tag[a[r]]==0)	update(1, 1, M-10, a[r], 0); --r; 
//				 cout<<l<<" "<<r<<endl;
				ans += query(1, 1, M-10);
//				 cout<<ans<<endl;
				// print();
			}
		}
//		cerr<<len<<" "<<l<<" "<<r<<endl;
	}
	cout<<ans-n*(n+1)/2<<endl;
	return 0;
}
