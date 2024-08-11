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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e4 + 10;
const int M = 2e5 + 10;

int fa[N], b[N];
int n,m,cnt;
struct ques{
	int l, r, f;
}q[N];

int find(int x){ return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
void merge(int x,int y){
	int fx = find(x), fy = find(y);
	if(fx==fy)	return ;
	fa[fx] = fy;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		string s;
		cin>>q[i].l>>q[i].r>>s;	q[i].f = s[0]=='o'; --q[i].l;
		b[++cnt] = q[i].l, b[++cnt] = q[i].r;
	}
	sort(b+1, b+1+cnt);
	cnt = unique(b+1, b+1+cnt) - b - 1;
	for(int i=1;i<=m;++i){
		q[i].l = lower_bound(b+1, b+1+cnt, q[i].l) - b;
		q[i].r = lower_bound(b+1, b+1+cnt, q[i].r) - b;
	}
	for(int i=1;i<=2*cnt;++i)	fa[i]=i;
	for(int i=1;i<=m;++i){
		if(q[i].f){
			if(find(q[i].l)==find(q[i].r)){
				cout<<i-1<<endl;
				return 0;
			}else{
				merge(q[i].l, q[i].r+cnt);
				merge(q[i].l+cnt, q[i].r);
			}
		}else{
			if(find(q[i].l)==find(q[i].r+cnt)){
				cout<<i-1<<endl;
				return 0;
			}else{
				merge(q[i].l+cnt, q[i].r+cnt);
				merge(q[i].l, q[i].r);
			}
		}
	}
	cout<<m<<endl;
	return 0;
}