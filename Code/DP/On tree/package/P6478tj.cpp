#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
using namespace std;
#define MAXN 5006
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
#define P 998244353
int n;
int A[MAXN];

int head[MAXN] , to[MAXN << 1] , nex[MAXN << 1] , ecn;
void ade( int u , int v ) {
    to[++ ecn] = v , nex[ecn] = head[u] , head[u] = ecn;
}

int dp[MAXN][MAXN] , siz[MAXN] , sz[MAXN];
int pd[MAXN];
void dfs( int u , int fa ) {
    siz[u] = 1 , sz[u] = A[u];
    dp[u][0] = 1;
    for( int i = head[u] , v ; i ; i = nex[i] ) {
        v = to[i];
        if( v == fa ) continue;
        dfs( v , u );
        rep( k , 0 , siz[u] + siz[v] ) pd[k] = 0;
        rep( j , 0 , min( siz[u] , n / 2 ) ) if( dp[u][j] )
            rep( k , 0 , min( siz[v] , n / 2 - j ) ) if( dp[v][k] )
                pd[j + k] = ( pd[j + k] + dp[u][j] * 1ll * dp[v][k] % P ) % P;
        rep( k , 0 , siz[u] + siz[v] ) dp[u][k] = pd[k];
        siz[u] += siz[v] , sz[u] += sz[v];
    }
    per( i , min( sz[u] , siz[u] - sz[u] ) , 1 ) dp[u][i] = ( dp[u][i] + dp[u][i - 1] * 1ll * ( ( A[u] ? ( siz[u] - sz[u] ) : ( sz[u] ) ) - ( i - 1 ) ) % P ) % P;
}

int J[MAXN] , iJ[MAXN];
int Pow( int x , int a ) {
    int ret = 1;
    while( a ) {
        if( a & 1 ) ret = 1ll * ret * x % P;
        x = 1ll * x * x % P , a >>= 1;
    }
    return ret;
}
int C( int a , int b ) {
    return J[a] * 1ll * iJ[b] % P * iJ[a - b] % P;
}

void solve() {
    cin >> n;
    J[0] = iJ[0] = 1;
    rep( i , 1 , MAXN - 1 ) J[i] = J[i - 1] * 1ll * i % P , iJ[i] = Pow( J[i] , P - 2 );
    rep( i , 1 , n )
        scanf("%1d",A + i);
    int u , v;
    rep( i , 2 , n ) scanf("%d%d",&u,&v) , ade( u , v ) , ade( v , u );
    dfs( 1 , 1 );
	rep(i, 1, n){
		rep(j, 0, siz[i])	printf("%d ", dp[i][j]);
		printf("\n");
	}
    int re = 0;
    rep( i , 0 , n / 2 + 1 ) dp[1][i] = dp[1][i] * 1ll * J[n / 2 - i] % P;
    rep( i , 0 , n / 2 ) {
        re = 0;
        rep( j , i , n / 2 )
            re += C( j , i ) * 1ll * ( ( j - i & 1 ) ? P - 1 : 1 ) % P * dp[1][j] % P , re %= P;
        printf("%d ",re);
    }
}

signed main() {
//    freopen("match.in","r",stdin);
//    freopen("match.out","w",stdout);
//    int T;cin >> T;while( T-- ) solve();
    solve();
}