#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 5e1 + 10;
const int M = 1.2e6 + 10;

int n,m,s;
int a[N],f[M];

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s+=a[i];
	}
	s-=m;
	if(s<0){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=s;j>=a[i];--j){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
	}
	cout<<s+m-f[s]<<endl;
	return 0;
}

