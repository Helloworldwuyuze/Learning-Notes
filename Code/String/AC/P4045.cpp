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
const int N = 100 + 10;
const int M = 1e6 + 10;

int n,m;
char c[N];

int t[N][26], flag[N], idx, fail[N];
void insert(char c[],int j){
	int len=strlen(c+1), p=0;
	for(int i=1;i<=len;++i)
		p=t[p][c[i]-'a']?t[p][c[i]-'a']:(t[p][c[i]-'a']=++idx);
	flag[p]=(1<<j);
}
queue<int> q;
void build(){
	for(int i=0;i<26;++i)
		if(t[0][i])	q.push(t[0][i]);
	while(q.size()){
		int p=q.front(); q.pop();
		flag[p]|=flag[fail[p]];
		for(int i=0;i<26;++i)
			if(t[p][i])	fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]);
			else	t[p][i]=t[fail[p]][i];
	}
}
int f[30][N][(1<<10)+10];
bool vis[30][N][(1<<10)+10], g[30][N][(1<<10)+10];
int tt[30];

bool dfs(int x,int y,int z){
	if(x==m){
		vis[x][y][z]=true;
		return g[x][y][z]=(z==(1<<n)-1);
	}
	if(vis[x][y][z])	return g[x][y][z];
	vis[x][y][z]=true;
	bool tmp=false;
	for(int i=0;i<26;++i)
		tmp|=dfs(x+1,t[y][i],z|flag[t[y][i]]);
	return g[x][y][z]=tmp;
}
void print(int x,int y,int z){
	if(!g[x][y][z])	return ;
	if(x==m){
		for(int i=1;i<=m;++i)
			cout<<(char)(tt[i]+'a');
		cout<<endl;
		return void();
	}
	for(int i=0;i<26;++i)
		tt[x+1]=i, print(x+1,t[y][i],z|flag[t[y][i]]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;++i)	cin>>(c+1), insert(c,i-1);
	build();
	f[0][0][0]=1;
	for(int i=0;i<=m;++i)
		for(int p=0;p<=idx;++p)
			for(int j=0;j<=(1<<n)-1;++j)
				if(f[i][p][j])
					for(int k=0;k<26;++k)
						f[i+1][t[p][k]][j|flag[t[p][k]]]+=f[i][p][j];
	int ans=0;
	for(int i=0;i<=idx;++i)
		ans+=f[m][i][(1<<n)-1];
	if(ans>42){
		cout<<ans<<endl;
		return 0;
	}else{
		cout<<ans<<endl;
		dfs(0,0,0);
		// for(int i=0;i<=m;++i,cout<<endl)
		// 	for(int p=0;p<=idx;++p,cout<<endl)
		// 		for(int j=0;j<=(1<<n)-1;++j)
		// 			cout<<g[i][p][j]<<" ";
		print(0,0,0);
		return 0;
	}
	return 0;
}