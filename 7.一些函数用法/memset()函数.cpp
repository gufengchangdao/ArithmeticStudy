int a[100];
int b[100][100];
bool c[100];
//memset用来赋值为0、-1、最大值0x3f 
memset(a,0,sizeof(a));//全部赋为0
memset(a,0x3f,sizeof(a)); 
memset(b,0,sizeof(b)); 
memset(b[0],0,sizeof(b[0]));//只把第1行赋值为0
memset(b,-1,sizeof(b));//全部赋值为-1 
memset(c,false,sizeof(c));
memset(c,0,sizeof(c));
memset(c,-1,sizeof(c));//赋值为-1表示true 
