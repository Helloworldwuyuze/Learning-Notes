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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1.1e7 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

char c[N],s[N*2];
int len,p[N*2],ans,l,r=-1;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>(c+1);
    len=strlen(c+1);
    s[0]=s[1]='#';
    for(int i=1;i<=len;++i) s[i*2]=c[i], s[i*2+1]='#';
    len=len*2+1;
    for(int i=2;i<len;++i){
        int k=i>r?1:min(p[l+r-i],r-i+1);
        while(s[i-k]==s[i+k])   ++k;
        p[i]=k--;
        if(i+k>r)   l=i-k, r=i+k;
        ans=max(ans,p[i]);
    }
	cout<<ans-1<<endl;
    return 0;
}