#include <bits/stdc++.h>
using namespace std;
const int MAXM = 10001;
int num[MAXM];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int tmp;
	for(int i = 0; i < n; i++){
		scanf("%d",&tmp);
		num[i] = tmp;
	}
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if(i != n-1){
			if((num[i-1] < num[i] && num[i+1] < num[i])|| (num[i-1] > num[i] && num[i+1] > num[i])){
					ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
