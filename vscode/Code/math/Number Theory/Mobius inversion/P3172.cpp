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
#include<unordered_map>

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
const int N = 2e6 + 10;
const int M = 2e6;
const int MOD = 1e9 + 7;

int mu[N], p[N], cnt;
void init(){
    mu[1] = 1;
    for(int i=2;i<=M;++i){
        if(!p[i])   mu[p[++cnt] = i] = -1;
        for(int j=1;j<=cnt&&i*p[j]<=M;++j){
            p[i*p[j]] = 1;
            if(i%p[j]==0)   break;
            mu[i*p[j]] = -mu[i];
        }
    }
    for(int i=1;i<=M;++i)   mu[i] += mu[i-1];
}
int n, k, l, h;
int ksm(int x, int m){
    int ans = 1;
    while(m){ if(m&1) ans = ans*x%MOD; x = x*x%MOD; m>>=1;}
    return ans;
}

unordered_map<int, int> ma;
int sum(int x){
    if(x<=M)    return mu[x];
    if(ma[x])   return ma[x];
    int ans = 1;
    for(int l=2;l<=x;++l){
        int r = x/(x/l);
        ans = (ans - sum(x/l) * (r-l+1) % MOD + MOD) % MOD;
        l=r;
    }
    return ma[x] = ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); init();
    cin>>n>>k>>l>>h;
    --l/=k, h/=k; int ans = 0;
    for(int i=1;i<=h;++i){
        int j = min(l<i?INF:l/(l/i), h/(h/i));
        ans += ((sum(j) - sum(i-1))%MOD +MOD)%MOD * ksm(h/i-l/i, n) % MOD;
        ans%=MOD, i=j;
    }
    cout<<ans<<endl;
	return 0;
}