//���⣺�����������飬�����ٶ��ٴβ���������ǰһ�������Ϊ��һ������
//����������1��ɾ����һ���������������κ�һ������2���ı���������һ��λ�õ����� 
/*
��⣺
	��ȡ���ݺ����������������¼��λ�Σ�����ÿ�������Ⱥ����֮���õ���ǰ��λ�εı仯��
	ȡ�仯�����ִ�������һ������Ϊ���壬�������������������ı��γ�Ŀ�����飬��n-�����(����) 
*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int a[maxn], b[maxn], pa[maxn], pb[maxn];//pa��pb�洢���������λ�� 
int main(){
    ios::sync_with_stdio(false);//�ر���ͬ�� 
    cin.tie(nullptr);//cin��cout��Ĭ�ϰ󶨵�,����������IO�ĸ�����ͨ��tie(nullptr)����� 
	//cin��std :: cout֮��İ󶨣���һ���ӿ�ִ��Ч��, tie�ǽ�����stream�󶨵ĺ���
	//��c++�У�nullptr�ǿ�ָ�룬NULL������0 
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], pa[a[i]] = i;
    for(int i = 1; i <= n; ++i) cin >> b[i], pb[b[i]] = i;
    map<int, int>mp;//������map�洢���Ա������õĿռ��˷Ѻͱ���ʱ����Ҫ���ݵĸ��ţ����Ҽ�����Ϊ���� 
    for(int i = 1; i <= n; ++i){
        mp[pa[i] - pb[i]]++;//ͬһ�����Ⱥ����Ĳ��ʾ���λ�� 
    }
    int ans = 0;
    for(auto i : mp){//��Χfor���������cin.tie(nullptr)ʹ��,mp��һ���ɱ�������������������vector
	//��map���ͣ�i�������ڱ��������л���������ÿһ��Ԫ�� 
        if(i.first >= 0)//�ų�λ�ν��͵ģ���Ϊ��Բ����һ����λ��ֻ����ǰ������� 
            ans = max(ans, i.second);
    }
    cout << n - ans << '\n';//����-����� 
    return 0;
}
