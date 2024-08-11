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
const int N = 1e4 + 10;
const int M = 10000;

int a[N], b[N], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("information20.in","w",stdout);
    srand((unsigned)time(NULL));
    n = M;
    cout<<n<<endl;
    for(int i=1;i<=n;++i)	a[i] = i;
    for(int i=1;i<=n;++i)	b[i] = i;
    random_shuffle(a+1,a+1+n);
    random_shuffle(b+1,b+1+n);
    for(int i=1;i<=n;++i)	cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;++i)	cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}

