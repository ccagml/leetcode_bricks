/*
 * @lc app=leetcode.cn id=6183 lang=cpp
 *
 * [6183] 字符串的前缀分数和
 *
 * https://leetcode.cn/problems/sum-of-prefix-scores-of-strings/description/
 *
 * algorithms
 * Hard (36.02%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 15.2K
 * Testcase Example:  '["abc","ab","bc","b"]'
 *
 * 给你一个长度为 n 的数组 words ，该数组由 非空 字符串组成。
 *
 * 定义字符串 word 的 分数 等于以 word 作为 前缀 的 words[i] 的数目。
 *
 *
 * 例如，如果 words = ["a", "ab", "abc", "cab"] ，那么 "ab" 的分数是 2 ，因为 "ab" 是 "ab" 和
 * "abc" 的一个前缀。
 *
 *
 * 返回一个长度为 n 的数组 answer ，其中 answer[i] 是 words[i] 的每个非空前缀的分数 总和 。
 *
 * 注意：字符串视作它自身的一个前缀。
 *
 *
 *
 * 示例 1：
 *
 * 输入：words = ["abc","ab","bc","b"]
 * 输出：[5,4,3,2]
 * 解释：对应每个字符串的答案如下：
 * - "abc" 有 3 个前缀："a"、"ab" 和 "abc" 。
 * - 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" ，1 个字符串的前缀为 "abc" 。
 * 总计 answer[0] = 2 + 2 + 1 = 5 。
 * - "ab" 有 2 个前缀："a" 和 "ab" 。
 * - 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" 。
 * 总计 answer[1] = 2 + 2 = 4 。
 * - "bc" 有 2 个前缀："b" 和 "bc" 。
 * - 2 个字符串的前缀为 "b" ，1 个字符串的前缀为 "bc" 。
 * 总计 answer[2] = 2 + 1 = 3 。
 * - "b" 有 1 个前缀："b"。
 * - 2 个字符串的前缀为 "b" 。
 * 总计 answer[3] = 2 。
 *
 *
 * 示例 2：
 *
 * 输入：words = ["abcd"]
 * 输出：[4]
 * 解释：
 * "abcd" 有 4 个前缀 "a"、"ab"、"abc" 和 "abcd"。
 * 每个前缀的分数都是 1 ，总计 answer[0] = 1 + 1 + 1 + 1 = 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] 由小写英文字母组成
 *
 *
 */

// @lc code=start

// class Solution
// {
// public:
//     class Node
//     {
//     public:
//         int val; // -- 计数
//         unordered_map<int, Node *> um;
//         Node(int i)
//         {
//             val = i;
//         }
//     };
//     Node *root;
//     vector<int> result;
//     vector<string> &my_words;
//     void insert(string &ss, int cur, Node *cur_root)
//     {
//         if (cur >= ss.size())
//         {
//             return;
//         }
//         int index = ss[cur] - 'a';
//         if (cur_root->um.count(index) < 1)
//         {
//             cur_root->um[index] = new Node(0);
//         }
//         cur_root->um[index]->val++;
//         insert(ss, cur + 1, cur_root->um[index]);
//     }

//     void check(int i, int cur, int all_val, Node *cur_root)
//     {
//         string ss = my_words[i];
//         int index = ss[cur] - 'a';

//         all_val += cur_root->um[index]->val;
//         if (cur + 1 < ss.size())
//         {
//             check(i, cur + 1, all_val, cur_root->um[index]);
//         }
//         else
//         {
//             result[i] = all_val;
//             // std::cout << i << ":" << result[i] << std::endl;
//         }
//     }
//     vector<int> sumPrefixScores(vector<string> &words)
//     {
//         my_words = words;
//         root = new Node(0);
//         for (int i = 0; i < words.size(); i++)
//         {
//             insert(words[i], 0, root);
//         }
//         // std::cout << "111" << std::endl;
//         vector<int> my_result(words.size());
//         result = my_result;
//         // std::cout << "222" << std::endl;
//         for (int i = 0; i < words.size(); i++)
//         {
//             check(i, 0, 0, root);
//         }
//         // std::cout << "333" << std::endl;
//         return result;
//     }
// };
// 函数递归调用会超时,改成循环

class Solution
{
public:
    class Node
    {
    public:
        int val; // -- 计数
        unordered_map<int, Node *> um;
        Node(int i)
        {
            val = i;
        }
    };
    Node *root;
    vector<int> result;

    vector<int> sumPrefixScores(vector<string> &words)
    {
        root = new Node(0);
        for (int i = 0; i < words.size(); i++)
        {
            Node *cur_root = root;
            for (int j = 0; j < words[i].size(); j++)
            {
                int index = words[i][j] - 'a';
                if (cur_root->um.count(index) < 1)
                {
                    cur_root->um[index] = new Node(0);
                }
                cur_root->um[index]->val++;
                cur_root = cur_root->um[index];
            }
        }
        // std::cout << "111" << std::endl;
        vector<int> my_result(words.size());
        result = my_result;
        // std::cout << "222" << std::endl;
        for (int i = 0; i < words.size(); i++)
        {
            // check(i, 0, 0, root);
            Node *cur_root = root;
            int all_val = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                int index = words[i][j] - 'a';
                all_val += cur_root->um[index]->val;
                cur_root = cur_root->um[index];
            }
            result[i] = all_val;
        }
        // std::cout << "333" << std::endl;
        return result;
    }
};
// @lc code=end
