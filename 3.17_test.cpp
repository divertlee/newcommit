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

//51.N皇后
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
//        for (int col = 0; col < n; col++)//列排序---列用来回溯了
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
//        //判断行
//        for (int i = 0; i < row; i++)
//        {
//            if (chessboard[i][col] == 'Q')
//            {
//                return false;
//            }
//        }
//        //判断45度
//        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
//        {
//            if (chessboard[i][j] == 'Q')
//            {
//                return false;
//            }
//        }
//        //判断135度
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

//47. 全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
// 用used数组规避同层前后相同元素要排序
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

//46.全排列：不用设起点，用used数组规避使用过的上层元素
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
//{  //第一个if对比的是单个，对子和三个
//	if ((s1.size() == s2.size() && s1.size() <= 3)//一是除了10以外的数字和jqk间对比单个，对子和三个
//		||((s1.size()==4&&s1[0]!=s1[1])|| (s2.size() == 4 && s2[0] != s2[1]))//这里是10的对子
//		|| ((s1.size() == 6 && s1[0] != s1[1]) || (s2.size() == 6 && s2[0] != s2[1]))////这里是10的三个
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
//		else//没有2则先是是，10，jqk比较
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
//	else if(s1.size()==4||s1.size()==6)//s1是对子10或者是三个的10
//	 {
//		 return s1;
//	 }
//	else if (s2.size() == 4 || s2.size() == 6)//s1是对子10或者是三个的10
//	 {
//		 return s1;
//	 }
//	else//3-9的单个，对子，三个比较
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
//{  //第一个if是王炸
//	if (s1.size() == 11 && (s1[0] == 'j' || s1[0] == 'J'))//s1是王炸-返回s1
//	{
//		return s1;
//	}
//	else if (s2.size() == 11 && (s2[0] == 'j' || s2[0] == 'J'))//s2是王咋-返回s2
//	{
//		return s2;
//	}
//	//四炸进来
//	else if ((s1.size()==7&&s2.size()==7)//除了10之外的四炸
//		|| ((s1.size()==11&&s1[0]=='1')
//			||(s2.size() == 11 && s2[0] == '1'))//10炸
//		)
//	{
//		if (s1.size() == 7 && s1[0] == '2')//s1二炸
//		{
//			return s1;
//		}
//		else if (s2.size() == 7 && s2[0] == '2')//s2二炸
//		{
//			return s2;
//		}
//		else//没有2则是，10，jqk比较
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
//			else if ( s1.size() == 11 )//s1是10炸
//			{
//				return s1;
//			}
//			else if ( s2.size() == 11)//s2是10炸
//			{
//				return s2;
//			}
//			else//3-9的单个，对子，
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
//	else if (s1.size() == 9 && s2.size() == 9)//顺子
//	{
//		if (s1[0] == 'J')//J开头的顺子最大
//		{
//			return s1;
//		}
//		else if (s2[0] == 'J')//s2二炸
//		{
//			return s2;
//		}
//		else if (s1[0] == '1'&&s1[1]!=' ') //10开头的顺子
//		{
//				return s1;
//			}
//		else if (s2[0] == '1' && s2[1] != ' ') //10开头的顺子
//		{
//			return s2;
//		}
//			else//3-9开头的顺子
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
//	//第一个if对比的是单个，对子和三个
//	else if (s1.size()<=8 && s2.size() <= 8)//一是单个，对子，三个都能进循环
//	{
//		if (s1.size() <=2 && s2.size() == 5&&((s2[0]=='j'&&s2[1]!=' ') || (s2[0] == 'J' && s2[1] != ' ')))//s1出单个且s2出王
//		{
//			return s2;
//		}
//		else if (s2.size() <=2 && s1.size() == 5 && ((s1[0] == 'j' && s1[1] != ' ') || (s1[0] == 'J' && s1[1] != ' ')))//s2出单个且s1出王
//		{
//			return s1;
//		}
//		else if ((s1.size() == 5 && (s1[0] == 'j' && s1[1] != ' ')) && (s2.size() == 5 && (s2[0] == 'J' && s2[1] != ' ')))//s1出小王s2出大王
//		{
//			return s2;
//		}
//		else if ((s1.size() == 5 && (s1[0] == 'J' && s1[1] != ' ')) && (s2.size() == 5 && (s2[0] == 'j' && s2[1] != ' ')))//s1出大王s2出小王
//		{
//			return s1;
//		}
//		//比较单个，对子，三个
//		else if ((s1.size()==s2.size()&&s1[0]=='2')//跟除了10的比较
//				||(s1.size()==5&&s1[0]=='2'&&s2.size()==8&&s2[0]=='1'&&s2[1]=='0')//三个跟10比
//				|| (s1.size() == 3 && s1[0] == '2' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//对子跟10比
//				)
//		{
//			return s1;
//		}
//		else if ((s2.size() == s2.size() && s2[0] == '2')//跟除了10的比较
//			|| (s2.size() == 5 && s2[0] == '2' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//三个跟10比
//			|| (s2.size() == 3 && s2[0] == '2' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//对子跟10比
//			)
//		{
//			return s2;
//		}
//		else//没有2则是，10，jqk比较
//		{
//			if ((s1.size() == s2.size() && s1[0] == 'K')//跟除了10的比较
//			|| (s1.size() == 5 && s1[0] == 'K' && s2.size() == 8 && s2[0] == '1' && s2[1] == '0')//三个跟10比
//			|| (s1.size() == 3 && s1[0] == 'K' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//对子跟10比
//				)
//			{
//				return s1;
//			}
//			else if ((s1.size() == s2.size() && s2[0] == 'K')//跟除了10的比较
//				|| (s2.size() == 5 && s2[0] == 'K' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//三个跟10比
//				|| (s2.size() == 3 && s2[0] == 'K' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//对子跟10比
//				)
//			{
//				return s2;
//			}
//			else if ((s1.size() == s2.size() && s1[0] == 'Q')//跟除了10的比较
//				|| (s1.size() == 5 && s1[0] == 'Q' && s2.size() == 8 && s2[0] == '1' && s2[1] == '0')//三个跟10比
//				|| (s1.size() == 3 && s1[0] == 'Q' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//对子跟10比
//				)
//			{
//				return s1;
//			}
//			else if ((s1.size() == s2.size() && s2[0] == 'Q')//跟除了10的比较
//				|| (s2.size() == 5 && s2[0] == 'Q' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//三个跟10比
//				|| (s2.size() == 3 && s2[0] == 'Q' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//对子跟10比
//				)
//			{
//				return s2;
//			}
//			else if ((s1.size() == s2.size() && s1[0] == 'Q')//跟除了10的比较
//				|| (s1.size() == 5 && s1[0] == 'J' && s2.size() == 8 && s2[0] == '1' && s2[1] == '0')//三个跟10比
//				|| (s1.size() == 3 && s1[0] == 'J' && s2.size() == 5 && s2[0] == '1' && s2[1] == '0')//对子跟10比
//				)
//			{
//				return s1;
//			}
//			else if ((s1.size() == s2.size() && s2[0] == 'J')//跟除了10的比较
//				|| (s2.size() == 5 && s2[0] == 'J' && s1.size() == 8 && s1[0] == '1' && s1[1] == '0')//三个跟10比
//				|| (s2.size() == 3 && s2[0] == 'J' && s1.size() == 5 && s1[0] == '1' && s1[1] == '0')//对子跟10比
//				)
//			{
//				return s2;
//			}
//			else if ((s2.size()==5&&s1.size() == 8 &&s1[0]=='1'&&s1[1]!=' ') || (s2.size()==3&&s1.size() == 5&&s1[0]=='1'&&s1[1]!=' '))//s1是对子10或者是三个的10
//			{
//				return s1;
//			}
//			else if ((s1.size() == 5 && s2.size() == 8 && s2[0] == '1' && s2[1] != ' ') || (s1.size() == 3 && s2.size() == 5 && s2[0] == '1' && s2[1] != ' '))//s2是对子10或者是三个的10
//			{
//				return s2;
//			}
//			else if(s1.size()==s2.size())//3-9的单个，对子，三个比较
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
//	//分割字符串
//	s1 = orig.substr(0, i);
//	s2 = orig.substr(i+1);
//	//去除空格
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