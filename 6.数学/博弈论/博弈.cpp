//	��ʲ���ģ�Bash Game��
//  ֻ��һ��n����Ʒ�������˴�������ȡ����1~m���������ȡ����ʤ��
int Bash_Game(int n,int m)//�Ƿ������б�Ӯ����
{
	if(m==1){
		if(m%2==0) return 0;
		else return 1;
	} 
	if(m>=n) return 1;//����һ��ȡ�� 
    if (n%(m+1)!=0) return 1;//���n����m+1�ı�������ô��һ���˱�Ӯ 
    return 0;//�����һ���˱��� 
}

