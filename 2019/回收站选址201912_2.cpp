#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
//将所有的点存入向量中，然后逐个判断，O(n^2)的复杂度，
//垃圾点不超过10^3个

vector<pii> Garbage; //存放垃圾点位置
int check[8];//判断是否四周有垃圾,前四个表示上下左右四个，后四个表示斜边四个
int score[5];//统计评分的垃圾站个数（0—4分）

bool isGarbageDump(pii g){ //判断是否是垃圾站
	pii tmp1 = make_pair(g.first-1,g.second);
	pii tmp2 = make_pair(g.first+1,g.second);
	pii tmp3 = make_pair(g.first,g.second-1);
	pii tmp4 = make_pair(g.first,g.second+1);
	for(int i = 0 ; i < (int)Garbage.size(); i++){
		if(tmp1 == Garbage[i])
			check[0] = 1;
		else if(tmp2 == Garbage[i])
			check[1] = 1;
		else if(tmp3 == Garbage[i])
			check[2] = 1;
		else if(tmp4 == Garbage[i])
			check[3] = 1;
	}
	for(int i = 0 ; i < 4 ; i++){
		if(check[i] != 1)
			return false;
	}
	return true;
}

void mark(pii g){//评分
	pii tmp1 = make_pair(g.first-1,g.second-1);
	pii tmp2 = make_pair(g.first-1,g.second+1);
	pii tmp3 = make_pair(g.first+1,g.second-1);
	pii tmp4 = make_pair(g.first+1,g.second+1);
	for(int i = 0 ; i < (int)Garbage.size(); i++){
		if(tmp1 == Garbage[i])
			check[4] = 1;
		else if(tmp2 == Garbage[i])
			check[5] = 1;
		else if(tmp3 == Garbage[i])
			check[6] = 1;
		else if(tmp4 == Garbage[i])
			check[7] = 1;
	}
	int flag = 0;
	for(int i = 4 ; i < 8 ; i++){
		if(check[i] == 1)
			flag++;
	}
	score[flag]++;
}

int main(int argc, char const *argv[])
{
	int n;//垃圾数
	scanf("%d",&n);
	int t1,t2;
	for(int i = 0; i < n ; i++){
		scanf("%d %d",&t1,&t2);
		Garbage.push_back(make_pair(t1,t2));
	}
	for(int i = 0 ; i < n; i++){ //需要注意，每次check数组都需要重置
		if(isGarbageDump(Garbage[i])){
			mark(Garbage[i]);
		}
		memset(check,0,sizeof(check));
	}
	for(int i = 0 ; i <= 4 ; i++){
		printf("%d\n",score[i]);
	}
	return 0;
}