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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 60 + 10;
const int M = 1e5 + 10;

int n, ans;
bool ch[N];

signed main(){
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=0;i<(1<<n);++i){
        int j = i;
        for(int j=0;j<n;++j)    ch[j+1] = (i>>j)&1;
        bool flag = true;
        for(int j=1;j<=n;++j)
            if(ch[j]&&(ch[2*j]||ch[3*j]))   flag=false;
        ans += flag;
    }
    cout<<ans<<endl;
	return 0;
}
