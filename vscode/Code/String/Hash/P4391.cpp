#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<bitset>

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
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;
const int mod = 10000451;

int h[N],n,p[N],H[N],P[N];
char c[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>c;
    for(int i=n;i;--i)  c[i]=c[i-1];
    p[0]=1; P[0]=1;
    for(int i=1;i<=n;++i)   p[i]=p[i-1]*10%MOD, P[i]=P[i-1]*10%mod;
    for(int i=1;i<=n;++i)
        h[i]=(h[i-1]*10+(c[i]-'a'))%MOD, H[i]=(H[i-1]*10+(c[i]-'a'))%mod;
    for(int i=1;i<=n;++i){
        bool flag=false;
        // cout<<"###"<<h[i]<<" "<<H[i]<<endl;
        for(int j=i+1;j<=n;j+=i){
            if(n-j+1>=i&&(h[j+i-1]-h[j-1]*p[i]%MOD+MOD)%MOD!=h[i])    flag=true;
            if(n-j+1<i&&(h[n]-h[j-1]*p[n-j+1]%MOD+MOD)%MOD!=h[n-j+1])    flag=true;
            // cout<<(h[j+i-1]-h[j-1]%p[i]%MOD+MOD)%MOD<<" "<<(h[j+1-1]-h[j-1]*P[i]%mod+mod)%mod<<" "<<h[n]-h[j-1]*p[n-j+1]+MOD
        }
        if(!flag){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}