//组合--回溯，横向：for循环改变判断元素起点，纵向：滑动窗口，符合就进入ret
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void forktree(int n, int k, int startn)
    {
        if (k == path.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = startn; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            forktree(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ret.clear();
        path.clear();
        forktree(n, k, 1);
        return ret;
    }
};
//216组合三
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void forktree(int n, int k, int sum, int startn)
    {
        if (path.size() == k)
        {
            if (sum == n)
            {
                ret.push_back(path);
            }
            return;
        }
        for (int i = startn; i <= 9 - (k - path.size()) + 1; i++)//宽度上剪枝
        {
            sum += i;
            path.push_back(i);
            if (sum > n)//深度上剪枝
            {
                sum -= i;
                path.pop_back();
                return;
            }
            forktree(n, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ret.clear();
        path.clear();
        forktree(n, k, 0, 1);
        return ret;
    }
};

//17.电话号码组合
class Solution {
public:
    string lettermap[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> ret;
    string path;
    void finddigitnum(const string& digits, int num)
    {
        if (num == digits.size())
        {
            ret.push_back(path);
            return;
        }
        int key = digits[num] - '0';//取出digits里字符转化为数字
        string letter = lettermap[key];//取出key数字对应的字母组
        for (int i = 0; i < letter.size(); i++)//遍历数字对应的字母组
        {
            path.push_back(letter[i]);
            finddigitnum(digits, num + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        ret.clear();
        path.clear();
        if (digits.size() == 0)
        {
            return ret;
        }
        finddigitnum(digits, 0);
        return ret;
    }
};
//39.组合总和
class Solution {
public:
    vector<int> path;
    vector<vector<int>>ret;
    void recall(vector<int>& candidates, int target, int sum, int num)
    {

        if (sum == target)//如果加和等于目标值，进入数组
        {
            ret.push_back(path);
            return;
        }
        for (int i = num; i < candidates.size(); i++)
        {

            sum += candidates[i];
            path.push_back(candidates[i]);
            if (sum > target)
            {
                path.pop_back();
                return;
            }
            recall(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        ret.clear();
        sort(candidates.begin(), candidates.end());
        recall(candidates, target, 0, 0);//第一个0是记录加和，第二个零是记录递归到第几个元素

        return ret;
    }
};

//40.组合总和2
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void recall(vector<int>& candidates, int target, int sum, int num, vector<bool>& used)
    {
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }
        for (int i = num; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if (i > num && candidates[i] == candidates[i - 1] && used[i] == false)//used数组为false即在同一层用过，需要跳过
            {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;//used数组为true即在统一树枝上用过，可以继续
            recall(candidates, target, sum, i + 1, used);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ret.clear();
        path.clear();
        vector<bool>used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        recall(candidates, target, 0, 0, used);
        return ret;
    }
};

//131.回文切割字符串
class Solution {
public:
    vector<vector<string>> ret;
    vector<string> path;
    void recall(string s, int num)
    {
        if (num >= s.size())
        {
            ret.push_back(path);
            return;
        }
        for (int i = num; i < s.size(); i++)
        {
            if (isvalidstring(s, num, i))//是回文
            {
                string str = s.substr(num, i - num + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            recall(s, i + 1);
            path.pop_back();
        }
    }
    bool isvalidstring(string s, int begin, int end)
    {
        for (int i = begin, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        ret.clear();
        path.clear();
        recall(s, 0);
        return ret;
    }
};