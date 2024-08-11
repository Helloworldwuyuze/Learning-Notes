#include<bits/stdc++.h>
using namespace std;

int main(){
	srand((unsigned)time(NULL));
	freopen("F.in","w",stdout); 
	cout<<3000<<" "<<3000<<endl;
	for(int i=1;i<=3000;++i){
		for(int j=1;j<=3000;++j){
//			cout<<(char)(rand()%26+'a');
			cout<<"a";
		}
		cout<<endl;
	}
	return 0;
}
