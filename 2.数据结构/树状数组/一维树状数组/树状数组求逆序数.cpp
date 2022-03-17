#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int c[N]; 
int n;

int lowbit(int i)
{
    return i&(-i);
}

int insert(int i,int x)
{
    while(i<=n){
        c[i]+=x;
        i+=lowbit(i);
    }
    return 0;
}

int getsum(int i)
{
    int sum=0;
    while(i>0){
        sum+=c[i];
        i-=lowbit(i);
    } 
    return sum;
}

void output()
{
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<endl;
}

int main()
{
    while(~scanf("%d",&n)){
        int ans=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            insert(a,1);
            ans+=i-getsum(a);//ͳ�Ƶ�ǰ�����д���a��Ԫ�صĸ���
        }
        cout<<ans<<endl;
    }
    return 0;
}
