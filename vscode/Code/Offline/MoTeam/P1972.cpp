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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef unsigned int ui;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, m, a[N], x[N], y[N], nn, col[N], sum, ans[N];
int flag[N], pre[N], suf[N];
struct node{
	int l, r, id;
	bool operator <(const node &other) const{
		if(l/nn == other.l/nn)  return (l/nn%2)?r<other.r:r>other.r;
		return l/nn < other.l/nn;
	}
}range[N];

void add(int x){ if(++col[a[x]] == 1)	++sum; }
void del(int x){ if(--col[a[x]] == 0)	--sum; }

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n; nn = sqrt(n);
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1;i<=n;++i)   pre[i] = flag[a[i]], flag[a[i]] = i;
    memset(flag, 0x3f, sizeof(flag));
    for(int i=n;i;--i)  suf[i] = flag[a[i]], flag[a[i]] = i;
    cin>>m;
    for(int i=1;i<=m;++i)   cin>>x[i]>>y[i], range[i] = node{ x[i], y[i], i};
    sort(range+1, range+1+m);
    int l = 1, r = 0;
    for(int i=1;i<=m;++i){
        while(r<range[i].r) sum += pre[++r] < l;
        while(l>range[i].l) sum += suf[--l] > r;
        while(r>range[i].r) sum -= pre[r--] < l;
        while(l<range[i].l) sum -= suf[l++] > r;
        ans[range[i].id] = sum;
    }
    for(int i=1;i<=m;++i)   cout<<ans[i]<<endl;
	return 0;
}