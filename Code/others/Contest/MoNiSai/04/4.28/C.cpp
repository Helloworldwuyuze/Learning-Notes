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

int n,m,t[N],a[40],b[40],cnt=0,ans;
string op[N];
bool lim=true;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>op[i]>>t[i];
    cnt=0;
    while(m)    a[++cnt]=m%2, m>>=1;
    for(int i=35;i;--i){
        int top=lim?a[i]:1;
        for(int j=0;j<=top;++j){
            int x=j;
            for(int k=1;k<=n;++k){
                // cout<<x<<" ";
                if(op[k]=="AND")    x&=((t[k]>>i-1)&1);
                else if(op[k]=="OR")    x|=((t[k]>>i-1)&1);
                else    x^=((t[k]>>i-1)&1);
            }
            if(x!=0){
                ans+=1<<i-1;
                if(!j&&a[i])    lim=false;
                break;
            }
            if(j==1)    lim=false;
        }
    }
    cout<<ans<<endl;
	return 0;
}

