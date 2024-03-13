#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define bug(x) cout<<"Bug "<<(x)<<endl
#define el putchar('\n')
#define sp putchar(' ')
using namespace std;
int read()
{
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
const int N=4e3+10;
int n;
int a[N];
int dp[N][N];
int ans=0;
int main()
{
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        a[i+n]=a[i];
    }
    a[0]=a[n];
    for(int i=1;i<=n*2;i++) dp[i][i]=a[i];
    for(int len=2;len<=n;len++)
    {
        for(int l=2;l+len-1<=n*2;l++)
        {
            int r=l+len-1;
            if(len%2==1) dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
            else
            {
                if(a[l]>=a[r+1]) dp[l][r]=max(dp[l][r],dp[l+1][r]);
                if(a[l-1]<=a[r]) dp[l][r]=max(dp[l][r],dp[l][r-1]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][i+n-1]);
    }
    printf("%d\n",ans);
    return 0;
}