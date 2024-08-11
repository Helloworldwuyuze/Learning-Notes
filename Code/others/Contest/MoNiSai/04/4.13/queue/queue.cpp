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

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 998244353;

int t[10], a[N], n, op, k, m;
string s;

signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    	cin>>a[i], t[a[i]]++;
    while(m--){
    	cin>>op;
    	if(op==3){
    		cin>>s>>k;
    		int ans=1;
    		int len=s.size();
    		for(int i=0;i<len;++i)
    			ans=ans*(t[s[i]-'0'])%MOD;
    		cout<<ans<<endl;
		}else if(op==1)	cin>>k>>k;
		else	cin>>k;
	}
	return 0;
}

