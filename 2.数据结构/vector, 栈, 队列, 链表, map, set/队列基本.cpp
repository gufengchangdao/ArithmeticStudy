struct node
{
	int x,y;	
}; 

#include<queue>
node item={1,2};
queue<int>q;//定义，int,float,char等 
q.push(item);//把item放入
q.push((node){1,2});//效果相同，(node)可以认为是强制类型转换 
q.front();//返回队首元素,就是第一个输入的数
q.back();//返回队尾元素  
q.pop();//删除队首元素 
q.size(); 
q.empty();

priority_queue<int>q;//优先队列，操作过后将元素从大到小出队 
priority_queue<int,vector<int>,greater<int>>q;//从小到大出队 
