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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e3 + 10;
const int M = 1e6 + 10;

int n,a,b,c,f[N];
bool ok[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>a>>b>>c;
	ok[0]=true;
	for(int i=1;i<=n;++i){
		if(i>=a&&ok[i-a])	f[i]=max(f[i], f[i-a]+1), ok[i]=true;
		if(i>=b&&ok[i-b])	f[i]=max(f[i], f[i-b]+1), ok[i]=true;
		if(i>=c&&ok[i-c])	f[i]=max(f[i], f[i-c]+1), ok[i]=true;
		// cout<<f[i]<<" ";
	}
	cout<<f[n]<<endl;
	return 0;
}