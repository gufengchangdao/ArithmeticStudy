#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int N=1003;
inline void inn(int & x) {
   // int���
inline void lnn(ll & x) {
   // ll���
int n,m;
ll a[N],tr[N],trr[N];//aԭ����,��cΪ������� trΪ��c��״���� trrΪΪc[i]*(i-1)����״����
//��̬������״����  
inline void add(int i,ll k,ll tree[]){
	for (;i<=n;i+=((i)&-(i)))
		tree[i]+=k;
}
//��tree��[1,i]�ĺͣ���ǰ׺�� 
inline ll sum(int i,ll tree[]){
	ll res=0;
	for (;i>0;i-=((i)&-(i)))
        res+=tree[i];
	return res;
}

int main(){
	inn(n);inn(m);
	//����a[i]�ͳ�ʼ�� 
	fo(i,1,n+1){//a[i]��1��ʼ�洢 
		lnn(a[i]);
		add(i,a[i]-a[i-1],tr);//�Ƚ��������״����������i*(tree[1]*i+tree[2]*i+...+tree[i])
		add(i,(i-1)*(a[i]-a[i-1]),trr);//������tree[1]*0+tree[2]*1+...+tree[i]*(i-1) 
	}
	while(m--){
        int bo,l,r;
        inn(bo);inn(l);inn(r);
        //��[l,r]������a[i]�޸�Ϊa[i]+k
        if(bo&1){	//ֻ���޸���a[l]��a[r+l]�йص�tr��trr�Ϳ���
            ll k;lnn(k); 
            add(l,k,tr);
			add(r+1,-k,tr);
            add(l,k*(l-1),trr);//����c[i]*(i-1)�޸Ķ˵�ʱ�޸�Ϊ(c[l]+k)*(l-1)��(c[r+1]-k)*(r) 
			add(r+1,-r*k,trr);
        }
        //��a��[l,r]����ĺ� ,sum[r]-sum[l-1]
        else{
            l--;
            printf("%lld\n",r*sum(r,tr)-sum(r,trr)-l*sum(l,tr)+sum(l,trr));
        }
	}
	return 0;
}


