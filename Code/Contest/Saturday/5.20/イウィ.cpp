#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

string s;
int f[300][300];

int Len(int x,int y){
	return y-x+1;
}

bool check(int x,int y,int z){
	return s[x]=='i'&&s[y]=='i'&&s[z]=='w'&&f[x+1][z-1]==Len(x+1,z-1)&&f[z+1][y-1]==Len(z+1,y-1);
}

int main(){
	cin.tie(0), cout.tie(0);
	cin>>s;
	int siz=s.size();
//	while(s.find("iwii")!=s.npos)	s.erase(s.find("iwii"),3);
//	while(s.find("iiwi")!=s.npos)	s.erase(s.find("iiwi")+1,3);
//	while(s.find("iwi")!=s.npos)	s.erase(s.find("iwi"),3);
//	cout<<(len-s.size())/3<<'\n';
	for(int len=1;len<=siz;++len){
		for(int i=0;i+len-1<siz;++i){
			int j=i+len-1;
			for(int k=i;k<=j;++k)
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+check(i,j,k)*3);
		}
	}
	cout<<f[0][siz-1]/3<<"\n";
	return 0;
}

