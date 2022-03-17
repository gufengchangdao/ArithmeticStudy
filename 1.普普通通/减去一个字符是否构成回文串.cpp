#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
//判断修改后的字符串是否为回文串 
bool IsHW(const string& str)
{
    string s=str;
    reverse(s.begin(),s.end());//翻转字符串s 
    return s==str;//判断是否相等 
}	

int main()
{ 
	int t;
	cin>>t;
    string str;
    while(t--){
    	cin>>str; 
        if(str.empty()||str.length()==1) cout<<"YES！\n";//如果是空或者只有一个字符为YES 
        else{
            bool ret=false;
            string tmp;
            int n=str.length();
            for(int i=0;i<n;i++){
                tmp=str.substr(0,i)+str.substr(i+1);//下标从0开始截取i位的字符串(即0到i-1的字符串)接上从下标i+1的位置开始的字符串 
                //即将i位置的字符去掉后重新组合的字符串 
                if(IsHW(tmp)){
                    ret=true;
                    break;
                }
            }
            if(ret)
                cout<<"YES！\n"<<endl;
            else
                cout<<"NO!\n"<<endl;
        }
    }
    return 0;
}
