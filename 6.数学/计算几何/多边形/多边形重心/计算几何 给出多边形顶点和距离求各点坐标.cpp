/*
题意：给出圆心坐标(x,y),半径r，求以圆心为重心的n多边形的各个顶点坐标，要求以顺时针输出，且从最左边
	的点开始 
	运用参数方程，构造一个特定w的正弦、余弦函数 
	x:r*cos(2.0*pi-2.0*pi/n*i)+x+0.00000001
	r:边长、-2.0*pi/n*i是把2*pi分成n份，每次占i份，负号要求顺时针转动 
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
