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
const int N = 2e6 + 10;
const int M = 1e6 + 10;

int n,m;
char c[N];

int t[N][26], fail[N], sta[N], dep[N], idx;
bool flag[N], f[N];
void insert(char c[]){
	int len=strlen(c), p=0;
	for(int i=0;i<len;++i)
		p=t[p][c[i]-'a']?(t[p][c[i]-'a']):(t[p][c[i]-'a']=++idx);
	flag[p]=true;
}
queue<int> q;
void build(){
	for(int i=0;i<26;++i)
		if(t[0][i])	q.push(t[0][i]), dep[t[0][i]]=1, sta[t[0][i]]=flag[t[0][i]]*2;
	while(q.size()){
		int p=q.front(); q.pop();
		sta[p]=sta[fail[p]]|((1<<dep[p])*flag[p]);
		for(int i=0;i<26;++i)
			if(t[p][i])	fail[t[p][i]]=t[fail[p]][i], dep[t[p][i]]=dep[p]+1, q.push(t[p][i]);
			else	t[p][i]=t[fail[p]][i];
	}
}
int query(char c[]){
	int len=strlen(c), p=0, maxx=0;
	unsigned int state=1;
	for(int i=0;i<len;++i){
		p=t[p][c[i]-'a'];
		state<<=1;
		if(state&sta[p])	maxx=i+1, state|=1;
	}
	return maxx;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>c, insert(c);
	build();
	// for(int i=0;i<=idx;++i)
	// 	cout<<fail[i]<<" "<<sta[i]<<endl;
	for(int i=1;i<=m;++i){
		cin>>c;
		cout<<query(c)<<endl;
	}
	return 0;
}