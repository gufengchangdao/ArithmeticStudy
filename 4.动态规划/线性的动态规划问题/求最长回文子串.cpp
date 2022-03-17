//最长子回文串： 
/*
动态规划：
pri[i][j]表示[i,j]的字符串是否为回文串，从长度1不断遍历
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
			if(pri[i][j]&&l+1>ans.size()) ans=s.substr(i,l+1);//如果pri[i][j]为回文串且长度大于最大值，更新答案 
		}								//s.substr(起始,末尾+1) 
	return ans;
}
/*
中心扩展算法
将s进行遍历，因为字符串的奇偶性，故中心一定是一个或两个字符 
对每个中心字符进行check，找到以该中心字符为中心的回文串的最大长度 
*/
pair<int,int>check(const string &s,int l,int r)//pair可以返回两个值 
{
	while(l>=0&&r<s.size()&&s[l]==s[r]){//向外扩展 
		l--;r++;
	}
	return {l+1,r-1};//返回最长回文串的两个下标 
}
string getlong(string s)
{
	int start=0,end=0;
	for(int i=0;i<s.size();i++){
		auto[l1,r1]=check(s,i,i);//定义两个变量l1、r1接收返回的两个下标 
		auto[l2,r2]=check(s,i,i+1);//这里不用担心i+1大于字符串长度,因为函数中会直接退出 
		if(r1-l1>end-start){//更新答案 
			start=l1;end=r1;
		}
		if(r2-l2>end-start){
			start=l2;end=r2;
		}
	}
	return s.substr(start,end-start+1); 
} 

/*
Manacher 算法
太难了，还不会 
*/
