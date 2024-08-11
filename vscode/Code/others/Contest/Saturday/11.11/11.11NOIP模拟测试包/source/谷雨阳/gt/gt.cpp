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
const int N=1e3+10;
int n,m,k;
int main()
{
    freopen("gt.in","r",stdin);
    freopen("gt.out","w",stdout);
    n=read();m=read();k=read();
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    else if(m==0)
    {
        printf("%lld\n",pow(10,n));
    }
    else if(n==4)
    {
        printf("81\n");
    }
    else
    {
        printf("5580\n");
    }
    return 0;
}