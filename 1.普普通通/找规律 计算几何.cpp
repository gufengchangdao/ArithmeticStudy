//���㼸�� 
/*
	��������[l,r]������������ڵ����ж�������ʽ��1Ϊ���������ĸ���
	�ҹ��� �����ɷ����� 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll x){
    ll temp, k=x,cnt=0;
    while(k!=0){
        temp=k%2;
        k/=2;
        if(temp==1)cnt++;
    }
    if(x==0)return 0;
    if(x&1)return x/2+1;
    if((x&1)==0){
        if(cnt&1)return x/2+1;
        else return x/2;
    }
}
int main() {
    ll t,l,r,x1,x2;
    cin>>t;
    while(t--){
        cin>>l>>r;
        x1=solve(l-1);
        x2=solve(r);
        //cout<<x1<<" "<<x2<<endl;
        cout<<x2-x1<<endl;
    }
}
/*���ɣ���һλ������0��1֮��ı䣬1��ʱ����ż�Ըı䲻֪��������0��1��ż��һ���仯 
1	1    	�� 

2	10		�� 
3	11

4	100		��
5	101

6	110
7	111		��

8	1000	��
9	1001

10	1010
11	1011	��
	����ֱ���㣬ż��Ҫ�жϸ��������ǲ��������� 
*/
