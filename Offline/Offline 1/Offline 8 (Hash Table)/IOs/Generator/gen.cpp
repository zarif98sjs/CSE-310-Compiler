
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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

const int nmax = 2e5+7;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int mx = 1e4;

int32_t main(int argc, char* argv[])
{
    optimizeIO();

    srand(atoi(argv[1])); /// atoi(s) converts an array of chars to int

    vector<char>v;
    for(char ch='a';ch<='z';ch++) v.push_back(ch);
    for(char ch='A';ch<='Z';ch++) v.push_back(ch);

    random_shuffle(ALL(v));

//    DBG(v);
//    DBG(v.size());

//    int n = atoi(argv[2]);

    int n = mx;
    int tot_op = n + n/10;
    cout<<tot_op<<endl;

    vector<string>all_strings;
    set<string>st;

    for(int i=0;i<n;)
    {
        string t = "";
        for(int j=0;j<7;j++) t = t + v[rand(1,mx)%52];
        cout<<"I "<<t<<endl;

        if(st.count(t)==0)
        {
            all_strings.push_back(t);
            st.insert(t);

            i++;
        }
    }

    int search_cnt = n/10;

    for(int i=0;i<search_cnt;i++)
    {
        cout<<"F "<<all_strings[rand(1,4*n)%n]<<endl;
    }

    return 0;
}

/**

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
