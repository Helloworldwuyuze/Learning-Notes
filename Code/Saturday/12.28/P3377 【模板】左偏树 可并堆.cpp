#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,m,belong[N];
typedef pair<int,int> PII;
#define mk(x,y) make_pair(x,y)
priority_queue<PII, vector<PII>, greater<PII> > q[N];
bool bd[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;++i)	cin>>x, q[i].push(mk(x,i)), belong[i]=i;
	for(int i=1,op,x,y;i<=m;++i){
		cin>>op;
		if(op==1){
			cin>>x>>y;
			if(bd[x]||bd[y])	continue;
			int xx=belong[x], yy=belong[y];
			if(belong[x]==belong[y])	continue;
			if(q[xx].size()<q[yy].size())	swap(xx,yy), swap(x,y);
			while(q[yy].size()){
				q[xx].push(q[yy].top());
				belong[q[yy].top().second]=xx;
				q[yy].pop();
			}
		}else{
			cin>>x;
			if(bd[x]){ cout<<-1<<endl; continue;}
			int xx=belong[x];
			cout<<q[xx].top().first<<endl;
			bd[q[xx].top().second]=true;
			q[xx].pop();
		}
	} 
	return 0;
}

