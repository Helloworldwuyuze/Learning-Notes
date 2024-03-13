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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 16 + 10;
const int M = (1<<16) + 10;

int dp[M],ma[N][N],n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>ma[i][j];
    for(int s=0;s<(1<<n);++s){
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if((s&(1<<i))&&(s&(1<<j)))  dp[s]+=ma[i][j];
        for(int t=s;t;t=(t-1)&s)
            dp[s]=max(dp[s],dp[t]+dp[t xor s]);
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}