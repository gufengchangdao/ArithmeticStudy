��һ�֣� 
#include<algorithm> // ͷ�ļ� 
//n ԭ�����С num ԭ�����е�Ԫ�� lsh ��ɢ�������� cnt ��ɢ����������С 
int lsh[MAXN] , cnt , num[MAXN] , n;
for(int i=1; i<=n; i++){
	scanf("%d",&num[i]);
	lsh[i] = num[i];	
}
sort(lsh+1 , lsh+n+1);
cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;//ȥ�غ��±귶ΧΪ[1,cnt]; 
for(int i=1; i<=n; i++)
	num[i]=lower_bound(lsh+1,lsh+cnt+1,num[i])-lsh;	//num[i]��СΪ1��num����ָ��lsh��Ӧ���±� 
//ע�� ȥ�غͶ��ֺ����ȥ����������unique���ص��ǲ��ظ����е����һ��Ԫ�ص���һ��Ԫ�أ�������ͬ 

�ڶ��֣� 
#include<algorithm>
struct Node {
	int data , id;
	bool operator < (const Node &a) const {
		if(data==a.data) return id<a.id;	//������Ŀ��Ҫ��id���� 
		return data < a.data;
	}
};
for(int i=1; i<=n; i++) {
	scanf("%d",&num[i].data);
	num[i].id = i;
}
sort(num+1 , num+n+1);	//������������±�i���Ƕ�ԭ��ֵ����ɢ�� 
for(int i=1; i<=n; i++)	
	rank[num[i].id] = i;


