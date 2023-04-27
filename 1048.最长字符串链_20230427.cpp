// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 * @lcpr version=21907
 *
 * [1048] 最长字符串链
 *
 * https://leetcode.cn/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (48.90%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    20.8K
 * Total Submissions: 40.7K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * 给出一个单词数组 words ，其中每个单词都由小写英文字母组成。
 *
 * 如果我们可以 不改变其他字符的顺序 ，在 wordA 的任何地方添加 恰好一个 字母使其变成 wordB ，那么我们认为 wordA 是 wordB 的
 * 前身 。
 *
 *
 * 例如，"abc" 是 "abac" 的 前身 ，而 "cba" 不是 "bcad" 的 前身
 *
 *
 * 词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word1 是 word2 的前身，word2
 * 是 word3 的前身，依此类推。一个单词通常是 k == 1 的 单词链 。
 *
 * 从给定单词列表 words 中选择单词组成词链，返回 词链的 最长可能长度 。
 *
 *
 * 示例 1：
 *
 * 输入：words = ["a","b","ba","bca","bda","bdca"]
 * 输出：4
 * 解释：最长单词链之一为 ["a","ba","bda","bdca"]
 *
 *
 * 示例 2:
 *
 * 输入：words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * 输出：5
 * 解释：所有的单词都可以放入单词链 ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
 *
 *
 * 示例 3:
 *
 * 输入：words = ["abcd","dbqca"]
 * 输出：1
 * 解释：字链["abcd"]是最长的字链之一。
 * ["abcd"，"dbqca"]不是一个有效的单词链，因为字母的顺序被改变了。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] 仅由小写英文字母组成。
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    bool check_is(string &a, string &b)
    {
        int al = a.size();
        int bl = b.size();
        if (al != (bl - 1))
        {
            return false;
        }
        bool flag = false;
        int left = 0;
        int right = 0;
        while (left < al && right < bl)
        {
            if ((a[left]) != (b[right]))
            {
                if (flag)
                {
                    return false;
                }
                flag = true;
                right++;
            }
            else
            {
                left++;
                right++;
            }
        }
        if (left == al && right == bl)
        {
            return true;
        }
        if (left == al && (right == (bl - 1) && !flag))
        {
            return true;
        }
        return false;
    }
    int result = 0;
    vector<vector<string>> vvp;
    unordered_map<string, int> umi;
    int longestStrChain(vector<string> &words)
    {
        vvp.resize(18);
        for (int i = 0; i < words.size(); i++)
        {
            int sl = words[i].size();
            vvp[sl].push_back(words[i]);
        }

        for (int ceng = 0; ceng <= 16; ceng++)
        {
            for (int j = 0; j < vvp[ceng].size(); j++)
            {
                int sss = dfs(0, vvp[ceng][j]);
                result = max(result, sss);
            }
        }
        return result;
    }
    int dfs(int cur, string &s)
    {
        if (umi.count(s) > 0)
        {
            return umi[s];
        }

        result = max(result, cur);
        int cur_ceng = s.size();
        int next_ceng = cur_ceng + 1;
        int son = 0;
        if (next_ceng <= 16)
        {
            for (int j = 0; j < vvp[next_ceng].size(); j++)
            {
                if (check_is(s, vvp[next_ceng][j]))
                {
                    int temp_son = dfs(cur + 1, vvp[next_ceng][j]);
                    son = max(son, temp_son);
                }
            }
        }
        umi[s] = son + 1;
        return umi[s];
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["a","b","ba","bca","bda","bdca"]\n
// @lcpr case=end

// @lcpr case=start
// ["xbc","pcxbcf","xb","cxbc","pcxbc"]\n
// @lcpr case=end

// @lcpr case=start
// ["abcd","dbqca"]\n
// @lcpr case=end

// @lcpr case=start
// ["biltnzk","jxwakrfxsifoj","uzdwyaxvcsr","sqqgkhwbf","tnoftkolx","ipmtvxcwe","zsucxrqkhahuo","qngglugvm","kvohqyedig","njoxacsnddwrg","vwtnxw","kjjourlrzpgeem","xcs","pfsgimurs","lsifyg","uzwyxcsr","muzdwcyanxvcstr","teqyrlhbvcv","rkga","tudezgzbnzb","uzwyaxvcsr","qvzkmgfulby","x","muzdwcyianxvcstr","koqyig","gl","aqcacmy","pmvwe","eskofqduddkhykr","pm","saxxd","ds","iemm","tudegzbz","yipsawmxbp","qyrlhbvcv","yxuhwkzvoczoz","zsucxqkahuo","kga","zwziivbijeiig","wffaheemjnjahzdd","zcxkahuo","djjjsulms","plxh","ffpasoizwhtu","zwziivijeii","fyvpzegautteiv","qszaitzfzv","uwoghcy","qqgkhwbf","eteqyrllhbvcvg","qknspkhngorof","qwvzkmgfuljbyz","grkte","grikrnwezryi","xjbpvekneaxn","cy","wnhnyqmpbsum","m","offqllgj","plxhib","omblqcoktkyf","pasw","prsngzx","offlj","rvvudgpixa","djjjjsulmmrs","gt","mpfsgimurs","cxkahuo","ipmtvxcwue","pqrbaoquxqemv","prqqv","tnoftfkolx","jfzzaw","rshquwmrboghccy","ebqhvwewzzmqif","rrd","dvjjjjqsulmmrs","pfsiurs","crnruydj","rvqgeqql","djsums","prbaquqemv","bs","dzytccvny","kce","llfv","jfzaw","qwvzkmgbfuljbyz","kgieph","hnympsum","ewv","vfgel","rklga","llzqbfv","gte","jckqurkg","qngglugm","tudgzbz","ipmvcwe","rr","kkcev","djjjjsulmrs","llqbfv","offqlgj","paswu","tlrlcnnrsrf","jcckqurkg","jjourlpgeem","nvl","shquwmrboghccy","vncfgelm","dgcdgjcksk","vvhvmibflb","juifgeqkaectlcj","scvdl","whcy","yipswmbp","wcy","hbqq","bsth","etjurltvpsuy","dzvytcccevnceyq","apqrbaoquxqemv","kvohuqyediyig","lenybbukzftz","ffpasoiuztwhtu","lzlhzqibfv","wfeemjnjahzdd","djsulms","xtudezgzbnzb","eemjhzdd","scavdil","guchrvaqbe","nvll","sxzfpzjmxvu","dytccvny","grikrnjwezryi","prng","ntvmcwwpzo","laqgcacyxmym","mglosifyg","nynvlqll","vwtn","lh","zhhxducgelhy","prg","kghierph","zsucxrqkhahuom","kvohqydig","eemjhzd","offiqcdllgji","dyc","toflx","dzvytccvney","ghvb","to","guchrvab","wyimthhfzndppwt","elbqhvwewzzmqif","hkghiyerph","hkghiyejrph","hlsioorugbsuu","c","kgierph","bstbghj","prbquqev","mpfsdgimurs","zfpjvu","zfpvu","yxuhwkzvoczfgoz","gel","ntvmcpzo","ekofqduddkhykr","ekofqdddhykr","rqeql","nhnympsum","xhoqlfolk","ipmtvxcwuje","wgmhjhdmnqot","bsh","rvncfgelm","hkahpbb","lzlzqibfv","xoqlfok","tnoftfkogwgplx","ekofqdddkhykr","zwiieii","ujfzzaw","jfzw","djsms","scavdpilj","tnoftfkoglx","ps","vwtnw","scavhdpilj","scayvhdpuilji","pdrshqngzx","crnrud","wmhjhdmnqot","wghmhjhdmnqot","vbyipsawmxbp","qknsapkhngorof","wymthhfzndppwt","wxcs","dzvytccevney","acacmy","dycy","teqyrllhbvcv","uzwyxcs","wmhjhdmnqt","qvzkmgfulbyz","qngglum","zhhxgdyukcgelhy","oj","iljes","bstbh","laqcacxmy","tofx","ke","yivkqoek","djjjsulmrs","lbirdzvttzze","l","zhhxgdukcgelhy","grikvrnjwezryi","bltz","npynvlqll","gvb","okzrs","urbarfkmnlxxn","qsyzaixtzfazv","dytcy","h","kohqyig","hgri","ojdxm","ujfdfzzaw","qyrhbvcv","ebqhvwewzmqif","uzwxcs","lebzf","ysijvkwqmoekromh","wffaeemjnjahzdd","crnrduyndj","ujfdmfzzaw","laqgcacyxmzgym","jjourlrpgeem","kvohqyediyig","lebukzf","zwiijeii","guchrvb","omoktkyf","hpgt","yikoek","ysijvkwqoekromh","tvpo","ysijvkqoekromh","xbgq","d","abmtk","ors","rnrd","xzrugvlzduaxhzc","njoxacjsnddwrg","yipswmxbp","xqsyzaixtzfazv","urbrfknlxxn","sxzfpjxvu","prbaquxqemv","dvjjjjsulmmrs","kviahvqu","urbfknx","qvmgfulby","yikqoek","zsucxrqkhfahuomm","koqyg","djss","moxpfsdgimlurs","qeql","urbrfknlxn","kgieh","qnspkhngorof","plxyhib","scyayvhdpuiljki","vvhvmbflb","lpzluhzqxibfv","kkcbev","hpzgty","nyvlqll","kvahvu","rklgja","ipmtavxcwuje","lbirdzvvttzze","psw","fpasoiwhtu","dgcdgjckk","qknhsapkhngorof","qszaixtzfazv","tvp","abmtvk","uwrboghcy","hbq","crnruyd","etjurltvsuy","etjurltyvpsuy","lenbukzf","teqyrllhbvcvg","ipmvwe","o","crnryduyndj","lbirdzvvqfttzze","tnoftfkowglx","ipmtavxcwujre","omlcoktkyf","rnperyemtmqh","bltnzk","sxzfpzjxvu","uzdwyaxvcstr","bq","rvvugpixa","laqcacxmym","wffeemjnjahzdd","fpvu","xjbpvekngeyaxbn","dzvytccevncey","qgly","scavdl","fw","tox","toftklx","prbaoquxqemv","ztrobzqiukdkcbv","yivkqoekr","feemjnjhzdd","plxhi","cp","fyvpzgauttei","prshqngzx","kplxyrhib","suwrboghcy","kviahvu","mvwe","dzvytccvny","hbqwq","prbquqemv","lzlhzqxibfv","ll","omblcoktkyf","toftlx","lpzlhzqxibfv","tudegzbnz","ddgcdgjcgkspk","kgih","xjbpvekneaxbn","suwrboghccy","zwiiijeii","dytccy","ympsum","jxwakfxsifoj","uwhcy","yxuhwkzvoczfoz","xzfpjvu","lenybbukzft","b","llqfv","laqgcacyxmgym","xq","scavdilj","zwziivbijaeiig","scyayvhdpuilji","amvevfulhsd","dss","tlrlcnnrs","uzwyaxcsr","qspkhngorof","etjurtvsuy","wgqhmhjhhdmnqot","tvmpo","tnoftklx","qgflby","mlosifyg","oqyg","gchvb","t","offqcdllgj","ziieii","zwziivbijeii","vp","lpb","fyvprzegauttejiv","vtn","amefulhsd","llf","muzdwyaxvcstr","zucxqkahuo","pfsgiurs","obstbghj","ipmqtavxcwuzjrbe","djjsulms","qvmgflby","ljpzluhzqxibfv","jjourlrzpgeem","zrugvlduaxhzc","xbpvkneaxn","ljpzluhzgqyxibfv","yivkqoekrh","laqcacyxmym","nyvll","muzdwcyaxvcstr","fyvpzegauttejiv","offlgj","vnfgelm","eteiqyrllhbvcvg","zsucxrqkhahuomm","ibiltnzk","rklgjae","fpasoizwhtu","t","zhhxdukcgelhy","fpasoiwu","xzfpjxvu","tlrlcnnrysrf","ojx","mpum","lxh","eturtvsuy","rklgbjaae","kahpbb","qngglugmfvmp","fielbqtcri","xzruogvlzduaxhzc","rshquwmrbtoghccy","nyvlll","lbirdzvvqttzze","dgcdgjckspk","vvhvmibfilb","dzvytcccevncey","g","vwe","zwxcs","k","jourlpgeem","cpk","cds","tlrlcnnrsr","ivemm","fgel","grktse","urbfknlxn","qwvzkmgfulbyz","xjbpvekngeaxbn","wphuutlgczfspyga","xbq","offqcdllgji","vbyipsakwmxbp","qyrhbvc","ygzpztbno","xhogqlfolk","ujffzzaw","xbnmgq","uwohcy","rnperyemqh","prbqqev","lenybukzf","mxpfsdgimurs","ga","hpt","moxpfsdgimurs","vb","offqcllgj","rklgbjae","lifg","ztrobzzqiukdkcbv","xoqok","cs","snaxxd","cdds","qknhsapkhngorohf","rvqgeql","rnperyemmqh","scavhdpuilji","urbfknlx","rvvugixa","ygzpztbndon","zrugvlzduaxhzc","shuwmrboghccy","mlsifyg","xhoqlfok","wfeemjnjhzdd","lbzf","wythhfzndppwt","mglqosifyg","ojxm","kvohuqyevdiyig","grte","prsngz","eteeiqyrllhbvcvg","dytccny","qngglugfvmp","kohqydig","fu","qgfly","tvmcpzo","tnoftfkowgplx","zruglduaxzc","yijvkqoekrh","xqsyzaixtzfdazv","ipmqtavxcwuzjre","omloktkyf","ympum","lzlzqbfv","pasowu","rvqeql","qngglugvmp","hkghierph","eemjhz","feemnjhzdd","c","yxpuhwkzvoczfgoz","dgcgjckk","lbz","yxuwkzvoczoz","zrugvlduaxzc","ntvmcwpzo","fzw","ygzpmztbndon","rvncfgxelm","mpm","tudezgzbnz","bltzk","ffpasoiuzwhtu","cd","r","okrs","byipsawmxbp","prsqngzx","wnhnyqmpsum","ipmqtavxcwujre","w","fpasoiwtu","plxyrhib","bstbhj","xbnmrgq","ipmtvcwe","urbfkn","nympsum","qtngglugmfvmpt","jckqurg","hgr","hpzgt","rvvxudgpixa","ysijvkqoekrh","lebkzf","guchvb","kvohqyediyg","amvefulhsd","suwmrboghccy","fvu","ibdiltnzk","rnrud","iem","urbarfknlxxn","ygzpztbnon","prsng","zcxqkahuo","ffpeasoiuztwhtu","laqcacmy","qszaitzfazv","xbngq","qvkmgfulby","scavhdpuilj","zsucxrqkahuo","v","qtngglugmfvmp","ysijvkqoekrmh","lfg","prqqev","pasoiwu","p","tvmcpo","kcev","im","crnrduydj","vfgelm","ddgcdgjckspk","ivqemm","ljpzluhzgqxibfv","lenybukzft","nhnyqmpsum","iljesr","hp","tqyrlhbvcv","eemnjhzdd","xbpvekneaxn","wghmhjhhdmnqot","uwboghcy","guchrvabe","xoqfok","fyvpzgautteiv","pg","zwiivijeii","qvgflby","lsifg"]\n
// @lcpr case=end

 */
