#include<iostream>
#include<vector>
using namespace std;
//491.�ݹ�������:һ����Ϊû�����򣬵���set�ж�ͬ��ݹ����ظ����ֵ�����������ͬ��ݹ顣���Ǳ�������ݹ����У����������²�ݹ飻�����ж��ǰ�λ��
// ����һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�

// �����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ���������

// class Solution {
// public:
// vector<vector<int>>ret;
// vector<int>path;
// void recall(vector<int>&nums,int start)
// {
    // if(path.size()>1)
    // {
        // ret.push_back(path);
    // }
    // unordered_set<int> used;
    // for(int i=start;i<nums.size();i++)
    // {
        // if((!path.empty()&&nums[i]<path.back())||used.find(nums[i])!=used.end())
       // {
          // continue;
       // }
        // path.push_back(nums[i]);
           // used.insert(nums[i]);
           // recall(nums,i+1);
           // path.pop_back();
    // }
// }
    // vector<vector<int>> findSubsequences(vector<int>& nums) {
    // ret.clear();
    // path.clear();
    // recall(nums,0);
    // return ret;
    // }
// };

//�Ӽ���������һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�
//ͬ����used�����жϣ���ǰ����ͬԪ��ʱΪfalse��ͬ��ݹ飬ֱ��continue
// class Solution {
// public:
// vector<vector<int>> ret;
// vector<int> path;
// void recall(vector<int>&nums,int start,vector<bool>& used)
// {
    // ret.push_back(path);
    // for(int i=start;i<nums.size();i++)
    // {
        // if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false)//����ͬ����ͬ����
        // continue;
        // used[i]=true;
        // path.push_back(nums[i]);
        // recall(nums,i+1,used);
       // used[i]=false;
        // path.pop_back();
    // }
// }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
   // ret.clear();
   // path.clear();
   // vector<bool> used(nums.size(),false);
   // sort(nums.begin(),nums.end());
   // recall(nums,0,used);
   // return ret;
    // }
// };

//int main()
//{
//	vector<int> ret;
//	ret.push_back(1);
//	ret.push_back(2);
//	ret.push_back(3);
//	ret.push_back(4);
//	vector<int>::iterator it = ret.begin();
//	cout << *it << endl;
//	cout << *(it + 1) << endl;
//	return 0;
//}

//78.�Ӽ�
// class Solution {
// public:
// vector<vector<int>> ret;
// vector<int> path;
// void recall(vector<int>& nums,int start)
// {
    // ret.push_back(path);
    // for(int i=start;i<nums.size();i++)
    // {
        // path.push_back(nums[i]);
        // recall(nums,i+1);
        // path.pop_back();
    // }
// }
    // vector<vector<int>> subsets(vector<int>& nums) {
  // ret.clear();
  // path.clear();
  // recall(nums,0);
  // return ret;
    // }
// };

//void findmin(vector<int> left, vector<int> right, vector<int>::iterator i, vector<int>::iterator j,int lnum,int rnum)
//{
//
//}
//93.��ԭip��ַ---ֱ�����ַ���s�������жϻ�����㣬���򻮷��յ㣬����Ҫ����ַ������ں����'.',������ֱ���˳��ݹ顣������ĵ���Ϊ3ʱ���ж��Ƿ���ȷ����ȷ�ͽ���ret
//�жϻ��ֵ��ַ����Ƿ���ȷ��һ�����ҪС���յ㣻���ǲ����ǷǷ����ֲ��Ҳ���0xxx��ʽ������sum��0-255֮��
//class Solution {
// public:
// vector<string> ret;
// void recall(string&s,int point,int start)
// { if(point==3)
  // {   if(istrue(s,start,s.size()-1))
    // {
        // ret.push_back(s);
    // }
    // return;
   // }
   // for(int i=start;i<s.size();i++)
   // {
       // if(istrue(s,start,i))
       // {
           // s.insert(s.begin()+i+1,'.');//�ڸ���λ�ò���
           // point++;
           // recall(s,point,i+2);
            // s.erase(s.begin()+i+1);//�ӵ�һ����������λ��������ɾ�������ַ�
            // point--;
       // }else
       // {
           // break;//���������Ҫ�����˳����εݹ�
       // }

   // } 
 // }

 // bool istrue(string&s,int begin,int end)
 // {
    // if(begin>end)
    // {
        // return false;
    // }
  // if(s[begin]=='0'&&begin!=end)
  // {
      // return false;//0xxx->false
  // }
// int sum=0;
  // for(int i=begin;i<=end;i++)
  // {
      // if(s[i]<'0'||s[i]>'9')//�Ƿ��ַ�
      // {
          // return false;
      // }
      // sum=sum*10+(s[i]-'0');
      // if(sum>255)
      // {
          // return false;
      // }
  // }
  // return true;
 // }
    // vector<string> restoreIpAddresses(string s) {
// ret.clear();
// if(s.size()<4||s.size()>12){return ret;}
// recall(s,0,0);
// return ret;
    // }
