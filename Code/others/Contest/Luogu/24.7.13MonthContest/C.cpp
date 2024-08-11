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
const int N = 2e6 + 10;
const int M = 1e6 + 10;

int l[N], r[N], type[N], n, m, lans[30], rans[30], a[N];

set<int> s[30], sans[10];

int solve(int p,int l,int r){
	int res;
	if(l == r){
		s[p].insert(res = a[l]);
		return res;
	}
	int mid = l+r>>1;
	int ls = solve(p<<1, l, mid), rs = solve(p<<1|1, mid+1, r);
	if(type[p] == 1)	res = max(ls, rs);
	else	res = min(ls, rs);
	s[p].insert(res);
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(lans, 0x3f, sizeof(lans));
	cin>>n>>m;
	for(int i=1;i<=(1<<n)-1;++i)	cin>>type[i];
	if(n<=3){
		++n;
		for(int i=1;i<=(1<<n-1);++i)
			a[i] = i;
		do{
			solve(1, 1, 1<<n-1);
		}while(next_permutation(a+1, a+(1<<n-1)+1));
		for(int dep = n; dep; --dep)
			for(int i=(1<<dep-1);i<=(1<<dep)-1;++i)
				for(int x:s[i])	sans[n-dep+1].insert(x);
		// for(int i=1;i<=n;++i){
		// 	for(int x:sans[i])	cout<<x<<" ";
		// 	cout<<endl;
		// }
		while(m--){
			int x, y; cin>>x>>y;
			if(sans[y].find(x) != sans[y].end())	cout<<"Yes"<<endl;
			else	cout<<"No"<<endl;
		}
		return 0;
	}
	for(int i=(1<<n-1);i<=(1<<n)-1;++i)
		l[i<<1] = l[i<<1|1] = 1, r[i<<1] = r[i<<1|1] = (1<<n);
	for(int dep = n; dep; --dep){
		for(int i=(1<<dep-1);i<=(1<<dep)-1;++i){
			if(type[i] == 1){
				if(l[i<<1] == l[i<<1|1])	l[i] = l[i<<1] + 1;
				else	l[i] = max(l[i<<1], l[i<<1|1]);
				r[i] = max(r[i<<1], r[i<<1|1]);
			}else{
				if(r[i<<1] == r[i<<1|1])	r[i] = r[i<<1] - 1;
				else	r[i] = min(r[i<<1], r[i<<1|1]);
				l[i] = min(l[i<<1], l[i<<1|1]);
			}
			// cout<<dep<<" "<<i<<" "<<l[i]<<" "<<r[i]<<" "<<lans[n-dep+2]<<" "<<rans[n-dep+2]<<endl;
			lans[n-dep+2] = min(lans[n-dep+2], l[i]);
			rans[n-dep+2] = max(rans[n-dep+2], r[i]);
		}
	}
	// for(int i=1;i<=(1<<n)<<1;++i)	cout<<l[i]<<" "<<r[i]<<endl;
	lans[1] = 1, rans[1] = (1<<n);
	// for(int i=1;i<=n+1;++i)	cout<<lans[i]<<" "<<rans[i]<<endl;
	while(m--){
		int x, y; cin>>x>>y;
		if(lans[y] <= x && x <= rans[y])	cout<<"Yes"<<endl;
		else	cout<<"No"<<endl;
	}
	return 0;
}