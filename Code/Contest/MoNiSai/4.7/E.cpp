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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,len;
char c[N];
int border[N],num[N],all[N],nxt[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    while(n--){
        cin>>c; len=strlen(c);
        for(int i=1;i<len;++i){
            int j=nxt[i-1];
            while(c[i]!=c[j]&&j)    j=nxt[j-1];
            j+=(c[i]==c[j]); nxt[i]=j;
            if(j)   all[i]=all[j-1]+1;
            else    all[i]=0;
        }
        for(int i=1;i<len;++i){
            int j=border[i-1];
            while((c[i]!=c[j]||(j+1)*2>i+1)&&j)    j=nxt[j-1];
            j+=(c[i]==c[j]); border[i]=j;
            if(j)   num[i]=all[j-1]+1;
            else    num[i]=0;
        }
        int ans=1;
        for(int i=0;i<len;++i)    ans=(ans*(num[i]+1))%MOD;
        cout<<ans<<endl;
    }
	return 0;
}