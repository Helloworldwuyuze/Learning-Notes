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
const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n,a[150],q;
char c[N],x,y,p[150];

int find(int x){ return x==a[x]?a[x]:a[x]=find(a[x]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>(c+1)>>q;
	for(int i=1;i<=128;++i)	a[i]=i, p[i]=i;
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		for(int i='a';i<='z';++i)
			if(p[i]==x)	p[i]=y;
	}
	// for(int i='a';i<='z';++i)	cout<<a[i]<<" ";
	// cout<<endl;
	// for(int i='a';i<='z';++i)	cout<<p[i]<<" ";
	// cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<(p[c[i]]);
	cout<<endl;
	return 0;
}