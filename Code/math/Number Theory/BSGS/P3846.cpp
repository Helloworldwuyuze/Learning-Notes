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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int a, b, p;
unordered_map<int, int> ma;

int ksm(int x,int m,int MOD){
	int ans = 1;
	for(;m;m>>=1, x=x*x%MOD)	if(m&1)	ans=ans*x%MOD;
	return ans;
}
int BSGS(int a,int b,int p){
	int nn = sqrt(p), res = b, st = ksm(a, nn, p);
	for(int i=0;i<nn;++i)
		ma[res] = i+1, res = a*res%p;
	// cout<<endl<<st<<endl;;
	res = st;
	for(int i=1;i<=nn;++i, res = res*st%p)
		if(ma[res])	return i*nn - ma[res] + 1;
	return -1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>p>>a>>b;
	int ans = BSGS(a, b, p);
	if(ans==-1)	cout<<"no solution"<<endl;
	else	cout<<ans<<endl;
	return 0;
}