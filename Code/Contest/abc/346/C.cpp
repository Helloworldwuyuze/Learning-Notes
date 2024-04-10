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

int n;
int a[N],b[N],c[N],m,minn[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(minn,0x3f,sizeof(minn));
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>c[i], b[i]=c[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i)	c[i]=lower_bound(b+1,b+1+m,c[i])-b;
	for(int i=1;i<=n;++i)	minn[c[i]]=min(minn[c[i]],a[i]);
	int maxx=0;
	for(int i=1;i<=n;++i)
		maxx=max(maxx,minn[c[i]]);
	cout<<maxx<<endl;
	return 0;
}