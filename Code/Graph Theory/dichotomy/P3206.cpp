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
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, q;
struct edge{
	int u, v, w, l = -1, r = -1;
};
vector<edge> a;
int lst[N], ans;

void divide(int l,int r,vector<edge> a){

	if(l == r){
		if(l)	cout<<ans<<endl;
		return ;
	}else{
		int mid = l+r>>1;
		vector<edge> tmp;
		for(edge e:a)
			if(!(e.l<=l && r<=e.r) && e.l <= mid)	tmp.pb(e);
		divide(l, mid, tmp);
		vector<edge>().swap(tmp);
		for(edge e:a)
			if(!(e.l<=l && r<=e.r) && e.r > mid)	tmp.pb(e);
		divide(mid+1, r, tmp);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1,x,y,z;i<=m;++i)	cin>>x>>y>>z, a.pb(edge{x, y, z, 0, -1}), lst[i] = a.size()-1;
	for(int i=1, x, y;i<=q;++i){
		cin>>x>>y;
		int u = a[lst[i]].u, v = a[lst[i]].v;
		a[lst[i]].r = i-1;
		a.pb(edge{u, v, y, i, -1});
		lst[i] = a.size()-1;
	}
	for(edge &e:a)
		if(e.r == -1)	e.r = q;
	divide(0, q, a);
	return 0;
}