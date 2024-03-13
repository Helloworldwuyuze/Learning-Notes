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
const int N = 3e3 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

int h,w,n;
PII p[N];
int f[N],fact[M],infact[M];

int ksm(int x,int m){
    int ans=1;
    while(m){ if(m&1)   ans=ans*x%MOD; x=x*x%MOD; m>>=1;}
    return ans;
}
int C(int n,int m){ return fact[n]*infact[m]%MOD*infact[n-m]%MOD;}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>h>>w>>n;
    for(int i=1;i<=n;++i)   cin>>p[i].fi>>p[i].se;
    p[++n].fi=h, p[n].se=w;
    sort(p+1,p+1+n);
    fact[0]=1;
    for(int i=1;i<=M-10;++i)    fact[i]=fact[i-1]*i%MOD;
    infact[M-10]=ksm(fact[M-10],MOD-2);
    for(int i=M-11;i>=0;--i)    infact[i]=infact[i+1]*(i+1)%MOD;
    for(int i=1;i<=n;++i){
        f[i]=C(p[i].fi+p[i].se-2,p[i].fi-1);
        for(int j=1;j<i;++j)
            if(p[j].fi<=p[i].fi&&p[j].se<=p[i].se)  f[i]=(f[i]-f[j]*C(p[i].fi+p[i].se-p[j].fi-p[j].se,p[i].fi-p[j].fi)%MOD+MOD)%MOD;
    }
    cout<<f[n]<<endl;
    return 0;
}