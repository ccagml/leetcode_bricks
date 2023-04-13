using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

void test_pair()
{
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
    std::pair<int, int> p1 = std::make_pair(n, a[1]);
    std::pair<int, int> p2{1, 3};
    // (1,2)
    std::cout << "(" << p1.first << "," << p1.second << ")\n";
}
void test_tuple()
{
    std::tuple<double, char, std::string> t1 = std::make_tuple(3.8, 'A', "LisaSimpson");
    //(3.8,A,LisaSimpson)
    std::cout << "(" << std::get<0>(t1) << "," << std::get<1>(t1) << "," << std::get<2>(t1) << ")\n";
    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = t1;
    //(3.8,A,LisaSimpson)
    std::cout << "(" << gpa1 << "," << grade1 << "," << name1 << ")\n";
}
void test_string()
{
    std::string str1 = "hello";
    std::string str2 = str1 + "world";
    // helloworld
    std::cout << str2 << '\n';
    // 查找find
    std::string::size_type pos1 = str2.find("o"); // pos1 = 4
    // 4
    std::cout << pos1 << '\n';
    std::string::size_type pos2 = str2.find("w"); // pos2 = 5
    std::cout << pos2 << '\n';
    std::string::size_type pos3 = str2.find("rl"); // pos3 = 7
    std::cout << pos3 << '\n';
    // 裁剪substr
    std::string str3 = "helloworld";
    std::string str4 = str3.substr(0, 5); // hello
    std::string str5 = str3.substr(6);    // world
    std::string str6 = str3.substr(1, 3); // ell
    // 插入某个位置insert
    std::string s = "hello";
    // insert(size_typeindex,size_typecount,charch)
    s.insert(0, 1, 'a'); // ahello
    // insert(size_typeindex,const char*s)
    s.insert(2, "bbb"); // ahbbbello
    // 尾部插入
    //  push_back尾部插入一个字符char
    s.push_back('c'); // ahbbbelloc
    // append尾部插入字符串
    s.append("ddd"); // ahbbbellocddd
    // append插入多次
    s.append(3, 'f'); // ahbbbellocdddfff
    // append插入一部分
    s.append("hello", 3, 3); // ahbbbellocdddffflo
    s.append("hello", 1, 2); // ahbbbellocdddfffloel
    // 替换
    std::string str{"Thequickbrownfoxjumpsoverthelazydog."};
    // 从第10位开始的后5位替换成 red
    str.replace(10, 5, "red"); // Thequickbrredxjumpsoverthelazydog.
    // 前3位替换成 A
    str.replace(str.begin(), str.begin() + 3, 1, 'A'); // Aquickbrredxjumpsoverthelazydog.
    // 重置长度
    std::string new_resize_str = "helloworld";
    new_resize_str.resize(5); // hello
    // 交换
    std::string a = "AAA";
    std::string b = "BBB";
    a.swap(b); // a=BBB  b=AAA
    // 字符串转数字
    std::string str_int = "123456";
    std::string str_long = "123456789987";
    std::string str_longlong = "123456789987654321";
    int int_str = std::stoi(str_int);                   // 123456
    long long_str = std::stol(str_long);                // 123456789987
    long long long_long_str = std::stoll(str_longlong); // 123456789987654321
    // 数字转字符串
    double f = 23.43;
    double f1 = 123456;
    std::string f_str = std::to_string(f);   // 23.430000
    std::string f_str1 = std::to_string(f1); // 123456.000000
    int i2 = 123456789;
    std::string i_str1 = std::to_string(i2); // 123456789
    // a -> std::toupper -> A
    std::cout << "a"
              << " -> std::toupper -> " << char(std::toupper('a')) << std::endl;
    // A -> std::tolower -> a
    std::cout << "A"
              << " -> std::tolower -> " << char(std::tolower('A')) << std::endl;

    // 翻转字符串
    string reverse_str = "abcdefghijklmn";
    reverse(reverse_str.begin(), reverse_str.end());
    std::cout << reverse_str << std::endl;
}
void test_array()
{
    std::array<int, 3> a1{{1, 2, 3}};
    a1 = {3, 2, 1};
    // 3,2,1
    std::cout << a1[0] << "," << a1[1] << "," << a1[2] << '\n';
    std::sort(a1.begin(), a1.end()); // 1,2,3
    // 交换
    std::swap(a1[0], a1[1]); // 2,1,3
}
void test_unordered_map()
{
    // Createanunordered_mapofthreestrings(thatmaptostrings)
    std::unordered_map<std::string, std::string> um = {{"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}};
    // 遍历

    // 遍历方式1 = {
    // "BLUE" = "#0000FF"
    // "GREEN" = "#00FF00"
    // "RED" = "#FF0000"
    // }

    std::cout << "遍历方式1 = {\n";
    for (const std::pair<std::string, std::string> &n : um)
    {
        std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
    }
    std::cout << "}\n";

    // 遍历方式2 = {
    // "BLUE" = "#0000FF"
    // "GREEN" = "#00FF00"
    // "RED" = "#FF0000"
    // }
    std::cout << "遍历方式2 = {\n";
    // 遍历
    for (const auto &n : um)
    {
        std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
    }
    std::cout << "}\n";

    // 遍历方式3 = {
    // "BLUE" = "#0000FF"
    // "GREEN" = "#00FF00"
    // "RED" = "#FF0000"
    // }
    std::cout << "遍历方式3 = {\n";
    // 遍历
    for (auto n : um)
    {
        std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
    }
    std::cout << "}\n";

    // 遍历方式4 = {
    // "BLUE" = "#0000FF"
    // "GREEN" = "#00FF00"
    // "RED" = "#FF0000"
    // }
    std::cout << "遍历方式4 = {\n";
    // 指针遍历
    for (auto iter = um.begin(); iter != um.end(); ++iter)
    {
        std::cout << "\"" << iter->first << "\" = \"" << iter->second << "\"\n";
    }
    std::cout << "}\n";

    std::unordered_map<char, std::vector<int>> index;
    index['a'].push_back(1);
    index['a'].push_back(2);
    index['a'].push_back(3);
    for (std::pair<char, std::vector<int>> &&tt : index)
    {
        // 1,2,3,
        for (int i = 0; i < tt.second.size(); i++)
        {
            std::cout << tt.second[i] << ",";
        }
    }

    // 设置
    um["BLACK"] = "#000000";
    // 设置值 "BLACK" = "#000000"
    std::cout << "设置值 \"BLACK\" = \"" << um["BLACK"] << "\"\n";
    // 判断空 um.empty() 是否为空0
    std::cout << "判断空 um.empty() 是否为空" << um.empty() << '\n';
    // 判断 size:4
    std::cout << "判断 size:" << um.size() << '\n';
    // 清空
    um.clear();
    // 清空 um.clear() 后是否为空1
    std::cout << "清空 um.clear() 后是否为空" << um.empty() << '\n';
    // 判断 size:0
    std::cout << "判断 size:" << um.size() << '\n';
    um = {{"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}};
    // um.count('RED') 计数 1
    std::cout << "um.count('RED') 计数 " << um.count("RED") << '\n';
    // um.count('GREEN') 计数 1
    std::cout << "um.count('GREEN') 计数 " << um.count("GREEN") << '\n';
    // um.count('BLUE') 计数 1
    std::cout << "um.count('BLUE') 计数 " << um.count("BLUE") << '\n';
    auto search = um.find("RED");
    if (search != um.end())
    {
        // 查找 um.find("RED") "RED" = "#FF0000"
        std::cout << "查找 um.find(\"RED\") \"" << search->first << "\" = \"" << search->second << "\"\n";
    }
    um.erase("RED");
    if (um.count("RED") <= 0)
    {
        // um.erase("RED")后RED不存在了0
        std::cout << "um.erase(\"RED\")后RED不存在了" << um.count("RED1") << '\n';
    }
    // um.count("RED1"):0,um['RED1']的操作会使得初始化默认值,um.count("RED1"):1
    std::cout << "um.count(\"RED1\"):" << um.count("RED1") << ",um['RED1']的操作会使得初始化默认值" << um["RED1"] << ",um.count(\"RED1\"):" << um.count("RED1") << "\n";
    auto red1 = um.find("RED1");
    if (red1 != um.end())
    {
        // um.find("RED1")存在了
        std::cout << "um.find(\"RED1\")存在了" << '\n';
    }
    um.erase(red1);
    // um.erase(red1)后RED1不存在了0
    std::cout << "um.erase(red1)后RED1不存在了" << um.count("RED1") << '\n';
    // 11:0:115292150460684697
    std::cout << um.bucket("GREEN") << ":" << um.bucket_size(6) << ":" << um.max_bucket_count() << '\n';
}
void test_unordered_set()
{
    std::unordered_set<int> nums = {2, 3, 4};
    // 插入
    auto p = nums.insert(1);
    // insertelement
    // 查找
    auto search = nums.find(2);
    if (search != nums.end())
    {
        // nums.find(2) 有找到2
        std::cout << "nums.find(2) 有找到" << (*search) << '\n';
    }
    // 查找
    //  nums.count(2):1
    std::cout << "nums.count(2):" << nums.count(2) << '\n';
    // nums.erase(nums.begin())0
    // nums.erase(nums.begin())1
    // nums.erase(nums.begin())1
    // nums.erase(nums.begin())0
    // nums.erase(nums.begin())1
    // nums.erase(nums.begin())0
    // 删除具体值
    nums.erase(2);
    std::cout << "nums.erase(nums.begin())" << nums.count(2) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(3) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(4) << '\n';
    // 根据位置删除
    nums.erase(++nums.begin());
    std::cout << "nums.erase(nums.begin())" << nums.count(2) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(3) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(4) << '\n';

    std::unordered_set<int> new_num_set = {2, 3, 4};
    // 4,3,2,
    for (const auto &get : new_num_set)
    {
        std::cout << get << ",";
    }
}
void test_vector()
{

    std::vector<int> v = {7, 5, 16, 8};
    v.push_back(25);
    v[1] = 10;
    //{7,10,16,8,25,};
    // 删除最后一个{7,10,16,8,};
    v.pop_back();
    // 删除某个位置
    //{10,16,8,};
    v.erase(v.begin());
    //{10,16,8,0,0,0,0,0,0,0,};
    v.resize(10);
    //{10,16,};
    v.resize(2);
    std::cout << "{";
    for (int n : v)
    {
        std::cout << n << ",";
    }
    std::cout << "};\n";
    // 翻转数组
    reverse(v.begin(), v.end());
    std::cout << "reverse{";
    for (int n : v)
    {
        std::cout << n << ",";
    }
    std::cout << "};\n";
}

// 双端队列
void test_deque()
{
    std::deque<int> d = {7, 5, 16, 8};
    d.push_front(13);
    d.push_back(25);
    //{13,7,5,16,8,25,}
    d.pop_back();
    //{13,7,5,16,8,}
    d.pop_front();
    //{7,5,16,8,}
    for (int n : d)
    {
        std::cout << n << ",";
    }
    std::cout << '\n';

    // 擦除
    std::deque<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 0 1 2 3 4 5 6 7 8 9
    for (auto &i : c)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';

    // with []4
    std::cout << "with []" << c[4] << std::endl;
    ;

    c.erase(c.begin());
    // 1 2 3 4 5 6 7 8 9
    for (auto &i : c)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';

    c.erase(c.begin() + 2, c.begin() + 5);
    // 1 2 6 7 8 9
    for (auto &i : c)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    // 取队列头尾
    // 1 9
    std::cout << c.front() << " " << c.back() << '\n';

    // 是否为空0大小6
    std::cout << "是否为空" << c.empty() << "大小" << c.size() << '\n';
}
// 栈
void test_stack()
{
    std::stack<int> c1;
    c1.push(5);
    std::cout << c1.size() << ','; // 1
    std::cout << c1.top() << ',';  // 5
    c1.pop();
    std::cout << c1.size() << ','; // 0
    std::stack<int> c2(c1);
}
// 单向队列
void test_queue()
{
    std::queue<int> c1;
    c1.push(5);
    std::cout << c1.size() << ','; // 1
    std::queue<int> c2(c1);
    std::cout << c2.size() << ','; // 1
    std::deque<int> deq{3, 1, 4, 6, 5};
    std::queue<int> c3(deq);
    std::cout << c3.size() << ',';  // 5
    std::cout << c3.front() << ','; // 3
    std::cout << c3.back() << ',';  // 5
    std::cout << c3.empty() << ','; // 0
    // 移除头
    c3.pop();
    std::cout << c3.front() << ','; // 1
}
struct Time
{
    int h;
    int m;
    int s;
};
struct CompareTime
{
    bool operator()(Time &t1, Time &t2) // Returnstrueift1isearlierthant2
    {
        if (t1.h < t2.h)
            return true;
        if (t1.h == t2.h && t1.m < t2.m)
            return true;
        if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s)
            return true;
        return false;
    }
};
void test_priority_queue()
{
    //====================================================================================================================================
    // 整数升序
    // sort的greater是降序,priority_queue的greater是升序
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for (int n : data)
    {
        q.push(n);
    }
    // 0123456789
    // 一样的函数可以用{}初始化sort的greater是降序,priority_queue的greater是升序
    std::priority_queue<int, std::vector<int>, std::greater<int>> q1{q};
    //====================================================================================================================================
    // 整数降序
    // 9,8,7,6,5,4,3,2,1,0,sort的less是升序,priority_queue的less是降序
    std::priority_queue<int, std::vector<int>, std::less<int>> q2;
    for (int n : data)
    {
        q2.push(n);
    }
    // 9,8,7,6,5,4,3,2,1,0,
    while (!q2.empty())
    {
        std::cout << q2.top() << ",";
        q2.pop();
    }
    std::cout << '\n';
    //====================================================================================================================================
    // 绑定pair
    // 第一个小的排前面,第一个相同比较第二个
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> coll;
    std::pair<int, int> a(3, 4);
    std::pair<int, int> b(3, 5);
    std::pair<int, int> c(6, 6);
    std::pair<int, int> d(4, 5);
    std::pair<int, int> e(4, 3);
    coll.push(a);
    coll.push(b);
    coll.push(c);
    coll.push(d);
    coll.push(e);
    //(3,4)(3,5)(4,3)(4,5)(6,6)
    while (!coll.empty())
    {
        std::cout << "(" << coll.top().first << "," << coll.top().second << ")";
        coll.pop();
    }
    std::cout << '\n';
    //====================================================================================================================================
    // 通过struct和自定义struct比较的方式
    std::priority_queue<Time, std::vector<Time>, CompareTime> pq;
    Time t[4] = {{3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};
    for (int i = 0; i < 4; ++i)
    {
        pq.push(t[i]);
    }
    while (!pq.empty())
    {
        // (5,16,13)
        // (5,14,20)
        // (3,2,40)
        // (3,2,26)
        // (5,16,13)
        // (5,14,20)
        // (3,2,40)
        // (3,2,26)
        Time t2 = pq.top();
        std::cout << "(" << t2.h << "," << t2.m << "," << t2.s << ")" << std::endl;
        pq.pop();
    }
    //====================================================================================================================================
    // 自定义lambda函数方式
    auto cmp = [](const Time &t1, const Time &t2)
    {
        // true使得t1排后面?
        if (t1.h < t2.h)
        {
            return true;
        }
        else if (t1.h == t2.h && t1.m < t2.m)
        {
            return true;
        }
        else if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s)
        {
            return true;
        }
        return false;
    };
    std::priority_queue<Time, std::vector<Time>, decltype(cmp)> que4(cmp);
    for (int i = 0; i < 4; ++i)
    {
        que4.push(t[i]);
    }
    //(5,16,13)
    //(5,14,20)
    //(3,2,40)
    //(3,2,26)
    while (!que4.empty())
    {
        Time t2 = que4.top();
        std::cout << "(" << t2.h << "," << t2.m << "," << t2.s << ")" << std::endl;
        que4.pop();
    }
    std::cout << '\n';
    //====================================================================================================================================
    // 自定义比较函数pair//返回true使得第一个参数排后面
    auto cmp_pair = [](const std::pair<int, int> &t1, const std::pair<int, int> &t2)
    {
        // true使得t1排后面?
        if (t1.first > t2.first)
        {
            return true;
        }
        else if (t1.first == t2.first && t1.second > t2.second)
        {
            return true;
        }
        return false;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp_pair)> pair_pq(cmp_pair);

    std::pair<int, int> p4{4, 3};
    std::pair<int, int> p5{3, 5};
    std::pair<int, int> p1{1, 3};
    std::pair<int, int> p2{1, 5};
    std::pair<int, int> p3{2, 3};
    pair_pq.push(std::make_pair(1, 4));
    pair_pq.push(p1);
    pair_pq.push(p2);
    pair_pq.push(p3);
    pair_pq.push(p4);
    pair_pq.push(p5);
    //(1,3)
    //(1,4)
    //(1,5)
    //(2,3)
    //(3,5)
    //(4,3)
    while (!pair_pq.empty())
    {
        std::pair<int, int> t2 = pair_pq.top();
        std::cout
            << "(" << t2.first << "," << t2.second << ")" << std::endl;
        pair_pq.pop();
    }
    std::cout
        << '\n';

    struct compare
    {
        bool operator()(const std::pair<int, std::string> &t1, const std::pair<int, std::string> &t2)
        {
            // true使得t1排后面?
            if (t1.first < t2.first)
            {
                return true;
            }
            else if (t1.first == t2.first && t1.second > t2.second)
            {
                return true;
            }
            return false;
        }
    };
    std::unordered_map<std::string, std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, compare>> cus_s;

    cus_s["test"].push({10, "aaa"});
    cus_s["test"].push({10, "baaa"});
    cus_s["test"].push({10, "aaaaaa"});
    cus_s["test"].push({11, "sss"});
    cus_s["test"].push({9, "aaa"});
    while (!cus_s["test"].empty())
    {
        std::cout << cus_s["test"].top().first << ":" << cus_s["test"].top().second << std::endl;
        cus_s["test"].pop();
    }
}
// 排序函数
void tset_sort()
{
    std::vector<int> v = {7, 5, 16, 8};
    //====================================================================================================================================
    // 升序5,7,8,16,
    std::sort(v.begin(), v.end());
    //====================================================================================================================================
    // 降序16,8,7,5,sort的greater是降序,priority_queue的greater是升序
    std::sort(v.begin(), v.end(), std::greater<int>());
    // 升序5,7,8,16,sort的less是升序,priority_queue的less是降序
    std::sort(v.begin(), v.end(), std::less<int>());
    // 使用lambda函数
    //====================================================================================================================================
    //  16,8,7,5,true排前面
    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a > b; });
    // 5,7,8,16,true排前面
    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a < b; });
    //====================================================================================================================================
    // 排序pair
    // 自定义比较函数pair//返回true使得第一个参数排后面
    std::vector<std::pair<int, int>> v_pair;
    std::pair<int, int> p4{4, 3};
    std::pair<int, int> p5{3, 5};
    std::pair<int, int> p1{1, 3};
    std::pair<int, int> p2{1, 5};
    std::pair<int, int> p3{2, 3};
    v_pair.push_back(p1);
    v_pair.push_back(p2);
    v_pair.push_back(p3);
    v_pair.push_back(p4);
    v_pair.push_back(p5);
    //(4,3),(3,5),(2,3),(1,5),(1,3),
    std::sort(v_pair.begin(), v_pair.end(),
              [](const std::pair<int, int> &left, const std::pair<int, int> &right)
              {
                  // true使得left排前面
                  if (left.first > right.first)
                  {
                      return true;
                  }
                  else if (left.first == right.first && left.second > right.second)
                  {
                      return true;
                  }
                  return false;
              });
    //====================================================================================================================================
    // 排序unordered_map?
    std::vector<std::unordered_map<std::string, int>> v_map;
    std::unordered_map<std::string, int> um1 = {{"a", 1}, {"b", 1}};
    std::unordered_map<std::string, int> um2 = {{"a", 1}, {"b", 5}};
    std::unordered_map<std::string, int> um3 = {{"a", 3}, {"b", 1}};
    std::unordered_map<std::string, int> um4 = {{"a", 4}, {"b", 1}};
    std::unordered_map<std::string, int> um5 = {{"a", 5}, {"b", 1}};
    v_map.push_back(um1);
    v_map.push_back(um2);
    v_map.push_back(um3);
    v_map.push_back(um4);
    v_map.push_back(um5);
    // 大的排前面//(key:5,value:1),(key:4,value:1),(key:3,value:1),(key:1,value:5),(key:1,value:1),
    std::sort(v_map.begin(), v_map.end(),
              [](const std::unordered_map<std::string, int> &left, const std::unordered_map<std::string, int> &right)
              {
                  // 好像const 中不能直接用[]
                  auto left_a_it = left.find("a");
                  auto left_b_it = left.find("b");
                  auto right_a_it = right.find("a");
                  auto right_b_it = right.find("b");
                  int left_a = 0;
                  int left_b = 0;
                  int right_a = 0;
                  int right_b = 0;
                  if (left_a_it != left.end())
                  {
                      left_a = left_a_it->second;
                  }
                  if (left_b_it != left.end())
                  {
                      left_b = left_b_it->second;
                  }
                  if (right_a_it != right.end())
                  {
                      right_a = right_a_it->second;
                  }
                  if (right_b_it != right.end())
                  {
                      right_b = right_b_it->second;
                  }
                  ////true使得left排前面
                  if (left_a > right_a)
                  {
                      return true;
                  }
                  else if (left_a == right_a && left_b > right_b)
                  {
                      return true;
                  }
                  return false;
              });
    //(key_a:1,key_b:1),(key_a:1,key_b:5),(key_a:3,key_b:1),(key_a:4,key_b:1),(key_a:5,key_b:1),
    std::sort(v_map.begin(), v_map.end(),
              [](const std::unordered_map<std::string, int> &left, const std::unordered_map<std::string, int> &right)
              {
                  // 好像const 中不能直接用[]
                  auto left_a_it = left.find("a");
                  auto left_b_it = left.find("b");
                  auto right_a_it = right.find("a");
                  auto right_b_it = right.find("b");
                  int left_a = 0;
                  int left_b = 0;
                  int right_a = 0;
                  int right_b = 0;
                  if (left_a_it != left.end())
                  {
                      left_a = left_a_it->second;
                  }
                  if (left_b_it != left.end())
                  {
                      left_b = left_b_it->second;
                  }
                  if (right_a_it != right.end())
                  {
                      right_a = right_a_it->second;
                  }
                  if (right_b_it != right.end())
                  {
                      right_b = right_b_it->second;
                  }
                  ////true使得left排前面
                  if (left_a < right_a)
                  {
                      return true;
                  }
                  else if (left_a == right_a && left_b < right_b)
                  {
                      return true;
                  }
                  return false;
              });
    for (int i = 0; i < v_map.size(); i++)
    {
        std::cout << "(key_a:" << v_map[i]["a"] << ",key_b:" << v_map[i]["b"] << ")"
                  << ",";
    }
    std::cout << "\n";
}
class TestClass
{
private:
    // 静态数据成员，必须在外部定义和初始化，内部不能直接初始化！
    static int static_int_var;

public:
    TestClass(/* args */);
    ~TestClass();
    static void static_void_func(TestClass tc);
    int data;
};
TestClass::TestClass(/* args */) {}
TestClass::~TestClass() {}
// 必须在类外定义和初始化，用(::)来指明所属的类。
int TestClass::static_int_var = 0;
void TestClass::static_void_func(TestClass tc)
{
    // 静态成员函数
    // 类外代码可以使用类名和作用域操作符来调用静态成员函数。
    // 静态成员函数只能引用属于该类的静态数据成员或静态成员函数。
    // static_void_func static_int_var:0
    std::cout << "static_void_func static_int_var:" << static_int_var << "\n";
    static_int_var = 5;
    // static_void_func static_int_var:5
    std::cout << "static_void_func static_int_var:" << static_int_var << "\n";
    // tc static_int_var:5tc data:1
    std::cout << "tc static_int_var:" << static_int_var << "tc data:" << tc.data << "\n";
}
void test_class()
{
    TestClass tc;
    tc.data = 1;
    TestClass::static_void_func(tc);
}
void test_mod_1e97()
{
    int a = 1;
    int b = a % ((int)1e9 + 7);
    int MOD = 1000000007;
    int c = a % MOD;
    std::cout << b << ":" << c << ":" << MOD << ":" << ((int)1e9 + 7);
}
// 快速幂次方 2^3 = 8, a = 2, x = 3
long long quick_pow(long long a, long long b)
{
    static const int MOD = 1e9 + 7;
    long long ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
void test_quick_pow()
{
    // quick_pow(1,1):11
    // quick_pow(1,2):11
    // quick_pow(1,3):11
    // quick_pow(2,1):22
    // quick_pow(2,2):44
    // quick_pow(2,3):88
    // quick_pow(2,4):1616
    std::cout << "quick_pow(1,1):1" << quick_pow(1, 1) << "\n";
    std::cout << "quick_pow(1,2):1" << quick_pow(1, 2) << "\n";
    std::cout << "quick_pow(1,3):1" << quick_pow(1, 3) << "\n";
    std::cout << "quick_pow(2,1):2" << quick_pow(2, 1) << "\n";
    std::cout << "quick_pow(2,2):4" << quick_pow(2, 2) << "\n";
    std::cout << "quick_pow(2,3):8" << quick_pow(2, 3) << "\n";
    std::cout << "quick_pow(2,4):16" << quick_pow(2, 4) << "\n";
}
// 第一个不小于 i 的位置
// 二分
void test_lower_bound()
{
    struct PriceInfo
    {
        double price;
    };
    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    for (int i = 0; i < 8; ++i)
    {
        // 第一个大于等于 i 的位置
        auto lower = std::lower_bound(data.begin(), data.end(), i);
        // 0 ≤ 1 at index 0
        // 1 ≤ 1 at index 0
        // 2 ≤ 2 at index 1
        // 3 ≤ 4 at index 2
        // 4 ≤ 4 at index 2
        // 5 ≤ 5 at index 3
        // 6 ≤ 6 at index 5
        // 7 ≤ [not found]
        std::cout << i << " ≤ ";
        if (lower != data.end())
        {
            std::cout << *lower << " at index " << std::distance(data.begin(), lower);
        }
        else
        {
            std::cout << "[not found]";
        }
        std::cout << '\n';
    }
    std::vector<PriceInfo> prices = {{100.0}, {101.5}, {102.5}, {102.5}, {107.3}};
    for (double to_find : {102.5, 110.2})
    {
        auto prc_info = std::lower_bound(prices.begin(), prices.end(), to_find, [](const PriceInfo &info, double value)
                                         { return info.price < value; });
        if (prc_info != prices.end())
        {
            // 102.5 at index 2
            std::cout << prc_info->price << " at index " << prc_info - prices.begin();
        }
        else
        {
            // 110.2 not found
            std::cout << to_find << " not found";
        }
        std::cout << '\n';
    }
}

int test_two_bouns()
{
    int left = 0;
    int right = 100;
    auto check = [](int a)
    {
        return true;
    };
    while (left < right)
    {
        int mid = (left + right + 1) / 2;

        // [left, mid - 1]
        // [mid, right]
        if (check(mid))
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left * 2;
}

// 第一个大于 i
// 二分
void test_upper_bound()
{
    struct PriceInfo
    {
        double price;
    };
    const std::vector<int> data = {1, 2, 4, 5, 5, 6};
    for (int i = 0; i < 7; ++i)
    {
        // //第一个大于 i
        auto upper = std::upper_bound(data.begin(), data.end(), i);
        // 0 < 1 at index 0
        // 1 < 2 at index 1
        // 2 < 4 at index 2
        // 3 < 4 at index 2
        // 4 < 5 at index 3
        // 5 < 6 at index 5
        // 6 < not found
        std::cout << i << " < ";
        if (upper != data.end())
        {
            std::cout << *upper << " at index " << std::distance(data.begin(), upper);
        }
        else
        {
            std::cout << "not found";
        }
        std::cout << '\n';
    }
    std::vector<PriceInfo> prices = {{100.0}, {101.5}, {102.5}, {102.5}, {107.3}};
    for (double to_find : {102.5, 110.2})
    {
        auto prc_info = std::upper_bound(prices.begin(), prices.end(), to_find, [](double value, const PriceInfo &info)
                                         { return value < info.price; });
        if (prc_info != prices.end())
        {
            // 107.3 at index 4
            std::cout << prc_info->price << " at index " << prc_info - prices.begin();
        }
        else
        {
            // 110.2 not found
            std::cout << to_find << " not found";
        }
        std::cout << '\n';
    }
}
int set_bit_1(int x, int index)
{
    x |= (1 << index);
    return x;
}
int set_bit_0(int x, int index)
{
    x &= ~(1 << index);
    return x;
}

bool is_bit_1(int x, int index)
{
    return ((1 << index) & (x));
}

void test_set_bit()
{
    std::cout << "1:" << (1 << 0) << '\n';
    std::cout << "2:" << (1 << 1) << '\n';
    std::cout << "4:" << (1 << 2) << '\n';
    std::cout << "8:" << (1 << 3) << '\n';
    int x = 0;
    for (int i = 0; i < 5; i++)
    {
        x = set_bit_1(x, i);
        std::cout << "b1 i:" << i << ",x:" << x << '\n';
    }
    for (int i = 5; i > 0; i--)
    {
        x = set_bit_0(x, i);
        std::cout << "b0 i:" << i << ",x:" << x << '\n';
    }
    // for (int v = 0; v < 100; v++)
    // {
    //     for (int i = 0; i < 15; i++)
    //     {
    //         std::cout << v << ":" << i << ":" << is_bit_1(v, i) << std::endl;
    //     }
    // }

    int v = 0;
    v = set_bit_1(v, 0);
    v = set_bit_1(v, 3);
    v = set_bit_1(v, 5);
    v = set_bit_1(v, 8);
    v = set_bit_1(v, 9);
    v = set_bit_1(v, 11);

    for (int i = 0; i < 15; i++)
    {
        std::cout << v << ":" << i << ":" << is_bit_1(v, i) << std::endl;
    }
    // b1 i:0,x:1
    // b1 i:1,x:3
    // b1 i:2,x:7
    // b1 i:3,x:15
    // b1 i:4,x:31
    // b0 i:5,x:31
    // b0 i:4,x:15
    // b0 i:3,x:7
    // b0 i:2,x:3
    // b0 i:1,x:1
}
// 双向链表
void test_list()
{
    std::list<int> l = {1, 2, 3, 4, 5, 6, 7};
    l.push_front(0); // 0,1,2,3,4,5,6,7
    l.push_back(8);  // 0,1,2,3,4,5,6,7,8

    l.front(); // 0
    l.back();  // 8

    l.pop_front(); // 去掉 头
    l.front();     // 1

    l.pop_back(); // 去掉尾巴
    l.back();     // 7

    // 1,2,3,4,5,6,7,
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << ",";
    }
    std::cout << "\n";
    // 7,6,5,4,3,2,1,
    for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
    {
        std::cout << *it << ",";
    }
}

void test_segment_tree()
{
    class segmentTree
    {
    private:
        class segmentTreeNode
        {
        public:
            segmentTreeNode(int l, int r)
            {
                left = l;
                right = r;
                val = 0;
                sum = 0;
                min_val = 0;
                max_val = 0;
                left_son = nullptr;
                right_son = nullptr;
            }
            int id;
            int left;
            int right;
            long long val;
            long long sum;
            long long min_val;
            long long max_val;
            segmentTreeNode *left_son;
            segmentTreeNode *right_son;
        };

        int all_left, all_right;

        void pushup(segmentTreeNode *cur_node)
        {
            cur_node->sum = (cur_node->left_son->sum + cur_node->right_son->sum);
            cur_node->min_val = std::min(cur_node->left_son->min_val, cur_node->right_son->min_val);
            cur_node->max_val = std::max(cur_node->left_son->max_val, cur_node->right_son->max_val);
        }

        void pushdown(segmentTreeNode *cur_node, long long add)
        {
            update(cur_node->left_son, add);
            update(cur_node->right_son, add);
        }
        void modify(segmentTreeNode *cur_node, int cur_l, int cur_r, int need_L, int need_R, long long add)
        {
            //  cur_r needl  needr cur_l
            if (cur_l > need_R || cur_r < need_L)
            {
                return;
            }
            //   need_l  cur_l  cur_r  need_r
            // std::cout << (cur_node == nullptr) << ":" << cur_l << ":" << cur_r << ":" << need_L << ":" << need_R << ":" << add << std::endl;
            if (need_L <= cur_l && cur_r <= need_R)
            {
                update(cur_node, (add * (cur_r - cur_l + 1)));
            }
            // 到底了
            if (cur_l == cur_r)
            {
                return;
            }

            // pushdown(node_index, add);
            int mid = (cur_l + cur_r) >> 1;
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode(cur_l, mid);
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
            }
            modify(cur_node->left_son, cur_l, mid, need_L, need_R, add);
            modify(cur_node->right_son, mid + 1, cur_r, need_L, need_R, add);
            pushup(cur_node);
        }

        long long query_min(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
        {
            if (cur_node == nullptr)
                return LLONG_MAX;
            if (cur_l > NEED_R || cur_r < NEED_L)
                return LLONG_MAX;
            if (NEED_L <= cur_l && cur_r <= NEED_R)
                return cur_node->min_val;
            long mid = (cur_l + cur_r) >> 1;
            // pushdown(cur_node, 0);
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode(cur_l, mid);
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
            }
            return std::min(query_min(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_min(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
        }
        long long query_max(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
        {
            // std::cout << cur_l << ":" << cur_r << ":" << NEED_L << ":" << NEED_R << ":" << std::endl;
            if (cur_node == nullptr)
                return LLONG_MIN;
            if (cur_l > NEED_R || cur_r < NEED_L)
                return LLONG_MIN;
            if (NEED_L <= cur_l && cur_r <= NEED_R)
                return cur_node->max_val;
            // pushdown(cur_node, 0);
            long mid = (cur_l + cur_r) >> 1;
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode(cur_l, mid);
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
            }
            return std::max(query_max(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_max(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
        }
        long long query_sum(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
        {
            if (cur_l > NEED_R || cur_r < NEED_L)
                return 0;
            if (NEED_L <= cur_l && cur_r <= NEED_R)
                return cur_node->sum;
            // pushdown(cur_node, 0);
            long mid = (cur_l + cur_r) >> 1;
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode(cur_l, mid);
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
            }
            return query_sum(cur_node->left_son, cur_l, mid, NEED_L, NEED_R) + query_sum(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R);
        }
        // 更新某个点?
        void update(segmentTreeNode *node, long long add)
        {
            node->val += add;
            node->sum = node->val;
            node->min_val = node->val;
            node->max_val = node->val;
        }
        segmentTreeNode *root;

    public:
        segmentTree(int left, int right)
        {

            root = new segmentTreeNode(left, right);
            all_left = left;
            all_right = right;
            // build(root, all_left, all_right, _initValue);
        }

        void modify(int l, int r, long long add)
        {
            modify(root, all_left, all_right, l, r, add);
        }

        long long query_min(int l, int r)
        {
            return query_min(root, all_left, all_right, l, r);
        }
        long long query_max(int l, int r)
        {
            return query_max(root, all_left, all_right, l, r);
        }
        long long query_sum(int l, int r)
        {
            return query_sum(root, all_left, all_right, l, r);
        }
    };

    segmentTree *root = new segmentTree(0, 100001);

    // max:0, min:0, sum:0
    std::cout << "max:" << root->query_max(1, 10);
    std::cout << ", min:" << root->query_min(1, 10);
    std::cout << ", sum:" << root->query_sum(1, 10) << std::endl;
    ;
    root->modify(1, 3, 3);
    // max:3, min:0, sum:9
    std::cout << "max:" << root->query_max(1, 10);
    std::cout << ", min:" << root->query_min(1, 10);
    std::cout << ", sum:" << root->query_sum(1, 10) << std::endl;
    ;
    root->modify(3, 8, 4);
    // max:7, min:0, sum:33
    std::cout << "max:" << root->query_max(1, 10);
    std::cout << ", min:" << root->query_min(1, 10);
    std::cout << ", sum:" << root->query_sum(1, 10) << std::endl;
    ;
    root->modify(9, 9, 100);
    // max:100, min:0, sum:133
    std::cout << "max:" << root->query_max(1, 10);
    std::cout << ", min:" << root->query_min(1, 10);
    std::cout << ", sum:" << root->query_sum(1, 10) << std::endl;
    ;
}

void seg_tree()
{
    // 延迟递推,好像会超时,很慢的线段是
    class segmentTree
    {
    private:
        class segmentTreeNode
        {
        public:
            segmentTreeNode(int l, int r)
            {
                left = l;
                right = r;
                val = 0;
                temp_add = 0;
                sum = 0;
                left_son = nullptr;
                right_son = nullptr;
                push_down_flag = true;
            }
            int id;
            int left;
            int right;
            int sum = 0;
            bool push_down_flag;
            long long val;
            long long temp_add;
            segmentTreeNode *left_son;
            segmentTreeNode *right_son;
        };

        int all_left, all_right;

        void pushup(segmentTreeNode *cur_node)
        {
            cur_node->sum = (cur_node->left_son->sum + cur_node->right_son->sum);
        }

        void wait_pushdown(segmentTreeNode *cur_node, long long add)
        {
            // 到底了
            if (cur_node->left == cur_node->right)
            {
                cur_node->val = ((cur_node->val + add) % 2);
                cur_node->sum = cur_node->val;
            }
            else
            {
                cur_node->temp_add += add;
            }
        }

        // 真正递推
        void pushdown(segmentTreeNode *cur_node, long long add)
        {
            // 需要递推
            // 继续下推
            int mid = (cur_node->left + cur_node->right) >> 1;
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode(cur_node->left, mid);
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode((mid + 1), cur_node->right);
            }

            // 到底了
            if (cur_node->left == cur_node->right)
            {
                cur_node->val = ((cur_node->val + add) % 2);
                cur_node->sum = cur_node->val;
                return;
            }
            long long next_add = add + cur_node->temp_add;
            if (cur_node->push_down_flag || next_add > 0)
            {
                pushdown(cur_node->left_son, next_add);
                pushdown(cur_node->right_son, next_add);
                pushup(cur_node);
                cur_node->push_down_flag = false;
                cur_node->temp_add = 0;
            }
        }

        void modify(segmentTreeNode *cur_node, int cur_l, int cur_r, int need_L, int need_R, long long add)
        {
            cur_node->push_down_flag = true;
            //  cur_l   need_L  need_R  cur_r
            //  范围外
            if (cur_l > need_R || cur_r < need_L)
            {
                return;
            }

            // 全包含了,不往下递推
            if (need_L <= cur_l && cur_r <= need_R)
            {
                wait_pushdown(cur_node, add);
                return;
            }

            // 继续下推
            int mid = (cur_l + cur_r) >> 1;
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode(cur_l, mid);
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
            }
            modify(cur_node->left_son, cur_l, mid, need_L, need_R, add);
            modify(cur_node->right_son, mid + 1, cur_r, need_L, need_R, add);
            // pushup(cur_node);
        }

        segmentTreeNode *root;
        long long query_sum(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
        {
            pushdown(cur_node, 0);
            if (cur_l > NEED_R || cur_r < NEED_L)
                return 0;
            if (NEED_L <= cur_l && cur_r <= NEED_R)
                return cur_node->sum;
            // pushdown(cur_node, 0);
            long mid = (cur_l + cur_r) >> 1;
            return query_sum(cur_node->left_son, cur_l, mid, NEED_L, NEED_R) + query_sum(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R);
        }

    public:
        segmentTree(int left, int right)
        {

            root = new segmentTreeNode(left, right);
            all_left = left;
            all_right = right;
            // build(root, all_left, all_right, _initValue);
        }

        void modify(int l, int r, long long add)
        {
            modify(root, all_left, all_right, l, r, add);
        }

        long long query_sum(int l, int r)
        {
            return query_sum(root, all_left, all_right, l, r);
        }
        void print_tree()
        {
            std::cout << "[";
            for (int j = all_left; j <= all_right; j++)
            {
                std::cout << query_sum(j, j) << ",";
            }
            std::cout << "]" << std::endl;
            ;
        }
    };
}

void test_seg_time_out()
{
    // 使用vector存数据,好像还是会超时
    class segmentTree
    {
    private:
        void pushup(int node_id)
        {
            node_sum[node_id] = node_sum[left_right_son_id[node_id].first] + node_sum[left_right_son_id[node_id].second];
        }

        void wait_pushdown(int node_id, long long add)
        {
            // 到底了
            int left = left_right_range[node_id].first;
            int right = left_right_range[node_id].second;

            if (left == right)
            {
                node_val[node_id] = ((node_val[node_id] + add) % 2);
                node_sum[node_id] = node_val[node_id];
            }
            else
            {
                node_temp_add[node_id] += add;
            }
        }

        // 真正递推
        void pushdown(int node_id, long long add)
        {
            // 需要递推
            // 继续下推
            int cur_l = left_right_range[node_id].first;
            int cur_r = left_right_range[node_id].second;
            int mid = (cur_l + cur_r) >> 1;
            if (left_right_son_id[node_id].first == -1)
            {
                int left_son_id = create_node(cur_l, mid);
                left_right_son_id[node_id].first = left_son_id;
            }
            if (left_right_son_id[node_id].second == -1)
            {
                int right_son_id = create_node((mid + 1), cur_r);
                left_right_son_id[node_id].second = right_son_id;
            }

            // 到底了
            if (cur_l == cur_r)
            {
                node_val[node_id] = ((node_val[node_id] + add) % 2);
                node_sum[node_id] = node_val[node_id];
                return;
            }
            long long next_add = add + node_temp_add[node_id];
            if (node_push_down_flag[node_id] || next_add > 0)
            {
                pushdown(left_right_son_id[node_id].first, next_add);
                pushdown(left_right_son_id[node_id].second, next_add);
                pushup(node_id);
                node_push_down_flag[node_id] = false;
                node_temp_add[node_id] = 0;
            }
        }

        void modify(int node_id, int need_L, int need_R, long long add)
        {
            int cur_l = left_right_range[node_id].first;
            int cur_r = left_right_range[node_id].second;

            node_push_down_flag[node_id] = true;
            //  cur_l   need_L  need_R  cur_r
            //  范围外
            if (cur_l > need_R || cur_r < need_L)
            {
                return;
            }

            // 全包含了,不往下递推
            if (need_L <= cur_l && cur_r <= need_R)
            {
                wait_pushdown(node_id, add);
                return;
            }

            // 继续下推
            int mid = (cur_l + cur_r) >> 1;
            if (left_right_son_id[node_id].first == -1)
            {
                int left_son_id = create_node(cur_l, mid);
                left_right_son_id[node_id].first = left_son_id;
            }
            if (left_right_son_id[node_id].second == -1)
            {
                int right_son_id = create_node((mid + 1), cur_r);
                left_right_son_id[node_id].second = right_son_id;
            }

            modify(left_right_son_id[node_id].first, need_L, need_R, add);
            modify(left_right_son_id[node_id].second, need_L, need_R, add);
            // pushup(cur_node);
        }

        long long query_sum(int node_id, int NEED_L, int NEED_R)
        {
            pushdown(node_id, 0);
            int cur_l = left_right_range[node_id].first;
            int cur_r = left_right_range[node_id].second;
            if (cur_l > NEED_R || cur_r < NEED_L)
                return 0;
            if (NEED_L <= cur_l && cur_r <= NEED_R)
                return node_sum[node_id];
            // pushdown(cur_node, 0);
            long mid = (cur_l + cur_r) >> 1;
            return query_sum(left_right_son_id[node_id].first, NEED_L, NEED_R) + query_sum(left_right_son_id[node_id].second, NEED_L, NEED_R);
        }

    public:
        vector<pair<int, int>> left_right_range;
        vector<pair<int, int>> left_right_son_id;
        segmentTree(int left, int right)
        {
            create_node(left, right);
        }

        // 额外的数据
        vector<bool> node_push_down_flag;
        vector<long long> node_val;
        vector<long long> node_sum;
        vector<long long> node_temp_add;

        // 创建一个新的点信息
        int create_node(int left, int right)
        {
            left_right_range.push_back({left, right});
            left_right_son_id.push_back({-1, -1});
            node_push_down_flag.push_back(false);
            node_val.push_back(0);
            node_sum.push_back(0);
            node_temp_add.push_back(0);
            return left_right_range.size() - 1;
        }

        void modify(int l, int r, long long add)
        {
            modify(0, l, r, add);
        }

        long long query_sum(int l, int r)
        {
            return query_sum(0, l, r);
        }
    };
}

vector<int> get_pre_sum(vector<int> &nums)
{
    vector<int> result;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        result.push_back(sum);
    }
    return result;
}

double get_sum(vector<int> &pre_sum, int i, int j)
{
    int a = i > 0 ? pre_sum[i - 1] : 0;
    int b = j < pre_sum.size() ? pre_sum[j] : pre_sum[pre_sum.size() - 1];
    return b - a;
}

// 字符串滚动哈希
void loop_hash(string s)
{
    int p_131 = 131;
    vector<unsigned long long> f(1001);
    vector<unsigned long long> p(1001);
    p[0] = 1;
    f[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < s.size(); i++)
    {
        f[i] = f[i - 1] * p_131 + (s[i] - 'a' + 1);
        p[i] = p[i - 1] * 131;
    }

    // 计算某部分的哈希
    // unsigned long long get_h(vector<unsigned long long> f, vector<unsigned long long> p, int left, int right)
    // {
    //     if (left == 0)
    //     {
    //         return f[right];
    //     }
    //     return f[right] - f[left - 1] * p[right - left + 1];
    // }
}

// 弗洛伊德 松弛k遍, x 到 y 的最短路
int test_floyd(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> vvi(n, vector<int>(n, 99999));
    // vvi[x][y] = 最小 ?
    for (int i = 0; i < n; i++)
    {
        vvi[i][i] = 0;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int v = edges[i][2];
        vvi[a][b] = v;
        vvi[b][a] = v;
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int i_k_j = vvi[i][k] + vvi[k][j];
                vvi[i][j] = min(vvi[i][j], i_k_j);
                vvi[j][i] = min(vvi[j][i], i_k_j);
            }
        }
    }
    // 输出 x 到 y 最短路
    // return vvi[x][y];
    return vvi[0][0];
}

// dijkstra单点最短路模板 带 优先级队列
void djik(vector<vector<int>> &vvi, vector<int> &d, int start)
{
    // 自定义比较函数pair//返回true使得第一个参数排后面
    auto cmp_pair = [](const std::pair<int, int> &t1, const std::pair<int, int> &t2)
    {
        // true使得t1排后面?
        if (t1.first > t2.first)
        {
            return true;
        }
        else if (t1.first == t2.first && t1.second < t2.second)
        {
            return true;
        }
        return false;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp_pair)> pair_pq(cmp_pair);
    d[start] = 0;
    pair_pq.push({d[start], start});
    while (!pair_pq.empty())
    {
        pair<int, int> cur = pair_pq.top();
        pair_pq.pop();
        int cur_len = cur.first;
        int cur_node = cur.second;

        // 可以继续走
        for (int i_node = 0; i_node < vvi.size(); i_node++)
        {
            if (i_node != cur_node)
            {
                int cur_to_i = vvi[cur_node][i_node];
                if (d[i_node] > (cur_len + cur_to_i))
                {
                    d[i_node] = (cur_len + cur_to_i);
                    // 这里可以进
                    pair_pq.push({d[i_node], i_node});
                }
            }
        }
    }
}

int test_dijkstra(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> vvi(n, vector<int>(n, 99999));
    // vvi[x][y] = 最小 ?
    for (int i = 0; i < n; i++)
    {
        vvi[i][i] = 0;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int v = edges[i][2];
        vvi[a][b] = v;
        vvi[b][a] = v;
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> i_to_x(n, 99999);
        djik(vvi, i_to_x, i);
        for (int j = 0; j < n; j++)
        {
            std::cout << "输出i 到 j 的最短路" << i_to_x[j];
        }
    }
}

void bellman_ford(vector<vector<pair<int, int>>> &vvpii, vector<int> &d, int node_num, int start)
{

    // 初始化start的距离
    for (pair<int, int> pp : vvpii[start])
    {
        d[pp.first] = pp.second;
    }

    // node_num - 1 次松弛
    for (int i = 0; i < node_num - 1; i++)
    {
        // 松弛所有的边
        for (int x = 0; x < vvpii.size(); x++)
        {
            for (int x_len = 0; x_len < vvpii[x].size(); x_len++)
            {
                pair<int, int> pii = vvpii[x][x_len];
                int y = pii.first;
                int value = pii.second;
                if (d[y] > d[x] + value)
                {
                    d[y] = d[x] + value;
                }
            }
        }
    }

    // 如果松弛了n - 1次后还能松弛,说明有负环
    // 松弛所有的边
    for (int x = 0; x < vvpii.size(); x++)
    {
        for (int x_len = 0; x_len < vvpii[x].size(); x_len++)
        {
            pair<int, int> pii = vvpii[x][x_len];
            int y = pii.first;
            int value = pii.second;
            if (d[y] > d[x] + value)
            {
                d[y] = d[x] + value;
                // 有负环
            }
        }
    }
}

// 测试贝尔弗曼
int test_bellman_ford(int n, vector<vector<int>> &edges, int distanceThreshold)
{

    // 如果用unordered_map<int, unordered_map<int, int>> uiuii; 的结构会超时
    vector<vector<pair<int, int>>> vvpii(n, vector<pair<int, int>>(0));

    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int value = edges[i][2];
        vvpii[x].push_back({y, value});
        vvpii[y].push_back({x, value});
    }

    int max_count = 99999;
    int id = -1;
    for (int i = 0; i < n; i++)
    {
        vector<int> len(n, 99999);
        bellman_ford(vvpii, len, n, i);
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && len[j] <= distanceThreshold)
            {
                count++;
            }
        }
        if ((count < max_count) || (count == max_count && i > id))
        {
            max_count = count;
            id = i;
        }
    }
    return id;
}

