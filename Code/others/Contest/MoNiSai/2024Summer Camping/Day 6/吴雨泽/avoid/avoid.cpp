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

int T, n, s;
int a[N];
set<int> g[10];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("avoid.in","r",stdin);
	freopen("avoid.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>s;
		for(int i=1;i<=n;++i)	cin>>a[i];
		int ans = 0;
		if(s == 2){
			for(int i=1;i<=n;++i)	ans += a[i] == 3;
			cout<<max(ans-1, 0)<<endl;
			for(int i=1;i<=n;++i)	cout<<i<<" ";
			cout<<endl;
		}else if(s == 3){
			int s[5];
			s[2] = s[3] = s[4] = 0;
			for(int i=1;i<=n;++i)
				++s[a[i]], g[a[i]].insert(i);
			if(s[2] > s[4])	cout<<s[2]-s[4]-1<<endl;
			else if(s[2] == s[4])	cout<<0<<endl;
			else	cout<<(s[4]-s[2])/2-(bool)((s[4]-s[2])%2==0)<<endl;
			for(int x:g[3])	cout<<x<<" ";
			while(g[2].size() && g[4].size())
				cout<<(*g[4].begin())<<" "<<(*g[2].begin())<<" ", g[2].erase(g[2].begin()), g[4].erase(g[4].begin());
			while(g[2].size())	cout<<(*g[2].begin())<<" ", g[2].erase(g[2].begin());
			while(g[4].size())	cout<<(*g[4].begin())<<" ", g[4].erase(g[4].begin());
			g[3].clear();
			cout<<endl;
		}
	}
	return 0;
}

