/*
���⣺����Բ������(x,y),�뾶r������Բ��Ϊ���ĵ�n����εĸ����������꣬Ҫ����˳ʱ��������Ҵ������
	�ĵ㿪ʼ 
	���ò������̣�����һ���ض�w�����ҡ����Һ��� 
	x:r*cos(2.0*pi-2.0*pi/n*i)+x+0.00000001
	r:�߳���-2.0*pi/n*i�ǰ�2*pi�ֳ�n�ݣ�ÿ��ռi�ݣ�����Ҫ��˳ʱ��ת�� 
*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD=1e9+7;
int t; 
int main(){
	cin>>t ;
    while(t--){
        int x,y,r,n ;
        scanf("%d%d%d%d",&x,&y,&r,&n);
        double pi=acos(-1);
        for(int i=0;i<n; i++){
            printf ("%.2lf %.2lf\n",r*cos(-2.0*pi/n*i)+x+0.00000001,r*sin(-2.0*pi/n*i)+y+0.00000001);
        }
    }
    return 0;
}
