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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

string s;
int n, K, a[15], ans;
map<string, bool> ma;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>K>>s;
	for(int i=0;i<n;++i)	a[i] = i;
	do{
		string tmp = s;
		for(int i=0;i<n;++i)	tmp[i] = s[a[i]];
		if(ma[tmp])	continue;
		ma[tmp] = true;
		bool flag = false;
		for(int i=0;i+K<=n;++i){
			// cout<<i<<endl;
			bool f = true;
			for(int j=i, k=i+K-1; j<k; ++j, --k)
				f &= tmp[j] == tmp[k];
			flag |= f;
		}
		// cout<<tmp<<" "<<flag<<endl;
		if(!flag)	++ans;
	}while(next_permutation(a, a+n));
	cout<<ans<<endl;
	return 0;
}