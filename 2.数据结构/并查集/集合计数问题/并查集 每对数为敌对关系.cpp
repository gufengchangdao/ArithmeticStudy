#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 130000
using namespace std;
int per[maxn], num[maxn],height[maxn],n, m;

int find(int x)
{
	int r=x;
	while(r!=per[r]) r=per[r];
	int temp,i=x;
	while(i!=r){
		temp=per[i];
		per[i]=r;
		i=temp;
	}
	return r; 
}

void join(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        if(height[fx]==height[fy]){
        	per[fx]=fy;
        	height[fy]+=1;
		}
		else if(height[fx]>height[fy])
			per[fy]=fx;
		else per[fx]=fy;
    }
    return;
}
int a,b,ch,count2=0,enemy[100100]; 
int main (){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(enemy,0,sizeof(enemy));
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;++j) per[j]=j;
        for(int i=0;i<m;++i){
            scanf(" %c%d%d",&ch,&a,&b);
            if(ch=='D'){
              if (enemy[a]) join(enemy[a],b); 
              if (enemy[b]) join(enemy[b],a);
              enemy[a] = b; 
              enemy[b] = a;
              }
            else {
              if (find(a)==find(enemy[b])) printf("In different gangs.\n");
              else if (find(a) == find(b)) printf("In the same gang.\n"); 
              else printf("Not sure yet.\n");
              }
        }
    }
}
