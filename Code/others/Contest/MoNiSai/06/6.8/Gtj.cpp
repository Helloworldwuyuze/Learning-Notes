#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template <typename T>
inline void read(T &x){
    x=0;char ch=getchar();bool f=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(f)x=-x;
}
template <typename T,typename ...Args>
inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
const int N = 5e5 + 5;
const int mod = 998244353;
inline void add(int &x,int y){
    if((x += y) >= mod)x -= mod;
}
vector<int>S;
int dp[N][2],s[N][2];
int a[N],n;
signed main(){
    read(n);
    rep(i,1,n)read(a[i]);
    dp[0][0] = s[0][0] = 1;
    rep(i,1,n){
        while(!S.empty() && a[S.back()] >= a[i])S.pop_back();
		if(!S.empty())	cout<<S.back()<<endl;
		else	cout<<-1<<endl;
        if(S.empty()){
            for(int x : {0,1})dp[i][x] = 1ll * s[i - 1][x ^ 1] * a[i] % mod;
        }
        else{
            for(int x : {0,1})dp[i][x] = (dp[S.back()][x] + 1ll * (s[i - 1][x ^ 1] - s[S.back() - 1][x ^ 1] + mod) * a[i] % mod) % mod;
        }
        S.push_back(i);
        s[i][0] = (s[i - 1][0] + dp[i][0]) % mod;
        s[i][1] = (s[i - 1][1] + dp[i][1]) % mod;
		cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<s[i][0]<<" "<<s[i][1]<<endl;
    }
    int ans = (dp[n][0] - dp[n][1] + mod) % mod;
    if(n & 1)ans = 1ll * ans * (mod - 1) % mod;
    printf("%d",ans);
}