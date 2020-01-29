#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace  std;

int main(int argc, char const *argv[])
{
	int n,k,temp; //temp值还有多少个小朋友
	int num = 0;
	scanf("%d %d",&n,&k);
	int x[n]; // 存放小朋友
	temp = n;
	memset(x,0,sizeof(x)); // memset并不能赋值1
	if(k == 1) {
		printf("%d",n);
		return 0;
	}
	for(int i = 0 ;temp != 1;i++){
		if(i > n-1) i = 0;
		if(x[i] == -1) continue;
		num++;
		if( num%k == 0|| num%10 == k){  //我tm是不是傻，这种条件都能错
			temp--;
			x[i] = -1;
		}
	}

	for(int i = 0 ; i < n ;i++){
		if(x[i] != -1){
			printf("%d ",i+1);	
		}
	}
	return 0;
}

//90分，一个点没过
