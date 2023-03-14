#pragma once
#include<iostream>
#include<string>
using namespace std;

class B0 {
public:
	virtual void display() {
		cout << "B0::displayo" << endl;
	}
};

class B1 :public B0 {
public:
	void display() { cout << "B1::displayo" << endl; }
};

class D1 : public B1 {
public:
	void display()
	{cout << "D1::displayo" << endl;
}
};

void fun(B0 ptr) {
	ptr.display();
}

int main()
{
	B0 b0;
	B1 b1;
	D1 d1;
	fun(b0);
	fun(b1);
	fun(d1);
	return 0;
}








//51.N»Êºó
//class Solution {
//public:
//    vector<vector<string>>ret;
//
//    void recall(int n, int row, vector<string>& path)
//    {
//        if (row == n)
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int col = 0; col < n; col++)
//        {
//            if (istrue(row, col, path, n))
//            {
//                path[row][col] = 'Q';
//                recall(n, row + 1, path);
//                path[row][col] = '.';
//            }
//        }
//
//    }
//    bool istrue(int row, int col, vector<string>& path, int n)
//    {
//        //ÅÐ¶ÏÐÐ
//        for (int i = 0; i < row; i++)
//        {
//            if (path[i][col] == 'Q')
//            {
//                return false;
//            }
//        }
//        //ÅÐ¶Ï45¶È
//        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
//        {
//            if (path[i][j] == 'Q')
//            {
//                return false;
//            }
//
//        }
//        //ÅÐ¶Ï135¶È
//        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
//        {
//            if (path[i][j] == 'Q')
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    vector<vector<string>> solveNQueens(int n) {
//        ret.clear();
//        std::vector<std::string> path(n, std::string(n, '.'));
//        recall(n, 0, path);
//        return ret;
//    }
//};