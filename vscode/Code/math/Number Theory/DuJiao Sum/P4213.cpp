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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 5e6 + 10;
const int M = 5e6;

int mu[N],p[N],cnt;
long long phi[N];
unordered_map<int,int> sumu;
unordered_map<int,long long> sumphi;

void init(){
    mu[1]=phi[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   phi[i]=i-1, mu[i]=-1, p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=M;++j){
            p[i*p[j]]=1;
            if(i%p[j]==0){ phi[i*p[j]]=p[j]*phi[i]; break;}
            phi[i*p[j]]=phi[i]*phi[p[j]], mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=M;++i)   mu[i]+=mu[i-1], phi[i]+=phi[i-1];
}

int s1(int n){ return n;}
int seps(int n){ return n>=1;}
long long sid(long long n){ return n*(n+1)/2;}
int smu(int n){
    if(n<=M)    return mu[n];
    if(sumu[n]) return sumu[n];
    int res=0;
    for(unsigned int i=2;i<=n;++i){
        int j=n/(n/i);
        res+=(s1(j)-s1(i-1))*smu(n/i);
        i=j;
    }
    return sumu[n]=seps(n)-res;
}
long long sphi(unsigned int n){
    if(n<=M)    return phi[n];
    if(sumphi[n])   return sumphi[n];
    long long res=0;
    for(unsigned int i=2;i<=n;++i){
        unsigned int j=n/(n/i);
        res+=1ll*(s1(j)-s1(i-1))*sphi(n/i);
        i=j;
    }
    return sumphi[n]=sid(n)-res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,t;
    init();
    cin>>t;
    while(t--)  cin>>n,cout<<sphi(n)<<" "<<smu(n)<<endl;
    return 0;
}