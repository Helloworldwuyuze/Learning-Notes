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

#define fi first
#define se second
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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 7e5 + 10;
const int M = 2e6;

struct card{
	int a,b,c;
	bool operator <(const card &other) const{ return a<other.a;}
}p[N], q[N];
int n,a,b,c, preb[N], prec[N], ans, sufb[N], sufc[N], tot, _sufc[N];

int len(int l,int r){ return l<=r?r-l+1:0;}

struct node{
	int maxx, s, siz;
}t[N<<2];

bool cmp(card x,card y){ return x.b<y.b;}
bool flag;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;++i)   cin>>p[i].a>>p[i].b>>p[i].c, flag&=(i==1|p[i].c==p[i-1].c);
	if(a<=100&&b<=100&&c<=100){
		int sum=0;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				for(int k=1;k<=c;++k){
					bool flag=true;
					for(int x=1;x<=n;++x)
						if((i>p[x].a)+(j>p[x].b)+(k>p[x].c)<=1)	flag=false;
					sum+=flag;
				}
		cout<<sum<<endl;
		return 0;
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;++i){
		preb[i] = max(preb[i-1], p[i].b);
		prec[i] = max(prec[i-1], p[i].c);
	}
	for(int i=n;i;--i){
		sufb[i] = max(sufb[i+1], p[i].b);
		sufc[i] = max(sufc[i+1], p[i].c);
	}
	ans = len(1, p[1].a) * len(sufb[1]+1, b) * len(sufc[1]+1, c);
	if(flag){
		for(int i=1;i<=n;++i){
			int la = p[i].a, ra = i==n?a:min(p[i+1].a, a);
			ans += len(la, ra) + len(sufb[i+1]+1, b) + len(p[1].c+1, c);
		}
		cout<<ans<<endl;
	}
	for(int i=1;i<=n;++i){
		q[i]=card{p[i].a,p[i].b,p[i].c};
		sort(q+1, q+1+i, cmp);
		if(p[i].a==p[i+1].a)	continue;
		int la = p[i].a+1, ra = i==n?a:min(a,p[i+1].a), sb = sufb[i+1]+1, sc = sufc[i+1]+1;
		for(int j=i;j;--j)	_sufc[j]=max(_sufc[j+1], q[j].c);
		ans+=len(la, ra) * len(sb, q[1].b) * len(sc, c);
		// cout<<ans<<endl;
		for(int j=1;j<=i;++j){
			// cout<<q[j].a<<" "<<q[j].b<<" "<<q[j].c<<endl;
			int lb = q[j].b+1, rb = j==n?b:min(q[j+1].b,b);
			ans += len(la, ra) * len(max(lb, sb), rb) * len(max(_sufc[j+1]+1, sc), c);
			// cout<<i<<" "<<j<<" "<<la<<" "<<ra<<" "<<lb<<" "<<sb<<" "<<rb<<" "<<_sufc[j+1]<<" "<<sc<<" "<<c<<endl;
			// cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
