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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int len, m, l, r, op, border[N];
string s, t, st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>len>>m>>s;
	for(int i=1;i<=m;++i){
		cin>>op>>l>>r>>t;
		if(op == 1)
			for(int i=l-1;i<r;++i)	s[i] = t[i-l+1];
		else{
			st = t+"#"+s;
			int n = st.size(), ts = t.size();
//			cerr<<st<<endl;
			border[0] = 0;
			for(int i=1;i<n;++i){
				int j = border[i-1];
				while(st[i] != st[j] && j)	j = border[j-1];
				border[i] = j+(st[j]==st[i]);
//				cerr<<border[i]<<" ";
			}
//			cout<<endl;
			int ans = 0;
			for(int i=ts+1;i<n;++i)
				if(border[i] == ts && i-ts-ts+1>=l && i-ts<=r)	++ans;
			cout<<ans<<endl;
		}
	}
	return 0;
}

