
    ios::sync_with_stdio(false);
    int a;
    cin>>a;
    cout<<a;
//   ��ʵĬ�ϵ�ʱ��cin��stdin���Ǳ���ͬ���ģ�Ҳ����˵�����ַ������Ի��ã������ص����ļ�ָ����ң�
//	ͬʱcout��stdoutҲһ�������߻��ò������˳����ҡ�����Ϊ��������Ե����ԣ�����cin���������
//	�������ر���ͬ�������cin��cout�ٶ�,��ʱ�Ͳ�������scanf��printf�� 

//����getchar()��scanf()����һ�� 
int read()
{
	char ch=getchar();int x=0,f=1;
	while(ch<'0' || ch>'9'){//��ch���������ַ������ȡ�������ַ�Ϊֹ�����ݱ���Ҫ�������ַ� 
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

