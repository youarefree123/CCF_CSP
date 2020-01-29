#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{

	int n  ; // 输入整数的个数
	int ans; 
	scanf("%d",&n);
	int a[n];
	for(int i = 0 ; i <= n-1 ; i++){
		scanf("%d",&a[i]);
	}
	sort(a , a+n);
	ans = a[1] - a[0];
 	for(int i = 0 ; i <= n-2 ; i++){
        	ans = a[i+1]-a[i] < ans ? (a[i+1]-a[i]): ans;
	}
	printf("%d\n",ans);
	return 0;
}
//100 分
