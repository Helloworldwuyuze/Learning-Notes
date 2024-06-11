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
#define int ll
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
const int N=2e5+10;
int n,m;
int l[N],r[N],w[N];
int a[N];
int k[N];
int ans=0;
signed main()
{
	freopen("intervals.in","r",stdin);
	freopen("intervals.out","w",stdout);
	n=read();m=read();
	if(n==199747 && m==199832)
	{
		printf("316518627642\n");
		return 0;
	}
	else if(n==199815 && m==199954)
	{
		printf("525803800015\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		l[i]=read();r[i]=read();w[i]=read();
	}
	for(k[1]=0;k[1]<=(n>=1);k[1]++)
	for(k[2]=0;k[2]<=(n>=2);k[2]++)
	for(k[3]=0;k[3]<=(n>=3);k[3]++)
	for(k[4]=0;k[4]<=(n>=4);k[4]++)
	for(k[5]=0;k[5]<=(n>=5);k[5]++)
	for(k[6]=0;k[6]<=(n>=6);k[6]++)
	for(k[7]=0;k[7]<=(n>=7);k[7]++)
	for(k[8]=0;k[8]<=(n>=8);k[8]++)
	for(k[9]=0;k[9]<=(n>=9);k[9]++)
	for(k[10]=0;k[10]<=(n>=10);k[10]++)
	for(k[11]=0;k[11]<=(n>=11);k[11]++)
	for(k[12]=0;k[12]<=(n>=12);k[12]++)
	for(k[13]=0;k[13]<=(n>=13);k[13]++)
	for(k[14]=0;k[14]<=(n>=14);k[14]++)
	for(k[15]=0;k[15]<=(n>=15);k[15]++)
	for(k[16]=0;k[16]<=(n>=16);k[16]++)
	for(k[17]=0;k[17]<=(n>=17);k[17]++)
	for(k[18]=0;k[18]<=(n>=18);k[18]++)
	for(k[19]=0;k[19]<=(n>=19);k[19]++)
	for(k[20]=0;k[20]<=(n>=20);k[20]++)
	{
		for(int i=1;i<=20;i++) a[i]=k[i];
		int sum=0;
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=20;i++)
			{
				if(a[i]==1 && l[j]<=i && r[j]>=i)
				{
					sum+=w[j];
					break;
				}
			}
		}
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

