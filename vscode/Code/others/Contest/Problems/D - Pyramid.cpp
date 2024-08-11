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

int a[N],n,pre[N],suf[N],ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1;i<=n;++i){
        pre[i]=min(min(i,a[i]),pre[i-1]+1);
    }
    for(int i=n;i;--i){
        suf[i]=min(min(n-i+1,a[i]),suf[i+1]+1);
        ans=max(ans,min(pre[i],suf[i]));
    }
    cout<<ans<<endl;
    return 0;
}