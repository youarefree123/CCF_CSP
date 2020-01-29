#include <bits/stdc++.h>
using namespace  std;


int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int T = 0,k = 0,p = 0;
	for (int i = 1; i <= n; ++i)
	{
		int num = 0;
		int sg = 0;
		cin>>num;
		for(int j = 1 ;j <= m ;++j){
			int tmp;
			cin>>tmp;
			sg += tmp;
		}
		T += (num+sg);
		if(abs(sg) > p){ //别忘了求绝对值
			p = abs(sg);
			k = i;
		}
	}
	cout<<T<<" "<<k<<" "<<p;
	return 0;
}
