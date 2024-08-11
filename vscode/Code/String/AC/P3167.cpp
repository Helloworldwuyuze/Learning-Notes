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
const int N = 2e5 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

char s[N], c[N];
int n, len, l[N], r[N], blk[N], idx, ln;
bool star[N];
unsigned long long H[N], h[N], p[N];
bool f[20][N];

signed main(){
//	freopen("match2.in","r",stdin);
//	freopen("match.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>(s+1); len=strlen(s+1);
//	cout<<len<<endl;
    for(int i=1;i<=len;++i){
        blk[i]=idx+1;
        if(s[i]=='*'||s[i]=='?'){
            ++idx;
            l[idx]=r[idx-1]+1;
            star[idx]=s[i]=='*';
            r[idx]=i; continue;
        }
        H[i]=H[i-1]*128+(s[i]);
    }
    if(s[len]!='*'&&s[len]!='?'){
		++idx;
		l[idx]=r[idx-1]+1, r[idx]=len;
	}
	p[0]=1;
    for(int i=1;i<=100000;++i)  p[i]=p[i-1]*128;
//     for(int i=1;i<=idx;++i)
//         cout<<l[i]<<" "<<r[i]<<" "<<star[i]<<endl;
    cin>>n;
    while(n--){
        cin>>(c+1); ln=strlen(c+1);
        // cout<<endl<<"###"<<endl;
        for(int i=1;i<=ln;++i)    h[i]=h[i-1]*128+c[i];
        // cout<<endl;
        for(int i=0;i<=idx;++i)
            for(int j=0;j<=ln;++j)  f[i][j]=false;
        f[0][0]=true;
        for(int j=0;j<=ln;++j){
//        	cout<<j<<endl;
            for(int i=0;i<=idx;++i){
                if(!f[i][j])    continue;
                if(H[r[i+1]-1]-H[l[i+1]-1]*p[r[i+1]-l[i+1]]==h[j+r[i+1]-l[i+1]]-h[j]*p[r[i+1]-l[i+1]])
                    if(star[i+1])   for(int k=j+r[i+1]-l[i+1];k<=ln;++k)    f[i+1][k]=true;
                    else    f[i+1][j+r[i+1]-l[i+1]+1]=true;
            }
//             for(int x=0;x<=idx;++x,cout<<endl)
//                 for(int y=0;y<=ln;++y)
//                     cout<<f[x][y]<<" ";
//             cout<<endl;
        }
        if(f[idx][ln])  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}
