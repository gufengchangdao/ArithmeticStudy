//计算几何 
/*
	给定区间[l,r]，求出该区间内的数中二进制形式中1为奇数的数的个数
	找规律 ，规律放下面 
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
/*规律，第一位不断在0和1之间改变，1的时候奇偶性改变不知道，但是0变1奇偶性一定变化 
1	1    	是 

2	10		是 
3	11

4	100		是
5	101

6	110
7	111		是

8	1000	是
9	1001

10	1010
11	1011	是
	奇数直接算，偶数要判断该数本身是不是奇数个 
*/
