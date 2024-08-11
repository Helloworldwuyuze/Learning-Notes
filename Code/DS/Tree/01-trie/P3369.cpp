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

int n, op, x, m;
const int ADD = 1e7;

int t[N<<5][2], w[N<<5], idx = 1;

void insert(int x,int k){
	int p = 1;
	for(int i=MAXH;i>=0;--i){
		if(!t[p][(x>>i)&1])	t[p][(x>>i)&1] = ++idx;
		w[p]+=k;
		p = t[p][(x>>i)&1];
	}
	w[p]+=k;
}
int GRBV(int x){
	int p = 1, ans = 0;
	for(int i=MAXH;i>=0;--i){
		if(((x>>i)&1))	ans += w[t[p][0]];
		p = t[p][(x>>i)&1];
		if(!p)	return ans+1;
	}
	return ans+1;
}
int GVBR(int x){
	// cout<<"GVBR! "<<x<<endl;
	int p = 1, ans = 0;
	for(int i=MAXH;i>=0;--i){
		// cout<<p<<" "<<w[t[p][0]]<<" "<<x<<" "<<t[p][0]<<" "<<t[p][1]<<" "<<ans<<endl;
		if(w[t[p][0]] >= x)	p = t[p][0];
		else	x -= w[t[p][0]], p = t[p][1], ans += (1<<i);
	}
	return ans;
}
int pre(int x){
	// cout<<"PRE! "<<x<<" "<<GRBV(x)<<endl;
	return GVBR(GRBV(x)-1);
}
int nxt(int x){
	// cout<<"SUF! "<<x<<" "<<GRBV(x)<<endl;
	return GVBR(GRBV(x+1));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>m;
	while(m--){
		cin>>op>>x;
		switch(op){
			case 1:insert(x+ADD, 1); break;
			case 2:insert(x+ADD, -1); break;
			case 3:cout<<GRBV(x+ADD)<<endl; break;
			case 4:cout<<GVBR(x)-ADD<<endl; break;
			case 5:cout<<pre(x+ADD)-ADD<<endl; break;
			case 6:cout<<nxt(x+ADD)-ADD<<endl; break;
		}
		// for(int i=1;i<=idx;++i)
		// 	cout<<i<<" "<<t[i][0]<<" "<<t[i][1]<<" "<<w[i]<<endl;
	}
	return 0;
}