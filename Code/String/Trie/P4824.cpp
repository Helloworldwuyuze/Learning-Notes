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

char c1[N],c2[N];
int n1,n2,ha[N],nxt[N],p[N];
int st[N],top;
bool f[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>(c1+1)>>(c2+1);
    n1=strlen(c1+1); n2=strlen(c2+1);
    for(int i=1;i<=n2;++i)
        ha[i]=(ha[i-1]*26+c2[i])%MOD;
    p[0]=1;
    for(int i=1;i<=n;++i)   p[i]=p[i-1]*10%MOD;
    for(int i=1;i<=n1;++i){
        if(top!=0){
            int t=st[top];
            st[++top]=(t*26+(c1[i]-'a'))%MOD;
        }else   st[++top]=c1[i]-'a';
        if(top<n2) continue;
        if((st[top]-st[top-n2]*p[n2]+MOD)%MOD+)  
    }
    return 0;
}