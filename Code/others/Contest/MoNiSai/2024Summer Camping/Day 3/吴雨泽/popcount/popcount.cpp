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
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n, a[N], q;
int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i))	b[i] += k;
}
int query(int x){
	int ans = 0;
	for(int i=x;i;i-=lowbit(i))	ans += b[i];
	return ans;
}
#undef lowbit

int popcnt(int x){
	int sum = 0;
	while(x)	sum += (x&1), x>>=1;
	return sum;
}

signed main(){
	freopen("popcount.in","r",stdin);
	freopen("popcount.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)	cin>>a[i], update(i, a[i]), update(i+1, -a[i]);
	if(n<=5000){
		while(q--){
			int op, l, r, k;
			cin>>op;
			if(op == 1){
				cin>>l>>r>>k;
				for(int i=l;i<=r;++i)	a[i] += k;
			}else if(op == 2){
				cin>>l>>r;
				for(int i=l;i<=r;++i)	a[i] = popcnt(a[i]);
			}else	cin>>k, cout<<a[k]<<endl;
		}
	}else{
		while(q--){
			int op, l, r, k;
			cin>>op;
			if(op == 1){
				cin>>l>>r>>k;
				update(r+1, -k), update(l, k);
			}else	cin>>k, cout<<query(k)<<endl;
		}
	}
	return 0;
}

