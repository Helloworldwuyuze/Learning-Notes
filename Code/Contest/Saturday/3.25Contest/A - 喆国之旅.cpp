#include<iostream>
#include<cstdio>
using namespace std;
const int N = 4e5 + 10;
int n,a[N],l=1;
long long x,b[N],maxx=0,sum=0,cnt=0;//数据会达到1e17的量，要开long long 
int main(){
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i+n]=a[i];//复制一遍链达到环的效果 
		b[i]=b[i+n]=a[i]*(a[i]+1)/2;//每个月的贡献 
	}
	for(int i=1;i<=n*2;++i){
		sum+=b[i], cnt+=a[i];//将i点加入序列 
		while(cnt-a[l]>=x)	sum-=b[l],cnt-=a[l++];//如果总天数减去序列的第一天仍然大于等于x那么将第一个移除 
		maxx=max(maxx,sum-(cnt-x)*(cnt-x+1)/2);//sum里面是住满序列里的月份，但是第一个月住不满，就减掉前面的cnt-x天 
	}
	cout<<maxx;
	return 0;
}