// 带优先级队列的spfa 最短路
void spfa_bellman_pri_que(vector<vector<pair<int, int>>> &vvpii, vector<int> &d, int start)
{
    auto cmp_pair = [](const std::pair<int, int> &t1, const std::pair<int, int> &t2)
    {
        // true使得t1排后面?
        if (t1.first > t2.first)
        {
            return true;
        }
        else if (t1.first == t2.first && t1.second > t2.second)
        {
            return true;
        }
        return false;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp_pair)> pair_pq(cmp_pair);
    // 初始化start的距离
    for (pair<int, int> pp : vvpii[start])
    {
        d[pp.first] = pp.second;
        pair_pq.push({pp.second, pp.first});
    }
    while (!pair_pq.empty())
    {
        pair<int, int> top = pair_pq.top();
        pair_pq.pop();
        int len = top.first;
        int y_nodex = top.second;
        // 出来已经有更短的了,说明这个没优势
        if (len <= d[y_nodex])
        {
            for (pair<int, int> pp : vvpii[y_nodex])
            {
                if (d[pp.first] > len + pp.second)
                {
                    d[pp.first] = len + pp.second;
                    pair_pq.push({d[pp.first], pp.first});
                }
            }
        }
    }
}
// 带优先级队列的spfa 最短路
int test_spfa_bellman_pri_que(int n, vector<vector<int>> &edges, int distanceThreshold)
{

    vector<vector<pair<int, int>>> vvpii(n, vector<pair<int, int>>(0));

    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int value = edges[i][2];
        vvpii[x].push_back({y, value});
        vvpii[y].push_back({x, value});
    }

    int max_count = 99999;
    int id = -1;
    for (int i = 0; i < n; i++)
    {
        vector<int> len(n, 99999);
        spfa_bellman_pri_que(vvpii, len, i);
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && len[j] <= distanceThreshold)
            {
                count++;
                // std::cout << "(" << i << "to" << j << "=" << count << ")";
            }
        }
        if ((count < max_count) || (count == max_count && i > id))
        {
            max_count = count;
            id = i;
        }
    }
    return id;
}

