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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 2e5 + 10;

int a[N], n, q, pre[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)   cin>>a[i];
	for(int i=1;i<=n;++i){
		int s = 0;
		while(a[i]%2==0)	++s, a[i]/=2;
		pre[i] = pre[i-1] + (1<<s);
	}
	cin>>q;
	while(q--){
		int x; cin>>x;
		int l = 1, r = n;
		while(l<r){
			int mid = l+r>>1;
			if(pre[mid]>=x)	r=mid;
			else	l = mid+1;
		}
		cout<<a[l]<<endl;
	}
	return 0;
}