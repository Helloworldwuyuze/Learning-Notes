#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

priority_queue<int> l;
priority_queue<int, vector<int>, greater<int> > r;
int len,t,n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		while(l.size())	l.pop();
		while(r.size())	r.pop();
		l.push(-INF), r.push(INF);
		while(cin>>n&&n){
			if(n==-1){
				cout<<l.top()<<endl;
				l.pop();
				if((l.size()+r.size())&1)	l.push(r.top()), r.pop();
			}else{
				if(n<=l.top()){
					l.push(n);
					if(l.size()-r.size()>=2)	r.push(l.top()), l.pop();
				}else{
					r.push(n);
					if(r.size()>l.size())	l.push(r.top()), r.pop();
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
//1 9 10 2 5 1 18 -1 -1 4 3 -1 8 7 -1 0
