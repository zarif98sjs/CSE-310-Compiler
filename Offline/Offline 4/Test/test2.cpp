
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("in.txt", "r", stdin)
#define WRITE       freopen("out.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/**

R : add  , sub  , and  , or  , sll , srl , nor
I : addi , subi , andi , ori , sw  , lw  , beq ,  bneq
J : j

**/

string lower(string s)
{
    string ret;

    for(auto c:s) ret += tolower(c);

    return ret;
}

string remove_whitespace(string str)
{
    string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
    return str;
}

vector<string> tokenize(string const str,char delim)
{
    vector<string> ret;

    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        ret.push_back(str.substr(start, end - start));
    }

    return ret;
}

string dec_to_hex(string d_s)
{
    int decimal_value = stoi(d_s);

    stringstream ss;
    ss<< hex << decimal_value;
    string res ( ss.str() );

    return res;
}

int32_t main()
{
    optimizeIO();

    auto v1 = tokenize("asd[2]",'[');
    cout<<v1<<endl;
    auto v2 = tokenize("asda",'[');
    cout<<v2<<endl;

    return 0;
}

/**


Corner cases:
- label declared later
- jump to actual address ?


x:
add ....

x:add ..
add ..



**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


