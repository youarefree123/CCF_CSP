#include <bits/stdc++.h>
using namespace std;

//利用到了c++ 11 中新增的 to_string()方法

bool check(int key){
	if(key%7 == 0)
		return false;
	string s = to_string(key);
	for(unsigned int i = 0 ; i < s.size(); i++){
		if(s[i] == '7')
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int person[4];
	memset(person,0,sizeof(person));
	int n;
	int flag = 1; //记录现在是由哪个人报数，从0开始
	cin>>n;
	while(n > 0){
		if(check(flag)){ //如果检查通过，报数，n自减1 
			n--;
		}
		else{//如果检查没通过，不会报数，n不减少，记录一次掉过，为第(flag-1)%4个人
			person[(flag-1)%4]++;
		}
		flag++; //flag每次都加
	}
	for(int i = 0 ; i < 4; i++){
		cout<<person[i]<<endl;
	}
	return 0;
}

