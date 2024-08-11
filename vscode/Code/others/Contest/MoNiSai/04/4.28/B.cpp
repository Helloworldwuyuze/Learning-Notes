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
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int MOD = 1e9 + 7;

string s, t, c;
int k, lens, lent, lenc, ans;
int f[N], border[N<<1], g[N];
bool flag=false;

int ksm(int x,int m){
    int ans=1;
    while(m){
        if(m&1) ans=ans*x%MOD;
        x=x*x%MOD, m>>=1;
    }
    return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>s>>t>>k; c=t+"#"+s+s;
    lens=s.size(), lent=t.size(), lenc=c.size();
    if(lens!=lent){ cout<<0<<endl; return 0;}
    if(k==0){cout<<(s==t)<<endl; return 0;}
    for(int i=1;i<lens;++i)
        if(s[i]!=s[i-1])    flag=true;
    for(int i=1;i<lenc-1;++i){
        int j=border[i-1];
        while(j&&c[j]!=c[i])    j=border[j-1];
        border[i]=j+(c[j]==c[i]);
    }
    f[0]=0; f[1]=1;
    for(int i=2;i<=k;++i) f[i]=(ksm(lens-1,i-1)-f[i-1]+MOD)%MOD;
    g[0]=1, g[1]=0;
    for(int i=2;i<=k;++i)   g[i]=(ksm(lens-1,i-1)-g[i-1]+MOD)%MOD;
    // for(int i=0;i<=k;++i)   cout<<f[i]<<" ";
    // cout<<endl;
    for(int i=lens+1;i<lenc-1;++i){
        if(!flag&&border[i]==lens){ cout<<ksm(lens-1,k)<<endl; return 0;}
        if(border[i]==lens&&i-lens+1==lens+1)  ans=(ans+g[k])%MOD;
        else if(border[i]==lens) ans=(ans+f[k])%MOD;
    }
    cout<<ans<<endl;
	return 0;
}

