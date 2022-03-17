���Ч����
/*
��̬�滮��
dp[i]Ϊ��s[i]��β������� 
s[i]=='('����Ϊ0 
s[i]==')'{
	s[i-1]=='('	dp[i]=dp[i-2]+2;
	s[i-1]==')'��s[i-dp[i-1]-1]=='(' dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
										//�����+s[i]�����Ӧ��+��ߵ� 
}
*/ 
class Solution {
public:
    int longestValidParentheses(string s) {
		int n=s.length();
		int dp[n+5],ans=0;
		for(int i=1;i<n;i++){
			if(s[i]==')'){	
				if(s[i-1]=='(') dp[i]=(i>=2?dp[i-2]:0)+2;
				else if(i>dp[i-1]&&s[i-dp[i-1]-1]=='(')
					dp[i]=dp[i-1]+2+((i>=(dp[i-1]+2))?dp[i-dp[i-1]-2]:0);
			ans=max(ans,dp[i]);
			}	
		}
		return ans;	
    }
};
/*
ջ��
���±����ջ�����һ��û�б�ƥ��������ŵ��±�һֱ��Ϊջ��
����(���룬����)��ȥ(���ж��Ƿ�Ϊ�գ�Ϊ�յ�ʱ�����ջ�ף���Ϊ�յĻ����㵱ǰ��
��ջ�Ѻ�������Ŷ���ȥ�ˣ����㵱ǰ������i��ջ���Ĳ�ֵ���ǵ��ڴ� 
*/
int longestValidParentheses(string s) 
{
	stack<int>sta;
	sta.push(-1);
	int n=s.length(),ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(') sta.push(i);
		else{
			sta.pop();
			if(sta.empty()) sta.push(i);
			else ans=max(ans,i-sta.top());//���´� 
		}
		return ans;
	}
}
/*
����ͨ��췽���� 
�����ұ�����(l+1,   )r+1,�������ʱ��¼�𰸣�r>lʱ���¼�¼��������(()������������¼
���ٴ��ҵ������һ��
*/ 
public int longestValidParentheses(String s) {
    int l=0,r=0,Max=0,n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='(') l++;
		else if(s[i]==')') r++;
		if(l==r) Max=max(Max,2*r);
		else if(r>l){
			l=0;r=0;
		}
	}
	l=0;r=0; 
	for(int i=n-1;i>=0;i--){
		if(s[i]=='(') l++;
		else if(s[i]==')') r++;
		if(l==r) Max=max(Max,2*r);
		else if(l>r){
			l=0;r=0;
		}
	}
    return Max;
}
