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
const int N = 100 + 10;
const int M = 1e6 + 10;

int n,m,k,a[N][N],c[N],ans;
bool key[N];
char r[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>c[i];
		for(int j=1;j<=c[i];++j)	cin>>a[i][j];
		cin>>r[i];
	}
	for(int state = 0;state < (1<<n); ++state){
		int st = state, top=0;
		while(st)	key[++top] = st&1, st>>=1;
		bool flag=true;
		for(int i=1;i<=m;++i){
			int sum=0;
			for(int j=1;j<=n;++j)	sum+=key[a[i][j]];
			if(sum>=k&&r[i]=='x'||sum<k&&r[i]=='o')	flag=false;
		}
		ans+=flag;
	}
	cout<<ans<<endl;
	return 0;
}