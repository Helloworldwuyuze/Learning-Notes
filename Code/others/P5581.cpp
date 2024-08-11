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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, m, g, a[N], ans = INF, f[N], nn, mm, bl[N], fir[N], re[N], minn[N][22], t;
vector<int> gp[N], ord[N];
char c;

int gcd(int x,int y){ return y==0 ? x : gcd(y, x%y);}
int query(int l,int r){
	int t = log(r-l+1);
	return min(minn[l][t], minn[r-(1<<t)+1][t]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;++i)	cin>>c, f[i] = c=='W'?1:-1;
	g = gcd(n, m); nn = n/g, mm = m/g, t = log2(mm<<1);
	// cerr<<g<<endl;
	for(int d=1;d<=g;++d){
		int tmp = d;
		ord[d].resize(mm+1);
		for(int i=1;i<=mm;++i)	ord[d][i] = tmp, fir[tmp] = i, tmp = (tmp+n-1)%m+1, re[d] += f[tmp];
		for(int i=0;i<nn;++i)	gp[d].pb(i*g+d), bl[i*g+d] = d;
		ord[d].resize(2*mm+1);
		for(int i=1;i<=mm;++i)	ord[d][i+mm] = ord[d][i];
		// re[d] *= mm;
		// cerr<<"ORD!!\n";
		// for(int i=1;i<=mm<<1;++i)	cerr<<ord[d][i]<<" ";
		// cerr<<endl;
		for(int i=1;i<=2*mm;++i)	ord[d][i] = f[ord[d][i]] + ord[d][i-1];
	}
	// cerr<<"ORD!!\n";
	// for(int d=1;d<=g;++d,cerr<<endl)
	// 	for(int x:ord[d])	cerr<<x<<" ";
	// cerr<<"FIR!!\n";
	// for(int i=1;i<=m;++i)	cout<<fir[i]<<" ";
	// cerr<<endl;
	for(int d=1;d<=g;++d){
		for(int i=1;i<=mm<<1;++i)	minn[i][0] = ord[d][i];
		for(int j=1;j<=t;++j)
			for(int i=1;i+(1<<j)-1<=mm<<1;++i)
				minn[i][j] = min(minn[i][j-1], minn[i+(1<<j-1)][j-1]);
		// for(int i=1;i<=mm<<1;++i, cout<<endl)
		// 	for(int j=0;j<=t;++j)	cout<<minn[i][j]<<" ";
		for(int x:gp[d]){
			// cout<<"###"<<x<<"###"<<endl;
			int L = fir[(x-1)%m+1], l = L, r = l+mm-1;
			if(query(l, r)-ord[d][L-1] >= 0 || a[x] > query(l, r) && re[d]>=0)	continue;
			int rest = re[d]<0 && a[x]+query(l,r)-ord[d][L-1]>0 ? ceil(1.0*(a[x]+query(l,r)-ord[d][L-1])/(-re[d])) : 0;
			// cout<<"REST A[X] RE[D]!!"<<endl;
			// cout<<rest<<" "<<a[x]<<" "<<re[d]<<" "<<query(l, r)<<" "<<ord[d][L-1]<<" "<<l<<" "<<r<<endl;
			a[x] += rest * re[d];
			while(l<r){
				int mid = l+r>>1;
				if(query(l, mid) - ord[d][L-1] <= -a[x])	r = mid;
				else	l = mid+1;
			}
			ans = min(ans, rest*n*m/g + (l-L)*n + x);
			// cout<<"l L REST X!!"<<endl;
			// cout<<l<<" "<<L<<" "<<rest<<" "<<query(1, 3)<<" "<<ans<<endl;
		}
	}
	if(ans == INF)	cout<<-1<<endl;
	else	cout<<ans<<endl;
	return 0;
}