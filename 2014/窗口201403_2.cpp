/*

试题编号：	201403-2
试题名称：	窗口
时间限制：	1.0s
内存限制：	256.0MB
问题描述：	
问题描述
　　在某图形操作系统中,有 N 个窗口,每个窗口都是一个两边与坐标轴分别平行的矩形区域。窗口的边界上的点也属于该窗口。窗口之间有层次的区别,在多于一个窗口重叠的区域里,只会显示位于顶层的窗口里的内容。
　　当你点击屏幕上一个点的时候,你就选择了处于被点击位置的最顶层窗口,并且这个窗口就会被移到所有窗口的最顶层,而剩余的窗口的层次顺序不变。如果你点击的位置不属于任何窗口,则系统会忽略你这次点击。
　　现在我们希望你写一个程序模拟点击窗口的过程。
输入格式
　　输入的第一行有两个正整数,即 N 和 M。(1 ≤ N ≤ 10,1 ≤ M ≤ 10)
　　接下来 N 行按照从最下层到最顶层的顺序给出 N 个窗口的位置。 每行包含四个非负整数 x1, y1, x2, y2,表示该窗口的一对顶点坐标分别为 (x1, y1) 和 (x2, y2)。保证 x1 < x2,y1 2。
　　接下来 M 行每行包含两个非负整数 x, y,表示一次鼠标点击的坐标。
　　题目中涉及到的所有点和矩形的顶点的 x, y 坐标分别不超过 2559 和　　1439。
输出格式
　　输出包括 M 行,每一行表示一次鼠标点击的结果。如果该次鼠标点击选择了一个窗口,则输出这个窗口的编号(窗口按照输入中的顺序从 1 编号到 N);如果没有,则输出"IGNORED"(不含双引号)。
样例输入
3 4
0 0 4 4
1 1 5 5
2 2 6 6
1 1
0 0
4 4
0 5
样例输出
2
1
1
IGNORED
样例说明
　　第一次点击的位置同时属于第 1 和第 2 个窗口,但是由于第 2 个窗口在上面,它被选择并且被置于顶层。
　　第二次点击的位置只属于第 1 个窗口,因此该次点击选择了此窗口并将其置于顶层。现在的三个窗口的层次关系与初始状态恰好相反了。
　　第三次点击的位置同时属于三个窗口的范围,但是由于现在第 1 个窗口处于顶层,它被选择。
　　最后点击的 (0, 5) 不属于任何窗口。


*/


#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
struct Node
{
	int number;  //窗口编号
	pii bl ; //左下角的坐标
	pii ur ; //右上角的坐标
};

typedef struct Node window ;

stack<window>  s1 , s2 ; //存放窗口顺序


int getAnswer(int x , int y){
	int nm  = 0;
	while(!s1.empty()){
	window wi = s1.top();
	if(x >= wi.bl.first && y >= wi.bl.second && 
	   x <= wi.ur.first && y <= wi.ur.second)
	{
		s1.pop();
		nm  = wi.number;
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(wi);
		return nm;
	}
	else
		{
			s2.push(wi);
			s1.pop();
		}
}

	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
  	return 0;
}



int main(int argc, char const *argv[])
{
	int N, M; //(1 ≤ N ≤ 10,1 ≤ M ≤ 10)
	// N 个窗口 ， M 次点击
	cin>>N>>M;
	window temp; 
	for(int i = 1 ; i <= N ;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		temp.number = i; //编号
		temp.bl = make_pair(x1,y1);
		temp.ur = make_pair(x2,y2);
		s1.push(temp);
	}

	// while(!s1.empty()){
	// 	window ss = s1.top();
	// 	cout<<"num:"<<ss.number<<endl;
	// 	cout<<"x1,y1:"<<ss.bl.first<<" "<<ss.bl.second<<endl;
	// 	cout<<"x2,y2:"<<ss.ur.first<<" "<<ss.ur.second<<endl;
	// 	s1.pop();
	// }

	for(int i = 1 ; i <= M ;i++){
		int x , y ;
		cin>>x>>y;
		if(getAnswer(x,y)){
			cout<<getAnswer(x,y)<<endl;
		}
		else
			cout<<"IGNORED"<<endl;

	}

	return 0;
}