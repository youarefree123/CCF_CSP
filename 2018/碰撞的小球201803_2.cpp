#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n , L , t ; //小球个数，线段长度 运动时间
	scanf("%d %d %d",&n,&L,&t);
	int a[n+2] ; // 存放小球最后的位置信息
	int b[n+2] ; //保存最开始的位置信息
	int flag[n+2]; //变换方向的标志位
	int x[n+2] ; //记录下标的信息

	//给flag[i]赋值，表示此时该小球的运动方向
	for(int i = 1 ; i <= n; i++){
		flag[i] = 1;
	}
	// 设置边界值 最小是0，最大和线端长一样，L
	a[0] = 0 ; b[0] = 0 ; 
	b[n+1] = L;	a[n+1] = L;

	//输入小球的位置信息，并保存在a b 数组中
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(a,a+n+1); //将a数组按照升序排序

	//利用x数组记录排序以后a数组和b数组之间的位置关系
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			if(b[i] == a[j])
				x[i] = j;
		}
	}

	//程序核心部分，模拟小球的运动轨迹
	for(int i = 1 ; i <= t ;i++){ //第一层循环是时间上的迭代，时间走了1s
		for(int j = 1 ; j <= n ; j++)  
			a[j] += flag[j];  //每一个小球在这1s朝着运动方向走了一步
		
		//判断如果某个小球与前一个或者后一个小球发生碰撞（位置重合）
		//则需要改变下一个时间段运动方向
		for(int j = 1 ; j<= n ; j++){ 
			if(a[j] == a[j+1] || a[j] ==a[j-1]){
				flag[j] = -flag[j];
			}
		}

	}
	//按照原来位置进行输出
	for(int i = 1 ; i <= n ;i++){
		printf("%d ",a[x[i]]);
	}
	return 0;
}
