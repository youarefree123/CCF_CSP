/*201312-3
试题名称：	最大的矩形
时间限制：	1.0s
内存限制：	256.0MB
问题描述：	
问题描述
　　在横轴上放了n个相邻的矩形，每个矩形的宽度是1，而第i（1 ≤ i ≤ n）个矩形的高度是hi。这n个矩形构成了一个直方图。例如，下图中六个矩形的高度就分别是3, 1, 6, 5, 2, 3。



　　请找出能放在给定直方图里面积最大的矩形，它的边要与坐标轴平行。对于上面给出的例子，最大矩形如下图所示的阴影部分，面积是10。

输入格式
　　第一行包含一个整数n，即矩形的数量(1 ≤ n ≤ 1000)。
　　第二行包含n 个整数h1, h2, … , hn，相邻的数之间由空格分隔。(1 ≤ hi ≤ 10000)。hi是第i个矩形的高度。
输出格式
　　输出一行，包含一个整数，即给定直方图内的最大矩形的面积。
样例输入
6
3 1 6 5 2 3
样例输出
10

*/


#include <stdio.h>
#include <stdlib.h>


int search(int *a,int n,int* maxi){
	int max = 0; 
	int i = 0, j = 0;
	while(i < n){
		if(max < a[i]){
			j = 0;
			max = a[i];
			maxi[j++] = i++;
		}
		else if(max == a[i]){
			maxi[j++] = i++;
		}
		else i++;

	}

	return max;
}

int main(int argc, char const *argv[])
{
	int n ; //矩形数量
	scanf("%d",&n);
	int rectangle[n] ; //记录各矩形的高度
	int maxi[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&rectangle[i]);
	}
	int jj = 0;
	int max = search(rectangle,n,maxi);
	while(rectangle[maxi[jj]] == max){
		printf("%d\n",maxi[jj++]);
	}
	return 0;
}