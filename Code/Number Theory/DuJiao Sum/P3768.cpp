#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
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

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 5e6 + 10;
const int M = 5e6;

int n,MOD,inv6,inv2,inv4;
unordered_map<int,int> sumf;
int phi[N],p[N],cnt;
void init(){
    phi[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])  phi[i]=i-1, p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=M;++j){
            p[p[j]*i]=1;
            if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
            phi[i*p[j]]=phi[i]*phi[p[j]];
        }
    }
    for(int i=1;i<=M;++i)   phi[i]=(phi[i]*i%MOD*i%MOD+MOD)%MOD;
    for(int i=1;i<=M;++i)   phi[i]=(phi[i]+phi[i-1])%MOD;
}

int ksm(int x,int m){
    int ans=1;
    while(m){
        if(m&1) ans=ans*x%MOD;
        x=x*x%MOD; m>>=1;
    }
    return ans;
}
int s2(int n){ return n%MOD*((n+1)%MOD)%MOD*((2*n+1)%MOD)%MOD*inv6%MOD;}
int s1(int n){ return n%MOD*((n+1)%MOD)%MOD*inv2%MOD;}
int s3(int n){ return n%MOD*n%MOD*((n+1)%MOD)%MOD*((n+1)%MOD)%MOD*inv4%MOD;}
int sf(int n){
    if(n<=M)    return phi[n];
    if(sumf[n]) return sumf[n];
    int res=0;
    for(int i=2;i<=n;++i){
        int j=n/(n/i);
        res=(res+(s2(j)%MOD-s2(i-1)%MOD+MOD)%MOD*sf(n/i)%MOD)%MOD;
        i=j;
    }
    return sumf[n]=(s3(n)%MOD-res%MOD+MOD)%MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>MOD>>n;
    init();
    inv6=ksm(6,MOD-2); inv2=ksm(2,MOD-2); inv4=ksm(4,MOD-2);
    int ans=0;
    for(int i=1;i<=n;++i){
        int j=n/(n/i);
        ans=(ans+(sf(j)%MOD-sf(i-1)%MOD+MOD)%MOD*s1(n/i)%MOD*s1(n/i)%MOD)%MOD;
        i=j;
    }
    cout<<(ans+MOD)%MOD<<endl;
    return 0;
}