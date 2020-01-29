#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int sum = 0 ; //最后得分
	int n1,n2; //n2代表这一步的状态（0，1，2），n1代表上一步状态
	int con = 1; //连续得分计数器
	n1 = 1; //初始状态下n1假定是没有跳到中心
	scanf("%d",&n2); //输入本次跳的状态
	while(n2 != 0){ 
		//如果上一次没有跳到中心，那sum只加1
		if(n2 == 1 && n1 == 1) 
			sum += 1;
		//如果上一次跳到中心，这一次没有，说明连续得分断了，
		//除了sum只加1外，连续计数器也要归1
		else if(n2 == 1 && n1 == 2){
			sum += 1;
			con = 1;
		}
		//如果上一次没有在中心，这一次在，sum+2
		else if(n2 == 2 && n1 == 1)
			sum += 2;
		//如果这次和上次都在中心，则代表连续得分，计数器++，并加相应的分
		else if(n2 == 2 && n1 == 2){
			con++;
			sum += con*2;
		}
		n1 = n2; //这次的状态就为上一次的
		scanf("%d",&n2); //输入下一次的状态，作为循环条件
	}
	printf("%d",sum);
	return 0;
}


//100分


