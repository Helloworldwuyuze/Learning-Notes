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
const int N = 2e6+ 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

char st[N];
int border[N], top=-1, len1, len2;
char c[N],m[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>c>>m; len1=strlen(c), len2=strlen(m);
    for(int i=0;i<len2;++i){
        st[++top]=m[i];
        if(i==0)    continue;
        int j=border[top-1];
        while(j&&st[j]!=st[top])    j=border[j-1];
        border[i]=j+(st[j]==st[top]);
    }
    st[++top]='#';
    for(int i=0;i<len1;++i){
        st[++top]=c[i];
        int j=border[top-1];
        while(j&&st[j]!=st[top])    j=border[j-1];
        border[top]=j+(st[j]==st[top]);
        if(border[top]==len2) top-=len2;
    }
    for(int i=len2+1;i<=top;++i)    cout<<st[i];
    cout<<endl;
    return 0;
}