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
const int N = 2e6 + 10;
const int M = 1e6 + 10;

int n,m,a[N],b[N],cnt;

struct opt{
	char op;
	int x,y;
}op[N];
struct BIT{
	int b[N];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=cnt;i+=lowbit(i))	b[i]+=k;}
	int query(int x){int ans=0; for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}
	#undef lowbit
}b1, b2;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>op[i].op>>op[i].x>>op[i].y;
		b[++cnt]=op[i].y;
	}
	b[++cnt]=0;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for(int i=1;i<=m;++i)
		op[i].y=lower_bound(b+1,b+1+cnt,op[i].y)-b;
	b2.update(1,n);
	for(int i=1;i<=n;++i)	a[i]=1;
	for(int i=1;i<=m;++i){
		if(op[i].op=='U'){
			int x=op[i].x, y=op[i].y;
			b1.update(a[x],-b[a[x]]);
			b2.update(a[x],-1);
			b1.update(y,b[y]);
			b2.update(y,1);
			a[x]=y;
		}else{
			int c=op[i].x, s=op[i].y;
			if(c>n)	cout<<"NIE"<<endl;
			else if(b1.query(s)+(b2.query(cnt)-b2.query(s))*b[s]>=c*b[s])	cout<<"TAK"<<endl;
			else	cout<<"NIE"<<endl;
		}
	}
	return 0;
}