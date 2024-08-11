#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
struct node
{
	int l,r,id;//id??????
};
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	deque<node> q;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		while(!q.empty()&&q.front().l>r)//????????
		{
			q.pop_front();
		}
		if(!q.empty())
		{
			ans=max(ans,i-q.front().id+1);
		}
		while(!q.empty()&&q.back().l<l)
		{
			q.pop_back();
		}
		q.push_back((node){l,r,i});
	}
	printf("%d",ans);
	return 0;
}
