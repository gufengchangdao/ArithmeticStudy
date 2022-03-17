#include<bits/stdc++.h>
#define Maxn 10
using namespace std;
int pos[Maxn];//pos[i]  第i个序列正在使用第几个位置
int T,n;
int deep;//DNA序列最小长度
char c[10] = "ACGT";//模板，类似坐标移动的上下左右 
struct node
{
    char list[Maxn];     //DNA的组成
    int len;     //DNA长度
}dna[Maxn];//a[i]  第i个DNA序列

int init()//预估最少剩余长度
{
    int ans=0;
    for(int i=0;i<n;i++)//总长度-正在使用的位置=剩下还没用的位置 即最少剩余长度
        ans=max(ans,dna[i].len-pos[i]);
    return ans;
}

int dfs(int step)
{
    if(step+init()>deep)//估价函数，预计最少剩余长度+当前长度>构造DNA序列的最小长度
        return 0;
    if(init()==0)//在最小deep下达到所有的DNA序列都排好，即已完成
        return 1;
        
    int pre[Maxn];//先将pos保存起来，一会回溯要用，一定不能设为全局变量 
	for(int j=0;j<n;j++)//保存pos
        pre[j]=pos[j];
        
    for(int i=0;i<4;i++){//构造序列，该位置分别设为A、T、G、C一一尝试 
        int f=0;
        for(int j=0;j<n;j++){//i==0时，对于A，所有DNA序列验证是否当前位置为A，存在A时尝试把该位置设置为A 
            if(c[i]==dna[j].list[pos[j]]){
                f=1;
                pos[j]++;//把该位置设为A后，要考虑下一位 
            }
        }
        if(f){
            if(dfs(step+1))//有符合的，则往下搜索，该位置为A后，尝试搜索下一位 
                return 1;
            for(int j=0;j<n;j++)//回溯,没有找到，往下搜索过程中pos的值改变，回溯到原来的值 
                pos[j]=pre[j];
        }
    }
    return 0;//不能省去，没有找到，不返回值0的话就默认为找到了 
}
int main()
{
    cin>>T;
    while(T--){
        deep=0;//自己构造的DNA序列最小长度
        cin>>n;
        	for(int i=0;i<n;i++){//存值
        	    cin>>dna[i].list;//cin>>数组名  可以直接读取一行字符，不包括空格 
        	    dna[i].len=strlen(dna[i].list);
        	    deep=max(deep,dna[i].len);//deep从最长的一条开始，节省时间 
        	    pos[i]=0;//所有序列从第一个字符开始搜索 
        	}
    	for(deep;;deep++)//一定存在答案 
    	    if(dfs(0)) break;	
    	cout<<deep<<endl;
    }
    return 0;
}
