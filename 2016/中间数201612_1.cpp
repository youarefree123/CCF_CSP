#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int key = -1;
	cin>>n;
	int num[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int half = num[(n-1)/2];
	int tmp1 = 0;
	for(int i = 0; i < (n-1)/2; i++){
		if(num[i] < half)
			tmp1++;
	}
	int tmp2 = 0;
	for(int i = (n-1)/2+1; i < n; i++){
		if(half < num[i])
			tmp2++;
	}
	if(tmp1 == tmp2)
		key = half;
	cout<<key;
	return 0;
}

