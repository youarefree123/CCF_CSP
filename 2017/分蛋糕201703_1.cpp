#include <bits/stdc++.h>
#define MAXM 1002
using namespace std;
int cake[MAXM];
int n,k;

int main(int argc, char const *argv[])
{
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		scanf("%d",&cake[i]);
	}
	int ans = 0;
	int tmp = 0;
	for(int i = 0; i < n ;i++){
		if(tmp >= k){
			ans++;
			tmp = 0;
		}
		tmp += cake[i];
	}
	if(tmp > 0)
		ans++;
	cout<<ans<<endl;
	return 0;
}
