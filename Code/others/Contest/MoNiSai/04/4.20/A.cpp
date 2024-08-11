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

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 998244353;

int n,k;
int a[N], q[N], fr, re, minn[N], mx[N], f[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)   cin>>a[i];
    fr=1;
    for(int i=n;i;--i){
        while(fr<=re&&a[q[re]]>=a[i])   --re;
        q[++re]=i;
        if(n-i+1<k)    continue;
        while(fr<=re&&q[fr]-i>=k)   ++fr;
        minn[i]=a[q[fr]];
    }
    fr=1;
    for(int i=1;i<=n;++i){
        while(fr<=re&&minn[q[fr]]<=minn[i]) --re;
        q[++re]=i;
        while(fr<=re&&i-q[fr]>=k)   ++fr;
        mx[i]=minn[q[fr]];
        // cout<<mx[i]<<" ";
    }
    // cout<<endl;
    long long sum=0, len=0;
    for(int i=1;i<=n;++i)
        sum+=a[i]-mx[i];
    cout<<sum<<endl;
    sum=0;
    for(int i=1;i<=n;++i){
        if(mx[i]==mx[i-1]){
            ++len;
            if(len==k)  f[i]=f[i-k]+1, len=0;
            else    f[i]=f[i-1];
        }else   len=0, f[i]=f[i-1]+1;
    }
    // if(len!=0)  ++f[n];
    cout<<f[n]<<endl;
	return 0;
}

