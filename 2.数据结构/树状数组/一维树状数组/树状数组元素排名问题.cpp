//https://www.nitacm.com/problem_show.php?pid=602
//1~n�ļ��ϣ�q==1��ɾ��w��q==2����ѯw�������ڶ���λ��N<=100000000��1<=M<=100000
//��⣺ԭ������Ѿ�ɾ��������Ϊ1������Ϊ0��1~i�ж�����ôi֮ǰ��ɾ���˶��� 
/*
e�ṹ��洢ÿ���q��w 
b[i]�洢ÿ���w���ź���
��s[b[i]]=i,��¼w���в�ͬ������ǰ��˳�� 
a[i]��Ϊs[i]����״���� 
����ÿ�β�����
ɾ�������жϣ���Ҫɾ��������mp[w]=1��ǣ�����a[i]���ݣ�����ĸı�ֵΪ1����s[w]��0���1���ı���a[i] 
��ѯ�����жϣ�����==w-w֮ǰ��ȥ����������s[i]�ܺ� 
*/ 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int>mp,s;
//unordered_map<int,int>mp,s;//��������map������map��map����һЩ
//������map�洢����Ϊ����һЩ�����maxn,��a[maxn]=1��Ǳ�mp[maxn]=1��ռ�ڴ棬a����Ҫ���ĺܴ󣬶�
//mapֻ��Ҫ��һ����һ�� 
const int maxn=1e5+5;
int a[maxn],b[maxn],n,m;//aΪ��״���� 
struct op{
    int q,w;
}e[maxn];

int lowbit(int x){
    return x&(-x);
}

void update(int i,int k){ //�������
    while(i<=m){
        a[i]+=k;
        i+=lowbit(i);
    }
}

int getsum(int i){ //�����ѯ
    int res=0;
    while(i>0){
        res+=a[i];
        i-=lowbit(i);
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int q,w;
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d",&e[i].q,&e[i].w);
            b[i]=e[i].w;
        }
        //��ɢ������ 
        //��b����������s������wΪID��ֵΪ�����Ӧ�Ĵ��򣬴���ֵ�޹ؽ�Ҫ����Ҫ�����⼸�����ķֲ� 
        sort(b+1,b+1+m); 
        for (int i = 1; i <= m; ++i)
            s[b[i]]=i;
    //    Ҳ������m=unique(b+1,b+m+1)-b-1; ֱ�Ӷ�b����ȥ��
	//		����s[i]=lower_bound(b+1,b+m+1)-b-1�����ֲ����ҵ�ID    
        for (int i = 1; i <= m; ++i) {
            q=e[i].q;w=e[i].w;
            if(q==1){//ɾ������ 
                if(!mp[w]){
                    mp[w]=1;//���Ѿ�ɾ���ĵ��� 
                    update(s[w],1);
                }
                else{
                    printf("mdzzwinter0\n");
                }
            }
            else{//���ʲ��� 
                if(!mp[w])
                    printf("%d\n",w-getsum(s[w]));//����==w - wǰ��ɾ�����������ĺ� 
                else
                    printf("mdzzwinter1\n");
            }
        }
        mp.clear();
        s.clear();
        memset(a,0,sizeof(a));
    }
    return 0;
}
