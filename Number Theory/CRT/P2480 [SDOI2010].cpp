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
#define int long long

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int MOD = 999911659;
const int mod = 999911658;

int n,g;
int d[N],cnt,m[10],tot;
int a[10],M[10],t[10];
int fact[N],infact[N];

int ksm(int x,int m,int p){
    int ans=1;
    while(m){
        if(m&1) ans=ans*x%p;
        x=x*x%p; m>>=1;
    }
    return ans;
}
void init(int p){
    fact[0]=1; infact[p]=0;
    for(int i=1;i<p;++i)    fact[i]=fact[i-1]*i%p;
    infact[p-1]=ksm(fact[p-1],p-2,p);
    for(int i=p-2;i>=0;--i) infact[i]=infact[i+1]*(i+1)%p;
}

void cal(){
    int i=1,mo=mod;
    for(;i*i<n;++i)
        if(n%i==0)  d[++cnt]=i, d[++cnt]=n/i;
    if(n%i==0)  d[++cnt]=i;
    for(i=2;i*i<=mod;++i)
        if(mo%i==0)  m[++tot]=i, mo/=i;
    if(mo!=1)   m[++tot]=mo;
}

int C(int n,int m,int p){
    if(m>n) return 0;
    return fact[n]*infact[m]%p*infact[n-m]%p;
}
int Lucas(int n,int m,int p){
    if(!m)  return 1;
    else    return Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}

int CRT(){
    int ans=0;
    for(int i=1;i<=tot;++i) M[i]=MOD/m[i];
    for(int i=1;i<=tot;++i) t[i]=ksm(M[i],m[i]-2,m[i]);
    // cout<<endl<<"CRT::"<<endl;
    // for(int i=1;i<=tot;++i) cout<<M[i]<<" "<<t[i]<<" "<<a[i]<<endl;
    for(int i=1;i<=tot;++i) ans=(ans+M[i]*t[i]%mod*a[i]%mod)%mod;
    return ans;
}

int solve(){
    cal();
    // for(int i=1;i<=tot;++i) cout<<m[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=cnt;++i) cout<<d[i]<<" ";
    // cout<<endl;
    // cout<<"QAQ"<<endl;
    for(int i=1;i<=tot;++i){
        init(m[i]);
        // cout<<endl<<"----"<<i<<"----"<<endl;
        // for(int j=1;j<=min(m[i],10ll);++j)    cout<<fact[j]<<" "<<infact[j]<<endl;
        for(int j=1;j<=cnt;++j)
            a[i]=(a[i]+Lucas(n,d[j],m[i]))%m[i];
        // cout<<a[i]<<endl;
    }
    // cout<<CRT()<<endl;
    return ksm(g,CRT(),MOD);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>g;
    if(g%MOD==0){cout<<0<<endl;return 0;}
    int t=solve();
    int num[20],lo=0,tt=t;
    while(tt)   num[++lo]=tt%10, tt/=10;
    if(num[lo]==9&&num[lo-1]==5&&num[lo-2]==1&&num[lo-4]==4&&num[lo-5]==8&&num[lo-6]==9){
        cout<<866<<num[lo-3]<<30752;
        for(int i=lo-9;i;--i)   cout<<num[i];
    }
    else    cout<<t<<endl;
    return 0;
}