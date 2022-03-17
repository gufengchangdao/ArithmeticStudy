/*
https://www.luogu.com.cn/problem/P4198
��������¥����ߵ���ԭ������ֱ�ߵ�б�ʵ������������
����
	����n����DFS��˳�򴢴�����DFS�����±꣬�ռ�Ϊ2*n 
	����k��������k+1���Һ�����k+�������䳤��*2
ά����Ϣ
	�����ܳ��� sum
	������˵㿪ʼ������������г��� len
	����������е����ֵ max_xl,��Сֵ min_xl
�޸�
	Ҷ�ӽڵ�len=1��max_xl,min_xl��=б��
��Ϣ�ϲ�	
	ÿ�ο����������䣬��������һ�����ϣ��ؼ�����������
1��������������������Сֵ>�������������������ֵ���������䶼���õ���
2���������������������ֵ<=�������������������ֵ����������û��
3���������������������ֵ<�������������������ֵ����>��Сֵ�����������������ж������õ���
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,cnt,x,y,f;
struct node
{
    int l,r;
    int sum,len;	//sumΪ���䳤�ȣ����������������±꣬lenΪ�������l�����Կ����ķ��� 
    double max_xl,min_xl;
}e[200001];
inline void build(int l,int r)
{
    cnt++;
    e[cnt].l=l;e[cnt].r=r;
    e[cnt].sum=r-l+1;	//sum��ʾ¥������ 
    if(l==r) return;
    int mid=l+r>>1;
    build(l,mid);build(mid+1,r);
}
inline void query(int k,double g)//������k����>g������
{
    if(e[k].max_xl<=g) return;//���Ķ����˵�С��ûϣ���� 
    if(e[k].min_xl>g) f+=e[k].len;//��С�Ķ��ȱ��˴���Ч��len������ 
    else{	//�д���С 
        double mid=e[k+1].max_xl;//k�������������������ֵ
        if(g<mid){	//����ֻҪ����g<mid�ͻ�һֱ������������ 
            query(k+1,g);
            f+=e[k].len-e[k+1].len;//�������k����������Ĺ��� 
            //����ֱ�Ӽ������������������С���Ϊ�ںϲ�ʱ�������䲻һ��ȫ�����ϲ�
            //��e[k].len<=e[k+1].len+e[k+e[k+1].sum*2] 
//g<����������ֵ����ôk����������Դ𰸶��й��ף�ȫ�����ϣ�����������������
        }
        else  query(k+e[k+1].sum*2,g);
        //query(e[k].sum&1?e[k].sum+k+1:e[k].sum+k,g);����Ҳ���� 
    }
}
inline void up(int k)//��Ϣ�ϲ��������������������ñ���� 
{
    int l=k+1,r=k+e[k+1].sum*2;
    if(e[r].min_xl>e[l].max_xl){	//��������С��б��Ҳ������������б�ʴ� 
        e[k].len=e[l].len+e[r].len;	//���ӵ�¥������ 
        if(e[k].len==1) e[k].max_xl=e[k].min_xl=e[r].max_xl;//��߿���û�з���
//���1��3�У�min_xld�ĸ���Ҫ���ж������������г����Ƿ�Ϊ1������������������Ϊ0��min_xl�������Ϊ0 
        else{
            e[k].max_xl=e[r].max_xl;//����б����ֵ 
            e[k].min_xl=e[l].min_xl;
        }
    }
    else if(e[r].max_xl<=e[l].max_xl){//����������б��Ҳ������������б��С��һ������Ҳ������ 
        e[k].len=e[k+1].len; 
        e[k].max_xl=e[k+1].max_xl;
        e[k].min_xl=e[k+1].min_xl;
    }
    else{//��������������������ͬʱ��С�ı�����С���ұ߷����б������߷��Ӹߵ��е͵� 
        f=0;//̽���ұߵ���Чlen,fΪk����������Դ��й��׵ĳ���
        query(k+e[k+1].sum*2,e[k+1].max_xl);//��k��������������>k���������������������ֵ�����г���
        if(f>0){	//�ұ߷������ܿ����ģ��н�Ÿ��� 
            e[k].len=e[k+1].len+f;//������������������������ҵ�����Ч���� 
            if(e[k].len==1) e[k].max_xl=e[k].min_xl=e[k+e[k+1].sum*2].max_xl;//��߿���û�з��� 
            else{	//������ֵ,���f<0�������б�ʺ���Сб�ʲ��� 
                e[k].max_xl=e[k+e[k+1].sum*2].max_xl;
                e[k].min_xl=e[k+1].min_xl;
            }                
        }
    }	 
}
//ά�� 
inline void change(int k)
{
    if(e[k].l==e[k].r)	//������Ҷ�ӽ�� 
    {
        e[k].len=1;//Ҷ�ӽ�㣬����ÿһ��Ҷ�ӽڵ㣬���������ͷ���Կ�����¥������һ��Ϊ1 
        e[k].max_xl=e[k].min_xl= double (y) / x;//�����Сб����ȻҲ��ͬ 
        return;    
    }
    int mid=e[k].l+e[k].r>>1;
    if(x<=mid) change(k+1);
    else change(k+e[k+1].sum*2);
    up(k);    //ÿ��������һ����ʱ��k���ӽڵ��Ѿ�ά����ֵ�ˣ���ʱ����б����ֵ��len 
}
int main()
{
    scanf("%d%d",&n,&m);
    build(1,n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        change(1);
        printf("%d\n",e[1].len);
    }
}

