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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n,op[N],ans[N];
char s[N];
vector<char> c[N];
vector<int> times[N], g[N];
int dfn[N], siz[N], idx;

namespace AC{
	int t[M][26], fail[M], flag[M], idx=0;
	void insert(char c[],int id){
		int len=strlen(c+1), p=0;
		for(int i=1;i<=len;++i)	p=t[p][c[i]-'a']?t[p][c[i]-'a']:(t[p][c[i]-'a']=++idx);
		flag[id]=p;
	}
	queue<int> q;
	void build(){
		for(int i=0;i<26;++i)
			if(t[0][i])	q.push(t[0][i]);
		while(q.size()){
			int p=q.front(); q.pop();
			for(int i=0;i<26;++i)
				if(t[p][i])	fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]);
				else	t[p][i]=t[fail[p]][i];
		}
		for(int i=1;i<=idx;++i)
			g[fail[i]].pb(i);
	}
}
namespace BIT{
	int b[M];
	#define lowbit(x) (x&-x)
	void update(int x,int k){ for(int i=x;i<=idx;i+=lowbit(i))	b[i]+=k;}
	int query(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))	ans+=b[i]; return ans;}
	#undef lowbit
}

void dfs1(int x){
	dfn[x]=++idx, siz[x]=1;
	for(int y:g[x])
		dfs1(y), siz[x]+=siz[y];
}

void query(int x){
	// cout<<"###"<<x<<"###"<<endl;
	// for(int i=0;i<=AC::idx;++i)
	// 	cout<<BIT::query(dfn[i])<<" ";
	// cout<<endl;
	int p=0;
	for(char i:c[x]){
		// cout<<i<<" "<<p<<endl;;
		p=AC::t[p][i-'a'];
		ans[x]+=BIT::query(dfn[p]);
	}
	// cout<<endl;
}

void dfs2(int x){
	// cout<<"###"<<x<<" "<<AC::flag[x]<<" "<<dfn[AC::flag[x]]<<" "<<dfn[AC::flag[x]]+siz[AC::flag[x]]<<"###"<<endl;
	// for(int i=0;i<=AC::idx;++i)
	// 	cout<<BIT::query(dfn[i])<<" ";
	// cout<<endl;
	if(op[x]==1)	BIT::update(dfn[AC::flag[x]],1), BIT::update(dfn[AC::flag[x]]+siz[AC::flag[x]],-1);
	else	query(x);
	for(int y:times[x])	dfs2(y);
	if(op[x]==1)	BIT::update(dfn[AC::flag[x]],-1), BIT::update(dfn[AC::flag[x]]+siz[AC::flag[x]],1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;++i){
		cin>>op[i]>>x>>(s+1);
		times[x].pb(i);
		if(op[i]==1)	AC::insert(s,i);
		else{
			int len=strlen(s+1);
			c[i].resize(len);
			for(int j=1;j<=len;++j)
				c[i][j-1]=s[j];
		}
	}
	AC::build();
	dfs1(0);
	// for(int i=0;i<=AC::idx;++i)
	// 	cout<<siz[i]<<" ";
	// cout<<endl;
	dfs2(0);
	for(int i=1;i<=n;++i)
		if(op[i]==2)	cout<<ans[i]<<endl;
	return 0;
}