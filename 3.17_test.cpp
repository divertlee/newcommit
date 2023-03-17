#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n = 3;
	vector<string> chessboard(n, string(n, '.'));

	return 0;

}

//51.N�ʺ�
//class Solution {
//public:
//    vector<vector<string>>ret;
//    void recall(vector<string>& chessboard, int n, int row)
//    {
//        if (row == n)
//        {
//            ret.push_back(chessboard);
//            return;
//        }
//        for (int col = 0; col < n; col++)//������---������������
//        {
//            if (istrue(chessboard, row, col, n))
//            {
//                chessboard[row][col] = 'Q';
//                recall(chessboard, n, row + 1);
//                chessboard[row][col] = '.';
//            }
//            else
//                continue;
//        }
//    }
//    bool istrue(vector<string>& chessboard, int row, int col, int n)
//    {
//        //�ж���
//        for (int i = 0; i < row; i++)
//        {
//            if (chessboard[i][col] == 'Q')
//            {
//                return false;
//            }
//        }
//        //�ж�45��
//        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
//        {
//            if (chessboard[i][j] == 'Q')
//            {
//                return false;
//            }
//        }
//        //�ж�135��
//        for (int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++)
//        {
//            if (chessboard[i][j] == 'Q')
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    vector<vector<string>> solveNQueens(int n) {
//        vector<string> chessboard(n, string(n, '.'));
//        recall(chessboard, n, 0);
//        return ret;
//    }
//};

//47. ȫ���� II
// ����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�
// ��used������ͬ��ǰ����ͬԪ��Ҫ����
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(vector<int>& nums, vector<bool>& used)
//    {
//        if (path.size() == nums.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if ((i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) || used[i] == true)
//                continue;
//            path.push_back(nums[i]);
//            used[i] = true;
//            recall(nums, used);
//            path.pop_back();
//            used[i] = false;
//        }
//    }
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        ret.clear();
//        path.clear();
//        vector<bool>used(nums.size(), false);
//        sort(nums.begin(), nums.end());
//        recall(nums, used);
//        return ret;
//    }
//};

//46.ȫ���У���������㣬��used������ʹ�ù����ϲ�Ԫ��
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int>path;
//    void recall(vector<int>& nums, vector<bool>& used)
//    {
//        if (path.size() == nums.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (used[i] == true)
//                continue;
//            used[i] = true;
//            path.push_back(nums[i]);
//            recall(nums, used);
//            path.pop_back();
//            used[i] = false;
//        }
//    }
//    vector<vector<int>> permute(vector<int>& nums) {
//        ret.clear();
//        path.clear();
//        vector<bool> used(nums.size(), false);
//        recall(nums, used);
//        return ret;
//    }
//};

//string recall(const string& s)
//{
//	string tmp = "";
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ')
//		{
//			continue;
//		}
//		tmp += s[i];
//	}
//	return tmp;
//}
//
//string cmp(const string& s1, const string& s2)
//{  //��һ��if�Աȵ��ǵ��������Ӻ�����
//	if ((s1.size() == s2.size() && s1.size() <= 3)//һ�ǳ���10��������ֺ�jqk��Աȵ��������Ӻ�����
//		||((s1.size()==4&&s1[0]!=s1[1])|| (s2.size() == 4 && s2[0] != s2[1]))//������10�Ķ���
//		|| ((s1.size() == 6 && s1[0] != s1[1]) || (s2.size() == 6 && s2[0] != s2[1]))////������10������
//		)
//	{
//		if (s1[0]=='2')
//		{
//			return s1;
//		}
//		else if(s2[0]=='2')
//		{
//			return s2;
//		}
//		else//û��2�������ǣ�10��jqk�Ƚ�
//		{
//	 if (s1[0] == 'K') 	{
//		return s1;
//	}
//	else if (s2[0] == 'K')
//	{
//		return s2;
//	}else if (s1[0] == 'Q') {
//		return s1;
//	}
//	else if (s2[0] == 'Q')
//	{
//		return s2;
//	}else if (s1[0] == 'J') {
//		return s1;
//	}
//	else if (s2[0] == 'J')
//	{
//		return s2;
//	}
//	else if(s1.size()==4||s1.size()==6)//s1�Ƕ���10������������10
//	 {
//		 return s1;
//	 }
//	else if (s2.size() == 4 || s2.size() == 6)//s1�Ƕ���10������������10
//	 {
//		 return s1;
//	 }
//	else//3-9�ĵ��������ӣ������Ƚ�
//	 {
//		 if (s1[0] > s2[0])
//		 {
//			 return s1;
//		 }
//		 else
//		 {
//			 return s2;
//		 }
//	 }
//		}
//		
//	}
//}

//string cmp(const string& s1, const string& s2)
//{  //��һ��if����ը
//	if (s1.size() == 11 && (s1[0] == 'j' || s1[0] == 'J'))//s1����ը-����s1
//	{
//		return s1;
//	}
//	else if (s2.size() == 11 && (s2[0] == 'j' || s2[0] == 'J'))//s2����զ-����s2
//	{
//		return s2;
//	}
//	//��ը����
//	else if ((s1.size()==7&&s2.size()==7)//����10֮�����ը
//		|| ((s1.size()==11&&s1[0]=='1')
//			||(s2.size() == 11 && s2[0] == '1'))//10ը
//		)
//	{
//		if (s1.size() == 7 && s1[0] == '2')//s1��ը
//		{
//			return s1;
//		}
//		else if (s2.size() == 7 && s2[0] == '2')//s2��ը
//		{
//			return s2;
//		}
//		else//û��2���ǣ�10��jqk�Ƚ�
//		{
//			if (s1.size() == 7 && s1[0] == 'K') {
//				return s1;
//			}
//			else if (s2.size() == 7 && s2[0] == 'K')
//			{
//				return s2;
//			}
//			else if (s1.size() == 7 && s1[0] == 'Q') {
//				return s1;
//			}
//			else if (s2.size() == 7 && s2[0] == 'Q')
//			{
//				return s2;
//			}
//			else if (s1.size() == 7 && s1[0] == 'J') {
//				return s1;
//			}
//			else if (s2.size() == 7 && s2[0] == 'J')
//			{
//				return s2;
//			}
//			else if ( s1.size() == 11 )//s1��10ը
//			{
//				return s1;
//			}
//			else if ( s2.size() == 11)//s2��10ը
//			{
//				return s2;
//			}
//			else//3-9�ĵ��������ӣ�
//			{
//				if (s1.size() == 7 && s2.size() == 7 && s1[0] > s2[0])
//				{
//					return s1;
//				}
//				else 
//				{
//					return s2;
//				}
//			}
//		}
//	}
//	else if (s1.size() == 9 && s2.size() == 9)//˳��
//	{
//		if (s1[0] == 'J')//J��ͷ��˳�����
//		{
//			return s1;
//		}
//		else if (s2[0] == 'J')//s2��ը
//		{
//			return s2;
//		}
//		else if (s1[0] == '1'&&s1[1]!=' ') //10��ͷ��˳��
//		{
//				return s1;
//			}
//		else if (s2[0] == '1' && s2[1] != ' ') //10��ͷ��˳��
//		{
//			return s2;
//		}
//			else//3-9��ͷ��˳��
//			{
//				if (s1[0] > s2[0])
//				{
//					return s1;
//				}
//				else
//				{
//					return s2;
//				}
//			}
//		}
//	
//	//��һ��if�Աȵ��ǵ��������Ӻ�����
//	else if (s1.size()<=8 && s2.size() <= 8)//һ�ǵ��������ӣ��������ܽ�ѭ��
//	{
//		if (s1.size() <=2 && s2.size() == 5&&((s2[0]=='j'&&s2[1]!=' ') || (s2[0] == 'J' && s2[1] != ' ')))//s1��������s2����
//		{
//			return s2;
//		}
//		else if (s2.size() <=2 && s1.size() == 5 && ((s1[0] == 'j' && s1[1] != ' ') || (s1[0] == 'J' && s1[1] != ' ')))//s2��������s1����
//		{
//			return s1;
//		}
//		else if ((s1.size() == 5 && (s1[0] == 'j' && s1[1] != ' ')) && (s2.size() == 5 && (s2[0] == 'J' && s2[1] != ' ')))//s1��С��s2������
//		{
//			return s2;
//		}
//		else if ((s1.size() == 5 && (s1[0] == 'J' && s1[1] != ' ')) && (s2.size() == 5 && (s2[0] == 'j' && s2[1] != ' ')))//s1������s2��С��
//		{
//			return s1;
//		}
//		//�Ƚϵ��������ӣ�����
//		else if ((s1.size()==s2.size()&&s1[0]=='2')//������10�ıȽ�
//				||(s1.size()==5&&s1[0]=='2'&&s2.size()==8&&s2[0]=='1'&&s2[1]=='0')//������10��
//				|| (s1.size() == 3 && s1[0] == '2' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//���Ӹ�10��
//				)
//		{
//			return s1;
//		}
//		else if ((s2.size() == s2.size() && s2[0] == '2')//������10�ıȽ�
//			|| (s2.size() == 5 && s2[0] == '2' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//������10��
//			|| (s2.size() == 3 && s2[0] == '2' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//���Ӹ�10��
//			)
//		{
//			return s2;
//		}
//		else//û��2���ǣ�10��jqk�Ƚ�
//		{
//			if ((s1.size() == s2.size() && s1[0] == 'K')//������10�ıȽ�
//			|| (s1.size() == 5 && s1[0] == 'K' && s2.size() == 8 && s2[0] == '1' && s2[1] == '0')//������10��
//			|| (s1.size() == 3 && s1[0] == 'K' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//���Ӹ�10��
//				)
//			{
//				return s1;
//			}
//			else if ((s1.size() == s2.size() && s2[0] == 'K')//������10�ıȽ�
//				|| (s2.size() == 5 && s2[0] == 'K' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//������10��
//				|| (s2.size() == 3 && s2[0] == 'K' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//���Ӹ�10��
//				)
//			{
//				return s2;
//			}
//			else if ((s1.size() == s2.size() && s1[0] == 'Q')//������10�ıȽ�
//				|| (s1.size() == 5 && s1[0] == 'Q' && s2.size() == 8 && s2[0] == '1' && s2[1] == '0')//������10��
//				|| (s1.size() == 3 && s1[0] == 'Q' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//���Ӹ�10��
//				)
//			{
//				return s1;
//			}
//			else if ((s1.size() == s2.size() && s2[0] == 'Q')//������10�ıȽ�
//				|| (s2.size() == 5 && s2[0] == 'Q' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//������10��
//				|| (s2.size() == 3 && s2[0] == 'Q' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//���Ӹ�10��
//				)
//			{
//				return s2;
//			}
//			else if ((s1.size() == s2.size() && s1[0] == 'Q')//������10�ıȽ�
//				|| (s1.size() == 5 && s1[0] == 'J' && s2.size() == 8 && s2[0] == '1' && s2[1] == '0')//������10��
//				|| (s1.size() == 3 && s1[0] == 'J' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//���Ӹ�10��
//				)
//			{
//				return s1;
//			}
//			else if ((s1.size() == s2.size() && s2[0] == 'J')//������10�ıȽ�
//				|| (s2.size() == 5 && s2[0] == 'J' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//������10��
//				|| (s2.size() == 3 && s2[0] == 'J' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//���Ӹ�10��
//				)
//			{
//				return s2;
//			}
//			else if ((s2.size()==5&&s1.size() == 8 &&s1[0]=='1'&&s1[1]!=' ') || (s2.size()==3&&s1.size() == 5&&s1[0]=='1'&&s1[1]!=' '))//s1�Ƕ���10������������10
//			{
//				return s1;
//			}
//			else if ((s1.size() == 5 && s2.size() == 8 && s2[0] == '1' && s2[1] != ' ') || (s1.size() == 3 && s2.size() == 5 && s2[0] == '1' && s2[1] != ' '))//s2�Ƕ���10������������10
//			{
//				return s2;
//			}
//			else if(s1.size()==s2.size())//3-9�ĵ��������ӣ������Ƚ�
//			{
//				if (s1[0] > s2[0])
//				{
//					return s1;
//				}
//				else
//				{
//					return s2;
//				}
//			}
//			else {
//				return "ERROR";
//			}
//		}
//
//	}
//	else
//	{
//	return "ERROR";
// }
//	
//	
//}
//int main()
//{
//	string orig = "2 2 2-10 10";
//	string s1;
//	string s2;
//	int i = 0;
//	for (; i < orig.size(); i++)
//	{
//		if (orig[i] == '-')
//		{
//			break;
//		}
//	}
//	//�ָ��ַ���
//	s1 = orig.substr(0, i);
//	s2 = orig.substr(i+1);
//	//ȥ���ո�
////	string tmp1= recall(s1);
////	string tmp2 = recall(s2);
//	string ret = cmp(s1, s2);
//	cout << ret << endl;
//	return 0;
//}


//class A
//{
//	int a = 2;
//	virtual void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
//};

//class B:public A
//{
//   void Print()
//	{
//		cout << "B::Print()" << endl;
//	}
//};

//int main()
//{
//	A a;
//	return 0;
//}