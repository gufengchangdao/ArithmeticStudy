#include<bits/stdc++.h>
#include<string>
char str[1205];
using namespace std;
int main()
{
	int i,length;
	char str0[4]={'H','U','B','A'};
	while(cin>>str){
		int sum=0,k=0;
		length=strlen(str);
		for(i=0;i<length;i++){
			if(strncmp(str0,str+i,4)==0) i+=3;//从str[i]开始比较4位 
			else{
					printf("%c",str[i]);
					k=1;
					if(strncmp(str0,str+i+1,4)==0&&i<length-5) printf(" "); 
				}
		}
		if(!k) printf("OMG");
		printf("\n");
	}
}
