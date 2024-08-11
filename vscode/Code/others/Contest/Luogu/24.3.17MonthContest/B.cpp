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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int T, n,a,b;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>a>>b;
		if(a==1&&b>0)	cout<<n%b-b<<endl;
		else if(a*n-b>=n)	cout<<n<<endl;
		else{
			int s=0;
			while(n>=0&&n*a-b<n)	n=n*a-b, ++s;
			cout<<n<<endl;
		}
	}
	return 0;
}
//a*(n*a-b)-b=a*(a*a*n-a*b-b)-b=a*a*a*n-a*a*b-a*b-b;