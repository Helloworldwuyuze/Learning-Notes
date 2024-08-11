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
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, l, r;

int b[N];
#define lowbit(x) (x&-x)
void update(int x,int k){ for(int i=x;i<=n;i+=lowbit(i))    b[i]+=k;}
int query(int x){ int ans = 0; for(int i=x;i;i-=lowbit(i))  ans+=b[i]; return ans;}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    while(cin>>n&&n){
        for(int i=1;i<=n;++i){
            cin>>l>>r;
            update(l, 1), update(r+1, -1);
        }
        for(int i=1;i<=n;++i)   cout<<query(i)<<" ";
        cout<<endl;
        for(int i=1;i<=n;++i)   b[i]=0;
    }
	return 0;
}