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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int f[128][128], n, len[N];
string s[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		len[i]=s[i].size();
	}
	for(int i=1;i<=n;++i){
		int l=s[i][0], r=s[i][len[i]-1];
		for(int j='a';j<='z';++j)
			if(f[j][l])	f[j][r]=max(f[j][r],f[j][l]+len[i]);
		f[l][r]=max(f[l][r],len[i]);
	}
	int ans=0;
	for(int i='a';i<='z';++i)	ans=max(ans,f[i][i]);
	cout<<ans<<endl;
	return 0;
}