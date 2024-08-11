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
#define bug(x) cout<<"Bug "<<#x<<"="<<(x)<<endl
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
const int N=110;
int T;
int n,m;
int a[N][N];
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    T=read();
    while(T--)
    {
        int ans=0;
        n=read();m=read();
        memset(a,0,sizeof(a));
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                a[i][j]=read();
                maxn=max(maxn,a[i][j]);
            }
        }
        for(int k=1;k<=maxn;k++)
        {

            // bug(k);

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    a[i][j]--;
                }
            }
            // for(int i=1;i<=n;i++)
            // {
            //     for(int j=1;j<=m;j++)
            //     {
            //         printf("%d ",a[i][j]);
            //     }
            //     el;
            // }
            // bug(ans);
            for(int i=2;i<n;i++)
            {
                for(int j=2;j<m;j++)
                {
                    int x=i,y=j;
                    while(a[x][y]==a[x][y+1]) y++;
                    int minn=min(a[i][j-1],a[i][y+1]);
                    for(int now=j;now<=y;now++)
                    {
                        minn=min(minn,min(a[i-1][now],a[i+1][now]));
                    }
                    // if(j==4) bug(minn);
                    if(minn>a[i][j])
                    {
                        // bug(i);bug(j);bug(minn);bug(y);
                        int tmp=a[i][j];
                        ans+=(minn-a[i][j])*(y-j+1);
                        for(int now=j;now<=y;now++)
                        {
                            // bug(now);
                            a[i][now]+=minn-tmp;
                        }
                    }
                    // bug("awa");
                    // for(int i=1;i<=n;i++)
                    // {
                    //     for(int j=1;j<=m;j++)
                    //     {
                    //         printf("%d ",a[i][j]);
                    //     }
                    //     el;
                    // }
                    
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
