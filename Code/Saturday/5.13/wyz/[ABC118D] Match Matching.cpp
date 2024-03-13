#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
int n,m,minn;
int a[N];
const int pay[]={0,2,5,5,4,5,6,3,7,6};
int f[N];

int main(){
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=m;++i){
		for(int j=pay[a[i]];j<=n;++j){
			f[j]=max(f[j],f[j-pay[a[i]]]+1);
		}
	}
	sort(a+1,a+1+m);
	for(int i=f[n];i>0;--i){
		for(int j=m;j>0;--j){
			if(f[n]==f[n-pay[a[j]]]+1&&n-pay[a[j]]>=0){
				n-=pay[a[j]];
				cout<<a[j];
				break;
			}
		}
	}
	return 0;
}