// };
//������ɵ�Ʊ�����---��ʱ��---ֱ�Ӽ�����������
void Gloves(int n, vector<int> left, vector<int>right,int &lnum,int&rnum)
{
	 vector<int>:: iterator i = left.begin();
	 vector<int>::iterator lcur = left.begin();
	 vector<int>::iterator lprev = left.begin();
	 vector<int>::iterator lmin = left.begin();
	 vector<int>::iterator j = right.begin();
	 vector<int>::iterator rcur = right.begin();
	 vector<int>::iterator rprev = right.begin();
	 vector<int>::iterator rmin = right.begin();
	 
	while(i!=left.end()&&j!=right.end())
	{
		if (*i == 0 && *j == 0)//����������ɫ��Ϊ0������
		{
			i++;
			j++;
		}
		else if (*i == 0)//���������Ϊ0���ұ���ѡ��С��
		{
			rcur = j;
			rmin = rcur;
			rprev = rcur + 1;
			while (rprev != right.end())//����С
			{
				if (*rprev <= *rcur)
				{
					
					rmin = rprev;
					break;//�ҵ��ȵ�ǰλ�ø��ٵ�������
				}
				rprev++;
			}
			if (rmin != rcur)//�ں����ҵ��˱ȵ�ǰλ�û��ٵ�����--��λ�õ�������������--ȡһ��
			{
				rnum += 1;//�����ӵȵ�ǰ����λ��1
			}
			else//��λ�õ�����������С��--ȡȫ��
			{
				rnum += *rcur;
			}

		}
		else if(*j==0)//�ұ�����λΪ0
		{
			lcur = i;
			lmin = lcur;
			lprev = lcur + 1;
			while (lprev != left.end())//�������С
			{
				if (*lprev <= *lcur)
				{

					lmin = lprev;
					break;//�ҵ��ȵ�ǰλ�ø��ٵ�������
				}
				lprev++;
			}
			if (lmin != lcur)//�ҵ���--��λ�õ�������������--ȡһ��
			{
				lnum += 1;//�����ӵȵ�ǰ����λ��1
			}
			else//��λ�õ�����������С��--ȡȫ��
			{
				lnum += *lcur;
			}
		}
		else//���Ҷ���Ϊ0
		{
			lcur = i;
			rcur = j;
			//�Ա���������С
			if (lcur!=left.end() &&rcur!=right.end() &&*lcur < *rcur)//���С-�������С���ҵ��˵�ǰλ�þ�ȡ1��û�ҵ���ǰλ��ȡȫ�����ұ�ȡ1
			{
				lmin = lcur;
				lprev = lcur+1;
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				while (lprev != left.end())
				{
					if (*lprev <= *lcur)//�ڴ�λ�������ҵ��˻�С�ģ���λ��Ϊ���--ȡ1
					{
						lmin = lprev;
						break;
					}
				}
				if (lmin != lcur)//��λ��Ϊ���--ȡ1
				{
					lnum += 1;
				}
				else//��λ��Ϊ��С
				{
					lnum += *lmin;
				}
				rnum++;
			}
			else//�ұ�С-�ұ�����С���ҵ��˵�ǰλ�þ�ȡ1��û�ҵ���ǰλ��ȡȫ�������ȡ1
			{
				rmin = rcur;
				rprev = rcur + 1;
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				while (rprev != right.end())
				{
					if (*rprev <= *rcur)//�ڴ�λ�������ҵ��˻�С�ģ���λ��Ϊ���--ȡ1
					{
						rmin = rprev;
						break;
					}
				}
				if (rmin != rcur)//��λ��Ϊ���--ȡ1
				{
					rnum += 1;
				}
				else//��λ��Ϊ��С
				{
					rnum += *rmin;
				}
				lnum++;
			}
			
		}
		i++;
		j++;
	}
}
int main()
{
	int n = 0;
	vector<int> left_hand;
	vector<int>right_hand;
	left_hand.push_back(0);
	left_hand.push_back(7);
	left_hand.push_back(1);
	left_hand.push_back(6);
	right_hand.push_back(1);
	right_hand.push_back(5);
	right_hand.push_back(0);
	right_hand.push_back(6);
	int lnum = 0;
	int rnum = 0;
	Gloves(n, left_hand, right_hand,lnum,rnum);
	cout << lnum << " " << rnum << " " << lnum + rnum << endl;
	return 0;
	
}


//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        int k = 1;
//        int num = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            if (n & 1 == 1)
//            {
//                num++;
//            }
//            n=(n>>1);
//        }
//        cout << num << endl;
//    }
//
//    return 0;
//}
//
//class A {
//
//public:
//	void foo()
//	{
//		printf("A_foo");
//	}
//};
//
//class B :public A
//{
//public:
//	void foo()
//	{
//		printf("B_foo");
//	}
//};
//
//int main()
//{
//	A* ptr = new B;
//	ptr->foo();
//	B*ptr1=new B;
//	ptr1->foo();
//
//
//	return 0;
//}