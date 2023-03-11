#include<iostream>
#include<vector>
using namespace std;

//47.ȫ���ж�
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
//            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)//used�����¼ͬ���
//            {
//                continue;
//            }
//            if (used[i] == false)//��������usedΪtrue���ϲ��ù���Ԫ�أ����ﲻ����
//            {
//                path.push_back(nums[i]);
//                used[i] = true;
//                recall(nums, used);
//                used[i] = false;
//                path.pop_back();
//            }
//        }
//    }
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        ret.clear();
//        path.clear();
//        vector<bool> used(nums.size(), false);
//        sort(nums.begin(), nums.end());
//        recall(nums, used);
//        return ret;
//    }
//};

//46.ȫ����---����Ҫstartindex�жϵݹ����
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
//            if (used[i] == true)
//            {
//                continue;
//            }
//            path.push_back(nums[i]);
//            used[i] = true;
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

//  491.����������
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(vector<int>& nums, int startindex)
//    {
//        //�ռ�
//        if (path.size() > 1)
//        {
//            ret.push_back(path);
//        }
//        if (startindex >= nums.size())
//        {
//            return;
//        }
//        int used[201] = { 0 };
//        for (int i = startindex; i < nums.size(); i++)
//        {
//            if ((path.size() > 0 && nums[i] < path.back()) || used[nums[i] + 100] == 1)
//            {
//                continue;
//            }
//            used[nums[i] + 100] = 1;//��¼������治��������
//            path.push_back(nums[i]);
//            recall(nums, i + 1);
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        ret.clear();
//        path.clear();
//        recall(nums, 0);
//        return ret;
//    }
//};

//90.�Ӽ�2
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(vector<int>& nums, int startindex, vector<bool>& used)
//    {
//        ret.push_back(path);
//        if (startindex >= nums.size())
//        {
//            return;
//        }
//        for (int i = startindex; i < nums.size(); i++)
//        {
//            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
//            {
//                continue;
//            }
//            path.push_back(nums[i]);
//            used[i] = true;
//            recall(nums, i + 1, used);
//            path.pop_back();
//            used[i] = false;
//        }
//    }
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        ret.clear();
//        path.clear();
//        vector<bool> used(nums.size(), false);
//        sort(nums.begin(), nums.end());
//        recall(nums, 0, used);
//        return ret;
//    }
//};



    //vector<vector<int>> result;
    //vector<int> path;
    //void backtracking(vector<int>& nums, int startIndex) {
    //    result.push_back(path); // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
    //    if (startIndex >= nums.size()) { // ��ֹ�������Բ���
    //        return;
    //    }
    //    for (int i = startIndex; i < nums.size(); i++) {
    //        path.push_back(nums[i]);
    //        backtracking(nums, i + 1);
    //        path.pop_back();
    //    }
    //}



    //int main()
    //{
    //    vector<int> nums;
    //    nums.push_back(0);
    //    backtracking(nums, 0);
    //    return 0;
    //}

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//
//// ����ָ������
//typedef void(*VFPtr)();
//void PrintVFTbale(VFPtr vft[])
//{
//	for (int i = 0; vft[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, vft[i]);
//		vft[i]();
//	}
//	cout << endl;
//}
//
//int main()
//{
//    Base1 b1;
//    PrintVFTbale((VFPtr*)(*(void**)&b1));
//    Base2 b2;
//    PrintVFTbale((VFPtr*)(*(void**)&b2));
//    Derive d;
//    PrintVFTbale((VFPtr*)(*(void**)&d));
//    Base2* ptr2 = &d;
//    PrintVFTbale((VFPtr*)*((void**)ptr2));
//    return 0;
//}

//class Base1 {
//public:
//    virtual void func1() { cout << "Base1::func1" << endl; }
//    virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//    int b1;
//};
//class Base2 {
//public:
//    virtual void func1() { cout << "Base2::func1" << endl; }
//    virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//    int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//    virtual void func1() { cout << "Derive::func1" << endl; }
//    virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//    int d1;
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//    cout << " ����ַ>" << vTable << endl;
//    for (int i = 0; vTable[i] != nullptr; ++i)
//    {
//        printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
//        VFPTR f = vTable[i];
//        f();
//    }
//    cout << endl;
//}
//int main()
//{
//    Derive d;
//    VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//    PrintVTable(vTableb1);
//    VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//    PrintVTable(vTableb2);
//    return 0;
//}


//typedef void(*vfptr)();//�����˺���ָ��
//void PrintVtalbe(vfptr vtable[])//������ָ������
//{
//    for (int i = 0; vtable[i] != nullptr; i++)
//    {
//        printf("[%d]:%p->", i, vtable[i]);
//        vfptr f = vtable[i];
//        f();    
//    }
//    cout << endl;
//}
//
//class Base1 {
//public:
//    virtual void func1() { cout << "Base1::func1" << endl; }
//    virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//    int b1;
//};
//class Base2 {
//public:
//    virtual void func1() { cout << "Base2::func1" << endl; }
//    virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//    int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//    virtual void func1() { cout << "Derive::func1" << endl; }
//    virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//    int d1;
//};
//
//int main()
//{
//    Base1 b1;
//    Base2 b2;
//    vfptr* vTab1 = (vfptr*)(*(void**)&b1);
//    PrintVtalbe(vTab1);
//  //  vfptr* vTab2 = (vfptr*)(*(void**)&b2);
//   // PrintVtalbe(vTab2);
//    Derive d;
//  //  vfptr* vTab3 = (vfptr*)(*(void**)&d);
//    //PrintVtalbe(vTab3);
//  //  vfptr* vTab4 = (vfptr*)(*(int*)((char*)&d + sizeof(Base1)));
//    //PrintVtalbe(vTab4);
//    return 0;
//}
//class A {
//public:
//    virtual void func1() { cout << "Base::func1" << endl; }
//    virtual void func2() { cout << "Base::func2" << endl; }
//private:
//    int _a;
//};
//class B :public A {
//public:
//    virtual void func1() { cout << "Derive::func1" << endl; }
//    virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//    int _b;
//};
//int main()
//{
//    A a;
//    B b;
//    vfptr* vtab1 = (vfptr*)(*((void**)&a));
//    vfptr* vtab2 = (vfptr*)(*((void**)&b));
//    PrintVtalbe(vtab1);
//    PrintVtalbe(vtab2);
//    return 0;
//}