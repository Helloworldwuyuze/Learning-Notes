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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 50 + 10;
const int M = 1e6 + 10;

int n,m,ans=INF;
char a[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>(a[i]+1);
	for(int i=1;i<n-1;++i)
		for(int j=i+1;j<n;++j){
			int res=0;
			for(int x=1;x<=i;++x)
				for(int y=1;y<=m;++y)
					res+=a[x][y]!='W';
			for(int x=i+1;x<=j;++x)
				for(int y=1;y<=m;++y)
					res+=a[x][y]!='B';
			for(int x=j+1;x<=n;++x)
				for(int y=1;y<=m;++y)
					res+=a[x][y]!='R';
			ans=min(ans,res);
		}
	cout<<ans<<endl;
	return 0;
}