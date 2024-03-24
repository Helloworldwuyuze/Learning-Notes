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

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int f[N][4],n,w[N];
char c[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	cin>>(c+1);
	for(int i=1;i<=n;++i)	cin>>w[i];
	f[1][1]=f[1][3]=w[1]; f[1][2]=f[1][3]=INF;
	for(int i=2;i<=n;++i){
		if(c[i]==c[i-1]){
			f[i][0]=f[i-1][1];
			f[i][1]=f[i-1][0]+w[i];
			f[i][2]=min(f[i-1][0],f[i-1][3]);
			f[i][3]=min(f[i-1][1],f[i-1][2])+w[i];
		}else{
			f[i][0]=f[i-1][0];
			f[i][1]=f[i-1][1]+w[i];
			f[i][2]=min(f[i-1][1],f[i-1][2]);
			f[i][3]=min(f[i-1][0],f[i-1][3])+w[i];
		}
		// for(int j=0;j<4;++j)	cout<<f[i][j]<<" ";
		// cout<<endl;
	}
	cout<<min(f[n][2],f[n][3])<<endl;
	return 0;
}