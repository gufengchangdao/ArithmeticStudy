//��ӻ��Ĵ��� 
/*
��̬�滮��
pri[i][j]��ʾ[i,j]���ַ����Ƿ�Ϊ���Ĵ����ӳ���1���ϱ���
l=0 pri[i][i]=1;
l=1 pri[i][i+l]=(s[i]==s[i+l]);
l>1 pri[i][j]=(pri[i+1][j-1]&&s[i]==s[j]);
*/ 
string longestPalindrome(string s){
	int len=s.size();
	int pri[len+5][len+5];
	string ans="";
	for(int l=0;l<len;l++)
		for(int i=0;i+l<len;i++){
			int j=i+l;
			if(l==0) pri[i][j]=1;
			else if(l==1) pri[i][j]=(s[i]==s[j]);
			else pri[i][j]=(pri[i+1][j-1]&&s[i]==s[j]);
			if(pri[i][j]&&l+1>ans.size()) ans=s.substr(i,l+1);//���pri[i][j]Ϊ���Ĵ��ҳ��ȴ������ֵ�����´� 
		}								//s.substr(��ʼ,ĩβ+1) 
	return ans;
}
/*
������չ�㷨
��s���б�������Ϊ�ַ�������ż�ԣ�������һ����һ���������ַ� 
��ÿ�������ַ�����check���ҵ��Ը������ַ�Ϊ���ĵĻ��Ĵ�����󳤶� 
*/
pair<int,int>check(const string &s,int l,int r)//pair���Է�������ֵ 
{
	while(l>=0&&r<s.size()&&s[l]==s[r]){//������չ 
		l--;r++;
	}
	return {l+1,r-1};//��������Ĵ��������±� 
}
string getlong(string s)
{
	int start=0,end=0;
	for(int i=0;i<s.size();i++){
		auto[l1,r1]=check(s,i,i);//������������l1��r1���շ��ص������±� 
		auto[l2,r2]=check(s,i,i+1);//���ﲻ�õ���i+1�����ַ�������,��Ϊ�����л�ֱ���˳� 
		if(r1-l1>end-start){//���´� 
			start=l1;end=r1;
		}
		if(r2-l2>end-start){
			start=l2;end=r2;
		}
	}
	return s.substr(start,end-start+1); 
} 

/*
Manacher �㷨
̫���ˣ������� 
*/
