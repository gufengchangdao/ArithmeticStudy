#include<bits/stdc++.h>
#define swap(a,b){int temp=a;a=b;b=temp;}
using namespace std;
int n,a[100];

void quilksort(int left,int right)
{
	if(left>=right) return;
	int temp=a[left]; //基准数选取左边的数，这里选的不太好
	int i=left,j=right;
	while(i!=j){
		while(a[j]>=temp&&i<j) j--;
		while(a[i]<=temp&&i<j) i++;
		if(i<j) swap(a[i],a[j]);//交换第一个和第(i+1)个 
	}
	a[left]=a[i];
	a[i]=temp;
	quilksort(left,i-1);
	quilksort(i+1,right);
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	quilksort(1,n);
	for(i=1;i<=n;i++) printf("%d ",a[i]);
}
