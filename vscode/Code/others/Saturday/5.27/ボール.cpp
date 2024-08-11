#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>

using namespace std;

const int N = 16+2;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n,x;
double f[1<<N];

bool check_0(int s,int i){
	return !(s&(1<<i));
}
void ejzsc(int s){
	while(s){
		cout<<(s&1);
		s>>=1;
	}
	cout<<endl;
}

double dfs(int s){
	if(s==0)	return f[s]=0;
	if(f[s]!=INF)	return f[s];
	for(int i=1;i<=16;++i){
		int a=s&(~(1<<(i-1))),b=s&(~(1<<(i))),c=s&(~(1<<(i+1))),cnt=3;
		cnt-=(a==s)+(b==s)+(c==s);
		f[s]=min(f[s],(1+((a!=s?dfs(a):0)/3.0)+((b!=s?dfs(b):0)/3.0)+((c!=s?dfs(c):0)/3.0))*3.0/cnt);
	}
	return f[s];
}

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n;
	int fir=0;
//	memset(f,-1,sizeof(f));
	for(int i=0;i<=1<<16;++i)	f[i]=INF;
	for(int i=1;i<=n;++i){
		cin>>x;
		fir|=(1<<(x));
	}
	printf("%.9lf\n",dfs(fir));
	return 0;
}

