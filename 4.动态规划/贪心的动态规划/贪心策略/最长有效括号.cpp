最长有效括号
/*
动态规划：
dp[i]为以s[i]结尾的最长长度 
s[i]=='('长度为0 
s[i]==')'{
	s[i-1]=='('	dp[i]=dp[i-2]+2;
	s[i-1]==')'且s[i-dp[i-1]-1]=='(' dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
										//里面的+s[i]与其对应的+左边的 
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
栈：
把下标存入栈，最后一个没有被匹配的右括号的下标一直作为栈底
遇见(存入，遇见)消去(，判断是否为空，为空的时候更换栈底，不为空的话计算当前答案
用栈把合理的括号都消去了，计算当前遍历的i与栈顶的差值便是当期答案 
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
			else ans=max(ans,i-sta.top());//更新答案 
		}
		return ans;
	}
}
/*
最普通最快方法： 
从左到右遍历，(l+1,   )r+1,两者相等时记录答案，r>l时重新记录，但是有(()这种情况不会记录
故再从右到左遍历一遍
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