// 开方
long long mysqrt(long long a)
{
    long long min = 0;
    // long long max=1<<32;
    long long max = ((long long)1) << 32; // chux' bugfix
    while (1)
    {
        if (max <= 1 + min)
            return min;

        long long sqt = min + (max - min) / 2;
        long long sq = sqt * sqt;

        if (sq == a)
            return sqt;

        if (sq > a)
            max = sqt;
        else
            min = sqt;
    };
}

int mykmp(string &text, string &pattern)
{
    // 计算前
    int size = pattern.size();
    int *pie = new int[size];
    pie[0] = 0;
    int k = 0;
    for (int i = 1; i < size; i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = pie[k - 1];
        }
        if (pattern[k] == pattern[i])
        {
            k = k + 1;
        }
        pie[i] = k;
    }
    // 开始查找

    int matched_pos = 0;
    for (int current = 0; current < text.length(); current++)
    {
        while (matched_pos > 0 && pattern[matched_pos] != text[current])
            matched_pos = pie[matched_pos - 1];

        if (pattern[matched_pos] == text[current])
            matched_pos = matched_pos + 1;

        if (matched_pos == (pattern.length()))
        {
            matched_pos = pie[matched_pos - 1];
            return current - (pattern.length() - 1);
        }
    }
    return -1;
}

