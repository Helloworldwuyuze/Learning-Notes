#include<iostream>
#include<cstdio>
using namespace std;
const int N = 4e5 + 10;
int n,a[N],l=1;
long long x,b[N],maxx=0,sum=0,cnt=0;//���ݻ�ﵽ1e17������Ҫ��long long 
int main(){
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i+n]=a[i];//����һ�����ﵽ����Ч�� 
		b[i]=b[i+n]=a[i]*(a[i]+1)/2;//ÿ���µĹ��� 
	}
	for(int i=1;i<=n*2;++i){
		sum+=b[i], cnt+=a[i];//��i��������� 
		while(cnt-a[l]>=x)	sum-=b[l],cnt-=a[l++];//�����������ȥ���еĵ�һ����Ȼ���ڵ���x��ô����һ���Ƴ� 
		maxx=max(maxx,sum-(cnt-x)*(cnt-x+1)/2);//sum������ס����������·ݣ����ǵ�һ����ס�������ͼ���ǰ���cnt-x�� 
	}
	cout<<maxx;
	return 0;
}
