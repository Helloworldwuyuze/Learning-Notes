#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("relative444.in","w",stdout);
	int n=20;
	int m=100;
	printf("%d %d\n",n,m); 
	for(int i=1; i<=n; i++)printf("%d ",rand()%200000-100000);
	printf("\n");
	for(int i=1; i<=n; i++)printf("%d ",rand()%200000-100000);
	while(m--){
		int op=rand()%3;
		if(!op){
			printf("1 ");
			int l=rand()%n+1,r=rand()%(n-l+1)+l;
			printf("%d %d\n",l,r);
		}else if(op==2){
			printf("3 ");
			int l=rand()%n+1,r=rand()%(n-l+1)+l;
			printf("%d %d %d %d\n",l,r,rand()%200000-100000,rand()%200000-100000);
		}else{
			printf("2 ");
			int l=rand()%n+1,r=rand()%(n-l+1)+l;
			printf("%d %d %d %d\n",l,r,rand()%200000-100000,rand()%200000-100000);
		}
	}
	return 0;
} 
