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
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int dp[N],f[N],t[N],n,s;
int st[N], top;

double X(int x){ return f[x];}
double Y(int x){ return dp[x]-f[x]*s;}
double slope(int x,int y){ return (Y(y)-Y(x))/(X(y)-X(x));}
int lowerbound(int l,int r,double k){
    while(l<r){
        int mid=l+r>>1;
        if(Y(st[mid+1])-Y(st[mid])<=k*(X(st[mid+1])-X(st[mid]))) l=mid+1;
        else    r=mid;
    }
    return st[l];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;++i)   cin>>t[i]>>f[i];
    for(int i=1;i<=n;++i)   f[i]+=f[i-1], t[i]+=t[i-1];
    st[top=1]=0;
    for(int i=1;i<=n;++i){
        int j=lowerbound(1,top,t[i]);
        dp[i]=dp[j]+(t[i]+s)*(f[i]-f[j])+s*(f[n]-f[i]);
        while(top>1&&(Y(st[top])-Y(st[top-1]))*(X(i)-X(st[top]))>=(Y(i)-Y(st[top]))*(X(st[top])-X(st[top-1])))    --top;
        st[++top]=i;
        // cout<<t[i]<<" ";
        // for(int i=2;i<=top;++i) cout<<slope(st[i],st[i-1])<<" ";
        // cout<<endl;
    }
    // cout<<endl;
    cout<<dp[n]<<endl;
    return 0;
}