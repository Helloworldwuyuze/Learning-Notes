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
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int n, ans;
string s[N];

int t[N][26], idx, flag[N];
void insert(string s){
	int len=s.size(), p=0;
	for(int i=0;i<len;++i){
		p=t[p][s[i]-'a']?t[p][s[i]-'a']:(t[p][s[i]-'a']=++idx);
		flag[p]++;
	}
}
int query(string s){
	int len=s.size(), p=0, ans=0;
	for(int i=0;i<len;++i){
		if(!t[p][s[i]-'a'])	return ans;
		p=t[p][s[i]-'a'];
		ans+=flag[p];
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>s[i];
	for(int i=n;i;--i){
		ans+=query(s[i]);
		insert(s[i]);
	}
	cout<<ans<<endl;
	return 0;
}