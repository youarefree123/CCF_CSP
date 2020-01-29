#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n ; //商贩数
	int temp; //临时变量
	cin>>n;
	int num1[n],num2[n];
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&temp);
		num1[i] = temp;
	}
	num2[0] = (num1[0]+num1[1])/2;
	num2[n-1] = (num1[n-1]+num1[n-2])/2;
	for(int i = 1 ; i < n-1 ; i++)
		num2[i] = (num1[i-1]+num1[i]+num1[i+1])/3;
	for(int i = 0 ; i <= n-1 ; i++)
	{
		printf("%d ",num2[i]);
	}
	return 0;
}

// 100分