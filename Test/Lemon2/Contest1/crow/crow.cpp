#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[100005];
int n,m;
bool vis[100005],use[100005];
vector<int>v[100005];
vector<int>e[100005];
bool dfs(int fa)
{
	vis[fa]=1;
	use[fa]=1;
	for(int i=0;i<v[fa].size();i++)
	{
		int y=v[fa][i];
		int z=e[fa][i];
		if(d[y]>d[fa]+z)
		{
			if(vis[y])return 1;
			d[y]=d[fa]+z;
			if(dfs(y))return 1;
		}
	}
	vis[fa]=0;
	return 0;
}
ofstream infile,outfile;
signed main()
{
	freopen("crow16.in","r",stdin);
	freopen("crow16.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	for(int k=1;k<=1;++k){
//		char inname[11], outname[12];
//		sprintf(inname,"crow01.in",k);
//		sprintf(outname,"crow01.out",k);
//		cout<<inname<<endl;
//		infile.open(inname);
//		outfile.open(outname);
//		infile<<t;
//		cout<<t<<endl;
		int times=clock();
		int t;
		cin>>t;
		while(t--){
			cin>>n>>m;
//			cout<<n<<" "<<m<<endl;
//			cout<<n<<" "<<m<<endl;
			for(int i=1;i<=n;i++)
			{
				d[i]=20000000000000000ll;
				vis[i]=use[i]=false;
				v[i].clear(), e[i].clear();
			}
			for(int i=1;i<=m;i++)
			{
				int x,y,z;
				cin>>x>>y>>z;
				v[x].push_back(y);
				e[x].push_back(z);
				v[y].push_back(x);
				e[y].push_back(-z);
			}
			bool ok=0;
			for(int i=1;i<=n;i++)
			{
				if(!use[i])//没走过就走
				{
					d[i]=0;
					if(dfs(i))
					{
						ok=1;
					}
				}
			}
			if(ok)	cout<<"N0"<<endl;
			else	cout<<"AC"<<endl;
//			return 0;
		}
		cerr<<clock()-times;
//		infile.close(), outfile.close();
//	}
	return 0;
}
