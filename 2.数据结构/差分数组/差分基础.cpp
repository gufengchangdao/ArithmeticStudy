#include<bits/stdc++.h>
#define ll long long
#define m=1e5*10
#define mem(a,b) memset(a,b,sizeof(a))	//����memset����д 
using namespace std;
const int inf=0x3f3f3f3f;	//const�Ƕ������˼ ,���ﶨ�弫���� 
const int mm=1e5+10;

int a[mm],b[mm];//a[mm]��¼�ı�ֵ 
int x,y;
int main()
{
    int n;
    while(scanf("%d",&n)&&n){ //����n��n��Ϊ0��ִ�� 
        mem(a,0);	//mem��memset����д 
        mem(b,0);
        
        for(int i=1;i<=n;i++){	 //���޸�ֵ�������� 
            scanf("%d%d",&x,&y);
            b[x]++;		//b+=change 
            b[y+1]--;	// b-=change 
        }
        
        for(int i=1;i<=n;i++)	 //�޸�x��y���� 
            a[i]=a[i-1]+b[i];	//b[i]==b[x]ʱ��ÿһ������b[x]���ϵ��� 
       
        for(int i=1;i<n;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
