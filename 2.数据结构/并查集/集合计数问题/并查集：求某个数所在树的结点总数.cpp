#include<stdio.h>
using namespace std;
int n;
int main()
{
	while(~scanf("%d",&n)){
		bool isfirst=true;
		int qian,bai;
		qian=n/99-1;
		for(int i=qian;i*99<=n;i++){
			bai=n-99*i;
			if(bai<100&&bai>=0&&i>0){
				if(isfirst){
					printf("%d",bai+i*100);
					isfirst=false;
				}
				else printf(" %d",bai+i*100);
			}
		}
	printf("\n");
	}
 } 
