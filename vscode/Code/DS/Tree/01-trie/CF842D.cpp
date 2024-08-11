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
const int MAXH = 30;

int t[N<<5][2], w[N<<5], idx = 1;
int n, q, x, lst;

void insert(int x){
	int p = 1;
	for(int i=MAXH;i>=0;--i){
		if(!t[p][(x>>i)&1])	t[p][(x>>i)&1] = ++idx;
		w[p] = 1, p = t[p][(x>>i)&1];
	}
	w[p] = 1;
}
int query(int x){
	int ans = 0, p = 1;
	for(int i=MAXH;i>=0;--i){
		if(w[t[p][(x>>i)&1]] == (1<<i))	ans += (1<<i), p = t[p][((x>>i)&1)^1];
		else	p = t[p][(x>>i)&1];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)	cin>>x, insert(x);
	for(int i=idx;i;--i)
		if(t[i][0] || t[i][1])	w[i] = w[t[i][0]] + w[t[i][1]];
		else	w[i] = 1;
	for(int i=1;i<=q;++i)	cin>>x, x^=lst, cout<<query(x)<<endl, lst = x;
	return 0;
}