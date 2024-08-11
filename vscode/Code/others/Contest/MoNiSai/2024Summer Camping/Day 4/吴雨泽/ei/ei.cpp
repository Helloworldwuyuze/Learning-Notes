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

int T, n, a[N], g, d[N];

int gcd(int x,int y){
	return y==0?x:gcd(y, x%y);
}

int main(){
//	freopen("ei.in","r",stdin);
//	freopen("ei.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	sort(a+1, a+1+n);
	int m = unique(a+1, a+1+n) - a - 1;
	if(m == 1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<m;++i)	d[i] = a[i+1]-a[i];
	g = d[1];
	for(int i=1;i<m;++i)	g = gcd(g, d[i]);
	if(g != 1)	cout<<1<<endl;
	else	cout<<2<<endl;
	return 0;
}

