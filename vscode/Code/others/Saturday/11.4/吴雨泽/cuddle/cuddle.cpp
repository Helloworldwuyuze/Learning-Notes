#include<bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;
#define int long long

int t,n,k;
int a[N];
int nxt[N],head,pre[N];

signed main(){
	freopen("cuddle.in","r",stdin);
	freopen("cuddle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)	cin>>a[i];
		if(a[1]!=1||k==0){
			cout<<1<<endl;
			return 0;
		}
		
		int pos=1,c=2,kth=0;
		bool flag=false;
		for(int i=2;i<=n;){
//			cout<<endl<<"###"<<i<<"###"<<endl;
			kth+=(a[i]-pos)/(i-1);
			pos+=(a[i]-pos)/(i-1)*(i-1);
//			cout<<pos<<" "<<kth<<endl;
			if(kth==k){
				while(pos>=a[i]&&i<=n)	++pos, ++i;
				cout<<pos<<endl;
				flag=true;
				break;
			}
			else if(kth>k){
				cout<<pos-(kth-k)*(i-1)<<endl;
				flag=true;
				break;
			}
			if(pos<a[i])	pos+=i, ++kth, ++i;
//			++i;
			else	while(pos>=a[i]&&i<=n)	++pos,++i;
			if(kth>=k){
				while(pos>=a[i]&&i<=n)	++pos,++i;
				cout<<pos<<endl;
				flag=true;
				break;
			}
//			cout<<pos<<" "<<kth<<endl;
//			cout<<"###"<<i<<"###"<<endl;
		}
		if(flag)	continue;
		cout<<pos+(k-kth)*n<<endl;
		
//		cout<<pos<<" "<<kth<<endl;
//		head=0;
//		for(int i=0;i<=N-10;++i)	nxt[i]=i+1, pre[i]=i-1;
//		nxt[N-10]=-1;
//		int mxj=0,i;
//		pos=0;
//		for(i=1;i<=k;++i){
//			cout<<endl<<"###"<<i<<"###"<<endl;
//			int cnt=0,idx=1;
//			for(int j=nxt[head];~j&&idx<=n;j=nxt[j]){
//				++cnt;
//				if(cnt==a[idx])	Remove(j), ++idx;
//				mxj=max(mxj,j);
//			}
////			for(int j=nxt[head];j<=mxj;j=nxt[j])	cout<<j<<" ";
//			cout<<nxt[head]<<endl;
//			if(nxt[head]-pos==n){
//				cout<<i<<" "<<nxt[head]<<endl;
//				return 0;
//			}
//			pos=nxt[head];
//		}
	}
	return 0;
}

