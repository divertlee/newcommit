#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//77.组合在[1，n]区间内取k个数来组合，把组合放进combine里；遍历1~n，先放第一个数入path，纵向递归第二层放第二数，依次放入path；当path的元素数大于等于k时把path放入ret然后返回
// 横向for循环起始点的值
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(int n, int k, int start)
//    {
//        if (path.size() == k)
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = start; i <= n; i++)
//        {
//            path.push_back(i);
//            recall(n, k, i + 1);
//            path.pop_back();
//        }
//
//    }
//    vector<vector<int>> combine(int n, int k) {
//        ret.clear();
//        path.clear();
//        recall(n, k, 1);
//        return ret;
//    }
//};
//数独
//class Solution {
//public:
//    bool recall(vector<vector<char>>& board)
//    {
//        for (int i = 0; i < 9; i++)//遍历行
//        {
//            for (int j = 0; j < board[i].size(); j++)
//            {
//                if (board[i][j] == '.')//空位
//                {
//                    for (char k = '1'; k <= '9'; k++)
//                    {
//                        if (isvalid(board, i, j, k))
//                        {
//                            board[i][j] = k;
//                            if (recall(board))return true;
//                            board[i][j] = '.';
//                        }
//                    }
//                    return false;//9组试完还没true就为false         
//                }
//                else
//                {
//                    continue;
//                }
//            }
//        }
//        return true;
//    }
//
//    bool isvalid(vector<vector<char>> board, int row, int col, char k)
//    {
//        //判断行
//        for (int j = 0; j < 9; j++)
//        {
//            if (board[row][j] == k)
//            {
//                return false;
//            }
//
//        }
//        //判断列
//        for (int i = 0; i < 9; i++)
//        {
//            if (board[i][col] == k)
//            {
//                return false;
//            }
//        }
//        //判断9宫格
//        int startrow = (row / 3) * 3;
//        int startcol = (col / 3) * 3;
//        for (int i = startrow; i < startrow + 3; i++)
//        {
//            for (int j = startcol; j < startcol + 3; j++)
//            {
//                if (board[i][j] == k)
//                {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//    void solveSudoku(vector<vector<char>>& board) {
//        recall(board);
//    }
//};

//幸运袋子
//int getfortune(vector<int>& path, int n, int pos, int sum, int mul)
//{
//    int count = 0;
//    for (int i = pos; i < n; i++)
//    {
//        sum += path[i];
//        mul *= path[i];
//        if (sum > mul)
//        
//            count += 1 + getfortune(path, n,i + 1, sum, mul);
//        
//        else if (path[i] == 1)
//        
//            count += getfortune(path, n, i + 1, sum, mul);     
//        else     
//            break; 
//
//        sum -= path[i];
//        mul /= path[i];
//        while (i < n - 1 && path[i] == path[i + 1])
//            i++;
//    }
//    return count;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> path(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> path[i];
//    }
//    sort(path.begin(), path.end());
//  int num=   getfortune(path, n,0,0,1);
//    cout << num << endl;
//    return 0;
//}

//void getfortune(vector<int>& path,int n,int num,int jia,int cheng,vector<bool>&used)
//{
//    
//    if (num > 1)//当装满后判断
//    {
//        if (jia>cheng)
//        {
//            sum.push_back(1);
//           // ret.clear();
//        }
//         else if(path[i])
//        {
//            return;
//        }
//    }
//    for (int i = num; i < n; i++)
//    {
//        if (i > 0 && path[i] == path[i - 1] && used[i - 1] == true)
//        {
//            break;
//        }
//        
//       jia += path[i];
//       cheng *= path[i];
//       used[i] = true;
//        getfortune(path, n, num + 1,jia,cheng,used);
//        jia -= path[i];
//        cheng /= path[i];
//        used[i] = false;
//    }
//
//}
//
//int main()
//{
//    sum.clear();
//    int n;
//    cin >> n;
//    vector<int> path;
//    int tmp = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> tmp;
//        path.push_back(tmp);
//    }
//    sort(path.begin(), path.end());
//    vector<bool> used(n, false);
//     getfortune(path, n,0,0,1,used);
//    cout << sum.size() << endl;
//    return 0;
//}

//int main()
//{ 
//	vector<int>path;
//	path.push_back(1);
//	path.push_back(2);
//	path.push_back(3);
//	path.push_back(4);
//	sort(path.begin(),path.end(),greater<int>());
//	for (auto e : path)
//	{
//		cout << e << " " ;
//	}
//	cout << endl;
//	path.erase(path.begin());
//	for (auto e : path)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int monyear[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//int getday(int year, int month, int day)
//{
//    int num = 0;
//    while (month > 0)
//    {
//        if (month == 2 && ((year % 400 == 0)|| (year % 4 == 0 && year % 100 != 0)))//是闰年
//        {
//            num += 29;
//            month--;
//            continue;
//        }
//        else
//        {
//            num += monyear[month];
//            month--;
//            continue;
//        }
//    }
//    num += day;
//    return num;
//}
//
//int main()
//{
//    int year, month, day;
//    while (cin >> year >> month >> day)
//    {
//        int realday = getday(year, month-1, day);
//        cout << realday << endl;
//    }
//    return 0;
//}


//class B0 {
//public:
//	virtual void display() {
//		cout << "B0::displayo" << endl;
//	}
//};
//
//class B1 :public B0 {
//public:
//	void display() { cout << "B1::displayo" << endl; }
//};
//
//class D1 : public B1 {
//public:
//	void display()
//	{
//		cout << "D1::displayo" << endl;
//	}
//};
//
//void fun(B0 ptr) {
//	ptr.display();
//}
//
//int main()
//{
//	B0 b0;
//	B1 b1;
//	D1 d1;
//	fun(b0);
//	fun(b1);
//	fun(d1);
//	return 0;
//}