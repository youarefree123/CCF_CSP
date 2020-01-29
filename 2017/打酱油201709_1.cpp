#include <stdio.h>

int main()
{
	int N; //总钱数
	int num = 0; //可购买的酱油数
	scanf("%d",&N);
	while(N > 0){
		if(N >= 50){
			N -= 50;
			num+= 7;
		}
		else if(N >= 30){
			N -= 30;
			num += 4;
		}
		else{
			N -= 10;
			num++;
		}
	}
	printf("%d",num);
	return 0;
}