int a[100];
int b[100][100];
bool c[100];
//memset������ֵΪ0��-1�����ֵ0x3f 
memset(a,0,sizeof(a));//ȫ����Ϊ0
memset(a,0x3f,sizeof(a)); 
memset(b,0,sizeof(b)); 
memset(b[0],0,sizeof(b[0]));//ֻ�ѵ�1�и�ֵΪ0
memset(b,-1,sizeof(b));//ȫ����ֵΪ-1 
memset(c,false,sizeof(c));
memset(c,0,sizeof(c));
memset(c,-1,sizeof(c));//��ֵΪ-1��ʾtrue 
