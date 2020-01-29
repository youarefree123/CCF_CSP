/*201312-1

试题名称：	出现次数最多的数
时间限制：	1.0s
内存限制：	256.0MB
问题描述：	
问题描述
　　给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
输入格式
　　输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
　　输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。
输出格式
　　输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
样例输入
6
10 1 10 20 30 20
样例输出
10

*/

#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace  std;


void printArray(int *a){
	for(int i = 0 ; i < 5 ; i++){
		cout<<a[i]<<" ";
	}
}

int main(int argc, char const *argv[])
{
	int n; //数字的个数 
	int ans_num = 0;
	int ans_rank = 0;
	int answer[10001];
	memset(answer,0,sizeof(answer));
	cin>>n;
	int num[n]; //存放各个元素
	for(int i = 0 ; i < n ; i++){
		cin>>num[i];
	}

	for(int i = 0 ; i < n ; i++){
		int tp = num[i];
		answer[tp]++;
	}
	for(int i = 0 ; i <= 10000 ; i++){
		if(ans_rank < answer[i]){
			ans_rank =  answer[i];
			ans_num = i;
		}
	}
	cout<<ans_num;
	return 0;
}