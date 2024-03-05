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
const int N = 3e3 + 10;
const int M = 1e6 + 10;

int k[N],l[N],r[N],f[N][N];
int n,idx,x,y;

int check(int a,int b,int k){
    return l[k]>=a&&r[k]<=b; 
}
int dfs(int a,int b){
    if(a>b) return 0;
    if(f[a][b]==INF)    f[a][b]=max(check(a,b,k[a])-dfs(a+1,b),check(a,b,k[b])-dfs(a,b-1));
    return f[a][b];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>k[i];
        if(!l[k[i]])   ++idx, l[k[i]]=i;
        r[k[i]]=i;
    }
    memset(f,0x3f,sizeof(f));
    dfs(1,n);
    int a=(idx+f[1][n])/2, b=idx-a;
    cout<<a<<":"<<b<<endl;
    return 0;
}