// 字典树
class MyTrie
{
private:
    /* data */
    vector<MyTrie *> t;
    char start;
    int cur_flag;

public:
    MyTrie(int n, char s)
    {
        t.resize(n);   // 初始化字典树存放长度
        start = s;     // 第一个字符, 例如 '0', 'a'
        cur_flag = -1; // 到这边是否是结尾
    }

    void insert(string &temp, int cur, int flag)
    {
        int cur_index = temp[cur] - start;
        if (t[cur_index] == nullptr)
        {
            t[cur_index] = new MyTrie(t.size(), start);
        }
        if (cur < temp.size() - 1)
        {
            t[cur_index]->insert(temp, cur + 1, flag);
        }
        else
        {
            // 到头了
            if (t[cur_index]->cur_flag == -1)
            {
                t[cur_index]->cur_flag = flag;
            }
        }
    }

    int get(string &temp, int cur)
    {
        int cur_index = temp[cur] - start;
        if (t[cur_index] == nullptr)
        {
            return -1;
        }
        if (cur < temp.size() - 1)
        {
            return t[cur_index]->get(temp, cur + 1);
        }
        else
        {
            // 到头了
            return t[cur_index]->cur_flag;
        }
    }
};

// 并查集
class unionFind
{
public:
    vector<int> v_father;
    unionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            v_father.push_back(i);
        }
    }
    int get(int i)
    {
        if (v_father[i] == i)
        {
            return i;
        }
        v_father[i] = get(v_father[i]);
        return v_father[i];
    }
    void set(int a, int b)
    {
        int fa = get(a);
        int fb = get(b);
        if (fa > fb)
        {
            v_father[fa] = fb;
        }
        else if (fb > fa)
        {
            v_father[fb] = fa;
        }
    }
};

