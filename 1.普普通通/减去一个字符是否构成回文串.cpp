#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
//�ж��޸ĺ���ַ����Ƿ�Ϊ���Ĵ� 
bool IsHW(const string& str)
{
    string s=str;
    reverse(s.begin(),s.end());//��ת�ַ���s 
    return s==str;//�ж��Ƿ���� 
}	

int main()
{ 
	int t;
	cin>>t;
    string str;
    while(t--){
    	cin>>str; 
        if(str.empty()||str.length()==1) cout<<"YES��\n";//����ǿջ���ֻ��һ���ַ�ΪYES 
        else{
            bool ret=false;
            string tmp;
            int n=str.length();
            for(int i=0;i<n;i++){
                tmp=str.substr(0,i)+str.substr(i+1);//�±��0��ʼ��ȡiλ���ַ���(��0��i-1���ַ���)���ϴ��±�i+1��λ�ÿ�ʼ���ַ��� 
                //����iλ�õ��ַ�ȥ����������ϵ��ַ��� 
                if(IsHW(tmp)){
                    ret=true;
                    break;
                }
            }
            if(ret)
                cout<<"YES��\n"<<endl;
            else
                cout<<"NO!\n"<<endl;
        }
    }
    return 0;
}
