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
const int N = 1e5 + 10;
const int M = 1e6 + 10;
typedef unsigned int uit;

const int MAXN = 20000010;

inline uit fsp(uit x, int k) {
	uit s = 1;
	while(k) {
		if(k & 1) s *= x;
		x *= x, k >>= 1;
	} return s;
}

int tot;
int pri[MAXN / 10];
bitset<MAXN>chk;
uit f[MAXN];
uit F[MAXN];

void Sieve(int maxn,int k){
    f[1]=F[1]=chk[1]=1;
    for(int i=2;i<=maxn;++i){
        if(!chk[i])   pri[++pri[0]]=i, f[i]=i-1, F[i]=fsp(i,k);
        for(int j=1;j<=pri[0]&&i*pri[j]<=maxn;++j){
            chk[i*pri[j]]=1, F[i*pri[j]]=F[i]*F[pri[j]];
            if(i%pri[j]==0){
                if(i/pri[j]%pri[j]) f[i*pri[j]]=-pri[j]*f[i/pri[j]];
				break;
            }
            f[i*pri[j]]=(pri[j]-1)*f[i];
        }
    }
    for(int i=2;i<=maxn;++i)   f[i]=(f[i-1]+f[i]*F[i]), F[i]=(F[i]+F[i-1]);
    for(int i=2;i<=maxn;++i)   F[i]=(F[i]+F[i-1]);
}

inline uit Calc(int n) { return F[n << 1] - (F[n] << 1); }

int main() {
	int Case, N, k;
    cin>>Case>>N>>k;
	Sieve(N << 1, k);
	while(Case--) {
		uit res = 0;
		int n;
        cin>>n;
		for(int l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			res += (f[r] - f[l - 1]) * (F[(n/l)<<1]-(F[n/l]<<1));
		} cout << res << "\n";
	}
	return 0;
}