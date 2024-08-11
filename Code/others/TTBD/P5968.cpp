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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e9;

int n, x;
map<int, PII> ma;
int b[N], cnt, a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	a[1] = 1, a[2] = 2;
	ma[1] = mk(2, 1);
	for(int i=3;a[i-1] <= M || !(i%2);++i){
		if(i%2)	a[i] = a[i-1]<<1;
		else
			for(int j=1;;++j)
				if(!ma.count(j)){ a[i] = a[i-1] + j; break;}
		for(int j=1;j<i;++j)
			ma[a[i]-a[j]] = mk(i, j);
		// cout<<i<<" ";
	}
	// cout<<endl;
	// for(int i=1;i<=56;++i)	cout<<a[i]<<" ";
	// cout<<endl;
	for(map<int,PII>::iterator it = ma.begin(); it!=ma.end(); ++it)
		b[++cnt] = it->fi;
	while(n--){
		cin>>x;
		if(ma.count(x))	cout<<ma[x].fi<<" "<<ma[x].se<<endl;
		else{
			int y = lower_bound(b+1, b+1+cnt, x) - b - 1;
			cout<<56+(x-y)*2<<" "<<56+(x-y)*2-1<<endl;
		}
	}
	return 0;
}