#include <bits/stdc++.h>
using namespace std;
struct Node  
{   // 结构体，从左到右，代表何时开始何时结束
	int l;
	int r;
};
//求更小者
int min1(int a , int b){
	return a<=b?a:b;
}
//求更大者
int max1(int a , int b){
	return a>=b?a:b;
}

int main(int argc, char const *argv[])
{
	int n; //买n次菜
	int sum = 0 ; //用来记录求得的时间
	cin>>n; //输入n
	struct Node h[n],w[n]; //两个结构体数组h,w 代表小H,小W
	//输入小H的装车时间段
	for(int i = 0 ; i <= n-1 ; i++)
		scanf("%d %d",&h[i].l,&h[i].r);
	//输入小W的装车时间段
	for(int i = 0 ; i <= n-1 ; i++)
		scanf("%d %d",&w[i].l,&w[i].r);
	for(int i = 0 ; i <= n-1 ; i++)
	{
		for(int j = 0 ; j <= n-1 ; j++)
		{
			//如果他们之间有相交的时间，则sum += 该时间
			if ((min1(h[i].r , w[j].r) - max(h[i].l , w[j].l))>0){
				sum = sum + min1(h[i].r , w[j].r) - max(h[i].l , w[j].l) ;
			}
		}
	}
	printf("%d",sum);	
	return 0;
}
