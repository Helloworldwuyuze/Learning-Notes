#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e2 + 10;
const int M = 1e5 + 10;

int n,k,minn=0x3f3f3f3f;
int a[N];
bool f[M];

int main(){
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		f[a[i]]=true;
		minn=min(minn,a[i]);
	}
	for(int i=0;i<minn;++i)	f[i]=false;
	for(int i=1;i<=k;++i){
		bool flag=false;
		for(int j=1;j<=n;++j){
			if(i-a[j]>=0&&f[i-a[j]]==false)	flag=true;
		}
		f[i]=flag;
	}
	cout<<(f[k]?"First":"Second");
	return 0;
}

