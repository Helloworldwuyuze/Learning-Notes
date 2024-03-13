#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int n,k,ans=1e9+7;
string s;
bool pd(int x){
	int m=k,q=0;
	for(int i=x;i<n;i++){
		if(s[i]=='J')m--;
		if(m==0){
			q=i+1;
			break;
		}
	}
	//cout<<q<<endl;
	if(m>0)return false;
	int l=0;m=k;
	for(int i=q;i<n;i++){
		if(s[i]=='O')m--;
		if(m==0){
			l=i+1;
			break;
		}
	}
	//cout<<l<<endl;
	if(m>0)return false;
	int w=0;m=k;
	for(int i=l;i<n;i++){
		if(s[i]=='I')m--;
		if(m==0){
			w=i+1;
			break;
		}
	}
	//cout<<w<<endl;
	if(m>0)return false;
	return true;
}
int cheak(int x){
	int ans=0,q=x,m=k;
	while(1){
		if(s[q]=='J')m--;
		if(m==0){
			q++;break;
		}
		if(s[q]!='J'){
			ans++;
		}
		q++;
	}
	m=k;
	while(1){
		if(s[q]=='O')m--;
		if(m==0){
			q++;break;
		}
		if(s[q]!='O'){
			ans++;
		}
		q++;
	}
	m=k;
	while(1){
		if(s[q]=='I')m--;
		if(m==0){
			q++;break;
		}
		if(s[q]!='I'){
			ans++;
		}
		q++;
	}
	return ans;
}
int main(){
	freopen("joi.in","r",stdin);
	freopen("joi.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='J')continue;
		if(!pd(i))break;
		ans=min(ans,cheak(i));
	}
	if(ans==1e9+7)puts("-1");
	else cout<<ans<<endl;
	return 0;
}
