#include <bits/stdc++.h>
using namespace std;

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

long long FIRSTTRUE(function<bool(long long)> f, long long lb, long long rb)
{
    while (lb < rb)
    {
        long long mb = (lb + rb) / 2;
        f(mb) ? rb = mb : lb = mb + 1;
    }
    return lb;
}
long long LASTTRUE(function<bool(long long)> f, long long lb, long long rb)
{
    while (lb < rb)
    {
        long long mb = (lb + rb + 1) / 2;
        f(mb) ? lb = mb : rb = mb - 1;
    }
    return lb;
}

template <class A>
void read(vector<A> &v);
template <class A, size_t S>
void read(array<A, S> &a);
template <class T>
void read(T &x)
{
    cin >> x;
}
void read(double &d)
{
    string t;
    read(t);
    d = stod(t);
}
void read(long double &d)
{
    string t;
    read(t);
    d = stold(t);
}
template <class H, class... T>
void read(H &h, T &...t)
{
    read(h);
    read(t...);
}
template <class A>
void read(vector<A> &x)
{
    EACH(a, x)
    read(a);
}
template <class A, size_t S>
void read(array<A, S> &x)
{
    EACH(a, x)
    read(a);
}

string to_string(char c)
{
    return string(1, c);
}
string to_string(bool b)
{
    return b ? "true" : "false";
}
string to_string(const char *s)
{
    return string(s);
}
string to_string(string s)
{
    return s;
}
string to_string(vector<bool> v)
{
    string res;
    int v_size = v.size();
    FOR(v_size)
    res += char('0' + v[i]);
    return res;
}

template <size_t S>
string to_string(bitset<S> b)
{
    string res;
    FOR(S)
    res += char('0' + b[i]);
    return res;
}
template <class T>
string to_string(T v)
{
    bool f = 1;
    string res;
    EACH(x, v)
    {
        if (!f)
            res += ' ';
        f = 0;
        res += to_string(x);
    }
    return res;
}

template <class A>
void write(A x)
{
    cout << to_string(x);
}
template <class H, class... T>
void write(const H &h, const T &...t)
{
    write(h);
    write(t...);
}
void print()
{
    write("\n");
}
template <class H, class... T>
void print(const H &h, const T &...t)
{
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

void DBG()
{
    cerr << "]" << endl;
}
template <class H, class... T>
void DBG(H h, T... t)
{
    cerr << to_string(h);
    if (sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template <class T>
void offset(long long o, T &x)
{
    x += o;
}
template <class T>
void offset(long long o, vector<T> &x)
{
    EACH(a, x)
    offset(o, a);
}
template <class T, size_t S>
void offset(long long o, array<T, S> &x)
{
    EACH(a, x)
    offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b)
{
    return uniform_int_distribution<long long>(a, b)(mt_rng);
}

template <class T, class U>
void vectori(vector<T> &v, U x, size_t n)
{
    v = vector<T>(n, x);
}
template <class T, class U>
void vectori(vector<T> &v, U x, size_t n, size_t m...)
{
    v = vector<T>(n);
    EACH(a, v)
    vectori(a, x, m);
}

void solve(int k, int l, int m, int n, int d)
{
    int result = 0;
    for (int i = 1; i <= d; i++)
    {
        if (i % k == 0)
        {
            result++;
        }
        else if (i % l == 0)
        {
            result++;
        }
        else if (i % m == 0)
        {
            result++;
        }
        else if (i % n == 0)
        {
            result++;
        }
    }
    write(result);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c;
    unordered_set<char> usc;
    while (true)
    {
        read(c);
        if (c == '}')
        {
            break;
        }
        else if (c >= 'a' && c <= 'z')
        {
            usc.insert(c);
        }
    }
    int result = usc.size();
    write(result);
    return 0;
}

// g++ --std=c++17 codeforces_443_A.cpp