// 质素筛选 埃筛 O(nloglogn)
int Eratosthenes(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<int> prime;
    if (n < 2)
    {
        return 0;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            if ((long long)i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    is_prime[j] = false; // 是i的倍数的均不是素数    因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i 的倍数开始，提高了运行速度
                }
            }
        }
    }
    return prime.size();
}

// 质素筛选 欧拉筛, 线筛  O(n)
int ola(int n)
{
    vector<int> vis(n + 1);
    vector<int> prime;
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size(); ++j)
        {
            if (1ll * i * prime[j] > n)
                break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                // i % pri[j] == 0
                // 换言之，i 之前被 pri[j] 筛过了
                // 由于 pri 里面质数是从小到大的，所以 i乘上其他的质数的结果一定会被
                // pri[j]的倍数筛掉，就不需要在这里先筛一次，所以这里直接 break
                // 掉就好了
                break;
            }
        }
    }
    return prime.size();
}

// 分解质因数
unordered_map<int, int> get_primes_list(int n)
{
    unordered_map<int, int> result;
    int num = n;
    while (num > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            while (num > 1 && num % i == 0)
            {
                result[i]++;
                num /= i;
            }
        }
    }
    return result;
}

// 更快速的分解质因数
unordered_set<int> get_primes_list_fast(int x)
{
    unordered_set<int> result;
    for (int d = 2; d * d <= x; ++d)
    { // 分解质因数
        if (x % d == 0)
        {
            result.insert(d);
            for (x /= d; x % d == 0; x /= d)
                ;
        }
    }
    if (x > 1)
    {
        result.insert(x);
    }
    return result;
}

int_fast8_t main(int argc, char const *argv[])
{
    // test_pair();
    // test_tuple();
    // test_string();
    // test_array();
    // test_unordered_map();
    // test_unordered_set();
    // test_vector();
    // test_deque();
    // test_stack();
    // test_queue();
    // test_priority_queue();
    // tset_sort();
    // test_class();
    // test_mod_1e97();
    // test_quick_pow();
    // test_lower_bound();
    // test_upper_bound();
    // test_set_bit();
    // test_list();
    test_segment_tree();
    return 0;
}

// g++ -std=c++11 quick_start.cpp