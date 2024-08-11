#include<cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=2e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int n,k,m=2147483647;
int sumj[N],sumo[N],sumi[N];
char s[N];
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;i--){
		if(s[i]=='J')sumj[i]=sumj[i+1]+1;
		else sumj[i]=sumj[i+1];
		if(s[i]=='O')sumo[i]=sumo[i+1]+1;
		else sumo[i]=sumo[i+1];
		if(s[i]=='I')sumi[i]=sumi[i+1]+1;
		else sumi[i]=sumi[i+1];
	}
	for(int j=1;j<=n-3*k+1;j++){
		if(sumj[j]<k||sumo[j]<k||sumi[j]<k)break;
		int ans=0,cntj=0,cnto=0,cnti=0;
		for(int i=j;i<=n;i++){
			if(cntj<k){
				if(s[i]!='J'){
					if(cntj==0)continue;
					else ans++;
				}
				else cntj++;
			}
			else if(cnto<k){
				if(s[i]!='O')ans++;
				else cnto++;
			}
			else if(cnti<k){
				if(s[i]!='I'){
					if(cnti==k)continue;
					else ans++;
				}
				else cnti++;
			}
		}
		if(cntj==k&&cnto==k&&cnti==k)m=min(m,ans);
	}
	if(m!=2147483647)printf("%d",m);
	else printf("-1");
	return 0;
}
