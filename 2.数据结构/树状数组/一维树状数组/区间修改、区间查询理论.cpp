����delta���� delta[i]��ʾ���� [i, n] �Ĺ�ͬ������
�����޸����� [l, r] ʱ�޸� delta[l] �� delta[r + 1] ����
��ѯ���� [l, r] �ĺ� ��sum[r] - sum[l - 1]
��sum[i]��
  
tree[i]=a[i]-a[i-1];
a[i]=tree[1]+tree[2]+tree[3]+...+tree[i];
sum[i]=tree[1]*i+tree[2]*(i-1)+...+tree[i]*1
	  =tree[1]*i+tree[2]*i+...+tree[i]*i-(tree[1]*0+tree[2]*1+...+tree[i]*(i-1))
	  =i*sum(1,i,tree)-sum(1,i,treei);	//treei[i]Ϊtree[i]*(i-1) 

a[i]//ԭ���� 
tr[i]//Ϊtree[i]����״����
trr[i]//Ϊtree[i]*(i-1)����״���飬 
//��̬������״���� 
inline void add(int i,ll k,ll tree[])//
{
	
}
//��tree��[1,i]�ĺͣ���ǰ׺�� 
inline ll sum(int i,ll tree[])
{
	
}
//����a[i]�ͳ�ʼ�� 
	scanf("%d",&a[i]); 
	add(i,a[i]-a[i-1],tr);//�Ƚ��������״����������i*(tree[1]*i+tree[2]*i+...+tree[i]) 
	add(i,(i-1)*(a[i]-a[i-1]),trr);//������tree[1]*0+tree[2]*1+...+tree[i]*(i-1) 
//��[l,r]������a[i]�޸�Ϊa[i]+k 
	add(l,k,tr);//ֻ���޸���a[l]��a[r+l]�йص�tr��trr�Ϳ��� 
	add(r+1,-k,tr);
	add(l,k*(l-1),trr);//������� 
	add(r+1,-k*r,trr);
//��a��[l,r]����ĺ� ,sum[r]-sum[l-1]
	r*sum(r,tr)-sum(r,trr) - (l*sum(l,tr)-sum(l,trr));
	
