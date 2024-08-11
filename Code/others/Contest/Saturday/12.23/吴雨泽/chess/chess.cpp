#include<bits/stdc++.h>

using namespace std;

const int n = 5;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int x,y,sum=0;
bool a[7][7];
bool f(int b,int c){
	return a[x+b][y+c];
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	char c;
	cin>>t;
	while(t--){
		sum=x=y=0;
		for(int i=1;i<=5;++i)
			for(int j=1;j<=5;++j)	cin>>c, a[i][j]=c=='o', sum+=a[i][j];
		bool flag=false;
		for(int i=1;i<=5;++i){
			if(flag)	break;
			for(int j=1;j<=5;++j)
				if(a[i][j]){ x=i;y=j; flag=true; break;}
		}
		switch(sum){
			case 1:{
				cout<<"Away"<<endl;
				break;
			}
			case 2:{
				cout<<"Far"<<endl;
				break;
			}
			case 3:{
				cout<<"Away"<<endl;
				break;
			}
			case 4:{
				if(f(1,0)&&f(2,0)&&f(3,0)||f(0,1)&&f(0,2)&&f(0,3)||
				   f(1,0)&&f(0,1)&&f(1,1))	cout<<"Away"<<endl;
				else	cout<<"Far"<<endl;
				break;
			}
		}
	}
	return 0;
}
//10 1 1 2 2 1 2 2 1 1 2
