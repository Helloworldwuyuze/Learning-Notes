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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int MOD1 = 1e9 + 7;
const int MOD2 = 233;


map<int,int> m1,m2;
int n,b[N],c[N], ans;
char a[N][N];

void read(int &x,int MOD,int i){
    x=0;
    int len=strlen(a[i]+1);
    for(int j=1;j<=len;++j)
        x=(x*10+a[i][j]-'0')%MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>(a[i]+1);
    for(int i=1;i<=n;++i)   read(b[i],MOD1,i), read(c[i],MOD2,i), m1[b[i]]++, m2[c[i]]++;
    // for(int i=1;i<=n;++i)   cout<<b[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;++i)   cout<<c[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(m1[b[i]*b[j]%MOD1]!=0&&m2[c[i]*c[j]%MOD2]!=0){
                ans+=min(m1[b[i]*b[j]%MOD1],m2[c[i]*c[j]%MOD2]);
            }
    cout<<ans<<endl;
    return 0;
}