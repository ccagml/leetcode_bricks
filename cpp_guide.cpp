#include <algorithm>
#include <array>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
void test_pair()
{
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
    std::pair<int, int> p1 = std::make_pair(n, a[1]);
    std::pair<int, int> p2{1, 3};
    // (1,2)
    // std::cout << "(" << p1.first << "," << p1.second << ")\n";
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
    // std::cout << str2 << '\n';
    //查找find
    std::string::size_type pos1 = str2.find("o"); // pos1 = 4
    // std::cout << pos1 << '\n';
    std::string::size_type pos2 = str2.find("w"); // pos2 = 6
    // std::cout << pos2 << '\n';
    std::string::size_type pos3 = str2.find("rl"); // pos3 = 8
    // std::cout << pos3 << '\n';
    //裁剪substr
    std::string str3 = "helloworld";
    std::string str4 = str3.substr(0, 5); // hello
    std::string str5 = str3.substr(6);    // world
    std::string str6 = str3.substr(1, 3); // ell
    //插入某个位置insert
    std::string s = "hello";
    // insert(size_typeindex,size_typecount,charch)
    s.insert(0, 1, 'a'); // ahello
    // insert(size_typeindex,const char*s)
    s.insert(2, "bbb"); // ahbbbello
    //尾部插入
    // push_back尾部插入一个字符char
    s.push_back('c'); // ahbbbelloc
    // append尾部插入字符串
    s.append("ddd"); // ahbbbellocddd
    // append插入多次
    s.append(3, 'f'); // ahbbbellocdddfff
    // append插入一部分
    s.append("hello", 3, 3); // ahbbbellocdddffflo
    s.append("hello", 1, 2); // ahbbbellocdddfffloel
    //替换
    std::string str{"Thequickbrownfoxjumpsoverthelazydog."};
    // 从第10位开始的后5位替换成 red
    str.replace(10, 5, "red"); // Thequickbrredxjumpsoverthelazydog.
    // 前3位替换成 A
    str.replace(str.begin(), str.begin() + 3, 1, 'A'); // Aquickbrredxjumpsoverthelazydog.
    //重置长度
    std::string new_resize_str = "helloworld";
    new_resize_str.resize(5); // hello
    //交换
    std::string a = "AAA";
    std::string b = "BBB";
    a.swap(b); // a=BBB  b=AAA
    //字符串转数字
    std::string str_int = "123456";
    std::string str_long = "123456789987";
    std::string str_longlong = "123456789987654321";
    int int_str = std::stoi(str_int);                   // 123456
    long long_str = std::stol(str_long);                // 123456789987
    long long long_long_str = std::stoll(str_longlong); // 123456789987654321
    //数字转字符串
    double f = 23.43;
    double f1 = 123456;
    std::string f_str = std::to_string(f);   // 23.430000
    std::string f_str1 = std::to_string(f1); // 123456.000000
    int i2 = 123456789;
    std::string i_str1 = std::to_string(i2); // 123456789

    std::cout << "a"
              << " -> std::toupper -> " << char(std::toupper('a')) << std::endl;
    std::cout << "A"
              << " -> std::tolower -> " << char(std::tolower('A')) << std::endl;
}
void test_array()
{
    std::array<int, 3> a1{{1, 2, 3}};
    a1 = {3, 2, 1}; // 3,2,1
    // std::cout << a1[0] << "," << a1[1] << "," << a1[2] << '\n';
    std::sort(a1.begin(), a1.end()); // 1,2,3
    //交换
    std::swap(a1[0], a1[1]); // 2,1,3
}
void test_unordered_map()
{
    // Createanunordered_mapofthreestrings(thatmaptostrings)
    std::unordered_map<std::string, std::string> um = {{"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}};
    //遍历
    std::cout << "遍历方式1 = {\n";
    for (const std::pair<std::string, std::string> &n : um)
    {
        std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
    }
    std::cout << "}\n";
    std::cout << "遍历方式2 = {\n";
    //遍历
    for (const auto &n : um)
    {
        std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
    }
    std::cout << "}\n";
    std::cout << "遍历方式3 = {\n";
    //遍历
    for (auto n : um)
    {
        std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
    }
    std::cout << "}\n";
    std::cout << "遍历方式4 = {\n";
    //指针遍历
    for (auto iter = um.begin(); iter != um.end(); ++iter)
    {
        std::cout << "\"" << iter->first << "\" = \"" << iter->second << "\"\n";
    }
    std::cout << "}\n";
    //设置
    um["BLACK"] = "#000000";
    std::cout << "设置值 \"BLACK\" = \"" << um["BLACK"] << "\"\n";
    //判断空
    std::cout << "判断空 um.empty() 是否为空" << um.empty() << '\n';
    std::cout << "判断 size:" << um.size() << '\n';
    //清空
    um.clear();
    std::cout << "清空 um.clear() 后是否为空" << um.empty() << '\n';
    std::cout << "判断 size:" << um.size() << '\n';
    um = {{"RED", "#FF0000"}, {"GREEN", "#00FF00"}, {"BLUE", "#0000FF"}};
    // um.count('RED'):1
    std::cout << "um.count('RED') 计数 " << um.count("RED") << '\n';
    // um.count('GREEN'):1
    std::cout << "um.count('GREEN') 计数 " << um.count("GREEN") << '\n';
    // um.count('BLUE'):1
    std::cout << "um.count('BLUE') 计数 " << um.count("BLUE") << '\n';
    auto search = um.find("RED");
    if (search != um.end())
    {
        std::cout << "查找 um.find(\"RED\") \"" << search->first << "\" = \"" << search->second << "\"\n";
    }
    um.erase("RED");
    if (um.count("RED") <= 0)
    {
        std::cout << "um.erase(\"RED\")后RED不存在了" << um.count("RED1") << '\n';
    }
    std::cout << "um.count(\"RED1\"):" << um.count("RED1") << ",um['RED1']的操作会使得初始化默认值" << um["RED1"] << ",um.count(\"RED1\"):" << um.count("RED1") << "\n";
    auto red1 = um.find("RED1");
    if (red1 != um.end())
    {
        std::cout << "um.find(\"RED1\")存在了" << '\n';
    }
    um.erase(red1);
    std::cout << "um.erase(red1)后RED1不存在了" << um.count("RED1") << '\n';
    // 6:1:576460752303423487
    std::cout << um.bucket("GREEN") << ":" << um.bucket_size(6) << ":" << um.max_bucket_count() << '\n';
}
void test_unordered_set()
{
    std::unordered_set<int> nums = {2, 3, 4};
    //插入
    auto p = nums.insert(1);
    // insertelement
    //查找
    auto search = nums.find(2);
    if (search != nums.end())
    {
        std::cout << "nums.find(2) 有找到" << (*search) << '\n';
    }
    //查找
    std::cout << "nums.count(2):" << nums.count(2) << '\n';
    // nums.erase(nums.begin())0
    // nums.erase(nums.begin())1
    // nums.erase(nums.begin())1
    // nums.erase(nums.begin())0
    // nums.erase(nums.begin())1
    // nums.erase(nums.begin())0
    //删除具体值
    nums.erase(2);
    std::cout << "nums.erase(nums.begin())" << nums.count(2) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(3) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(4) << '\n';
    //根据位置删除
    nums.erase(++nums.begin());
    std::cout << "nums.erase(nums.begin())" << nums.count(2) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(3) << '\n';
    std::cout << "nums.erase(nums.begin())" << nums.count(4) << '\n';
}
void test_vector()
{
    // Createavectorcontainingintegers
    std::vector<int> v = {7, 5, 16, 8};
    // Addtwomoreintegerstovector
    v.push_back(25);
    v[1] = 10;
    //{7,10,16,8,25,};
    //删除最后一个{7,10,16,8,};
    v.pop_back();
    //删除某个位置
    //{10,16,8,};
    v.erase(v.begin());
    //{10,16,8,0,0,0,0,0,0,0,};
    v.resize(10);
    //{10,16,};
    v.resize(2);
    // std::cout << "{";
    // for (int n : v)
    // {
    //     std::cout << n << ",";
    // }
    // std::cout << "};\n";
}
void test_deque()
{
    // Createadequecontainingintegers
    std::deque<int> d = {7, 5, 16, 8};
    d.push_front(13);
    d.push_back(25);
    //{13,7,5,16,8,25,}
    d.pop_back();
    //{13,7,5,16,8,}
    d.pop_front();
    //{7,5,16,8,}
    // std::cout << "{";
    // for (int n : d)
    // {
    //     std::cout << n << ",";
    // }
    // std::cout << "}" << '\n';
}
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
    //移除头
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
    //整数升序
    // sort的greater是降序,priority_queue的greater是升序
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for (int n : data)
    {
        q.push(n);
    }
    // 0123456789
    //一样的函数可以用{}初始化sort的greater是降序,priority_queue的greater是升序
    std::priority_queue<int, std::vector<int>, std::greater<int>> q1{q};
    //====================================================================================================================================
    //整数降序
    // 9,8,7,6,5,4,3,2,1,0,sort的less是升序,priority_queue的less是降序
    std::priority_queue<int, std::vector<int>, std::less<int>> q2;
    for (int n : data)
    {
        q2.push(n);
    }
    // 9,8,7,6,5,4,3,2,1,0,
    // while(!q2.empty())
    //{
    // std::cout<<q2.top()<<",";
    // q2.pop();
    //}
    // std::cout<<'\n';
    //====================================================================================================================================
    //绑定pair
    //第一个小的排前面,第一个相同比较第二个
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
    // while(!coll.empty())
    //{
    // std::cout<<"("<<coll.top().first<<","<<coll.top().second<<")";
    // coll.pop();
    //}
    // std::cout<<'\n';
    //====================================================================================================================================
    //通过struct和自定义struct比较的方式
    std::priority_queue<Time, std::vector<Time>, CompareTime> pq;
    Time t[4] = {{3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};
    for (int i = 0; i < 4; ++i)
    {
        pq.push(t[i]);
    }
    // while(!pq.empty())
    //{
    // Timet2=pq.top();
    // std::cout<<t2.h<<","<<t2.m<<","<<t2.s<<std::endl;
    // pq.pop();
    //}
    //====================================================================================================================================
    //自定义lambda函数方式
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
    // while(!que4.empty())
    //{
    // Timet2=que4.top();
    // std::cout
    //<<"("<<t2.h<<","<<t2.m<<","<<t2.s<<")"<<std::endl;
    // que4.pop();
    //}
    // std::cout<<'\n';
    //====================================================================================================================================
    //自定义比较函数pair//返回true使得第一个参数排后面
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
    // while(!pair_pq.empty())
    //{
    // std::pair<int,int>t2=pair_pq.top();
    // std::cout
    //<<"("<<t2.first<<","<<t2.second<<")"<<std::endl;
    // pair_pq.pop();
    //}
    // std::cout<<'\n';

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
    std::unordered_map<std::string, std::priority_queue<std::pair<int,std::string>, std::vector<std::pair<int, std::string>>, compare>> cus_s;

    cus_s["test"].push({10, "aaa"});
    cus_s["test"].push({10, "baaa"});
    cus_s["test"].push({10, "aaaaaa"});
    cus_s["test"].push({11, "sss"});
    cus_s["test"].push({9, "aaa"});
    while(!cus_s["test"].empty()){
        std::cout << cus_s["test"].top().first << ":" << cus_s["test"].top().second << std::endl;
        cus_s["test"].pop();
    }
}
//排序函数
void tset_sort()
{
    std::vector<int> v = {7, 5, 16, 8};
    //====================================================================================================================================
    //升序5,7,8,16,
    std::sort(v.begin(), v.end());
    //====================================================================================================================================
    //降序16,8,7,5,sort的greater是降序,priority_queue的greater是升序
    std::sort(v.begin(), v.end(), std::greater<int>());
    //升序5,7,8,16,sort的less是升序,priority_queue的less是降序
    std::sort(v.begin(), v.end(), std::less<int>());
    //使用lambda函数
    //====================================================================================================================================
    // 16,8,7,5,true排前面
    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a > b; });
    // 5,7,8,16,true排前面
    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a < b; });
    //====================================================================================================================================
    //排序pair
    //自定义比较函数pair//返回true使得第一个参数排后面
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
    //排序unordered_map?
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
    //大的排前面//(key:5,value:1),(key:4,value:1),(key:3,value:1),(key:1,value:5),(key:1,value:1),
    std::sort(v_map.begin(), v_map.end(),
              [](const std::unordered_map<std::string, int> &left, const std::unordered_map<std::string, int> &right)
              {
                  //好像const 中不能直接用[]
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
                  //好像const 中不能直接用[]
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
    //静态数据成员，必须在外部定义和初始化，内部不能直接初始化！
    static int static_int_var;

public:
    TestClass(/* args */);
    ~TestClass();
    static void static_void_func(TestClass tc);
    int data;
};
TestClass::TestClass(/* args */) {}
TestClass::~TestClass() {}
//必须在类外定义和初始化，用(::)来指明所属的类。
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
    int MOD = 100000007;
    int c = a % MOD;
    std::cout << b << ":" << c;
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
    std::cout << "quick_pow(1,1):1" << quick_pow(1, 1) << "\n";
    std::cout << "quick_pow(1,2):1" << quick_pow(1, 2) << "\n";
    std::cout << "quick_pow(1,3):1" << quick_pow(1, 3) << "\n";
    std::cout << "quick_pow(2,1):2" << quick_pow(2, 1) << "\n";
    std::cout << "quick_pow(2,2):4" << quick_pow(2, 2) << "\n";
    std::cout << "quick_pow(2,3):8" << quick_pow(2, 3) << "\n";
    std::cout << "quick_pow(2,4):16" << quick_pow(2, 4) << "\n";
}
// 第一个不小于 i 的位置
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
            std::cout << prc_info->price << " at index " << prc_info - prices.begin();
        }
        else
        {
            std::cout << to_find << " not found";
        }
        std::cout << '\n';
    }
}
//第一个大于 i
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
            std::cout << prc_info->price << " at index " << prc_info - prices.begin();
        }
        else
        {
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
    // std::cout << "1:" << (1 << 0) << '\n';
    // std::cout << "2:" << (1 << 1) << '\n';
    // std::cout << "4:" << (1 << 2) << '\n';
    // std::cout << "8:" << (1 << 3) << '\n';
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
    for (int v = 0; v < 100; v++)
    {
        for (int i = 0; i < 15; i++)
        {
            std::cout << v << ":" << i << ":" << is_bit_1(v, i) << std::endl;
        }
    }

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
int main(int argc, char const *argv[])
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
    test_priority_queue();
    // tset_sort();
    // test_class();
    // test_mod_1e97();
    // test_quick_pow();
    // test_lower_bound();
    // test_upper_bound();
    // test_set_bit();
    return 0;
}

// g++ -std=c++11 cpp_guide.cpp