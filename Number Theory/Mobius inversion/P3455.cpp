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
const int N = 5e4 + 10;
const int M = 5e4;

int t,a,b,d;
int p[N],mu[N],cnt,s[N];

void prime(){
    mu[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   p[++cnt]=i ,mu[i]=-1;
        for(int j=1;j<=cnt&&i*p[j]<=M;++j){
            p[i*p[j]]=1;
            if(i%p[j]==0){ mu[i*p[j]]=0; break;}
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=M;++i)   s[i]=s[i-1]+mu[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    prime();
    cin>>t;
    while(t--){
        int ans=0;
        cin>>a>>b>>d; a/=d, b/=d;
        int n=min(a,b);
        for(int i=1;i<=n;++i){
            int j=min(a/(a/i),b/(b/i));
            ans+=(s[j]-s[i-1])*(a/i)*(b/i);
            i=j;
        }
        cout<<ans<<endl;
    }
    return 0;
}