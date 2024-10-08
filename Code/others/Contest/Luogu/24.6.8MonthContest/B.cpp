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

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e3 + 10;
const int M = 1e6 + 10;

string s;
int ans=0, n;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>s; n=s.size();
	for(int i=0;i<n;++i)
		if(s[i]=='1'||s[i]=='2'||s[i]=='4'||s[i]=='8')	++ans, s[i]='9';
	// cout<<ans<<endl;
	for(int i=0;i+4<n;++i)
		if(s[i]=='6'&&s[i+1]=='5'&&s[i+2]=='5'&&s[i+3]=='3'&&s[i+4]=='6')	++ans, s[i+4]='9';
	cout<<ans<<endl;
	return 0;
}