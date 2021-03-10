
/*
 *
 * Hash Table : Separate Chaining Method
 *
 * - Md. Zarif Ul Alam
 * Staring at : 16 November 2020 6:10pm
 *
 * */


/* Which of the favors of your Lord will you deny ? */

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

struct Node
{
    string key;
    int val;
    Node* nxt;

    Node(){}

    Node(string key,int val)
    {
        this->key = key;
        this->val = val;
        this->nxt = NULL;
    }

    Node(string key,int val,Node* nxt)
    {
        this->key = key;
        this->val = val;
        this->nxt = nxt;
    }
};

struct HashTable_SeparateChaining
{
    int N; /* initial number of assumed data */
    int M; /* initial hast table size */

    int collisionCnt = 0 , probecnt = 0;

    vector<Node*>ht;

    function<int(string)> hashValue;

    template<typename T>
    HashTable_SeparateChaining(T func)
    {
        N = 10000;
//        M = 1009; /*prime*/
        M = 10007; /*prime*/
//        M = 25; /*prime*/

        ht = vector<Node*>(M);

        hashValue = func;
    }

    int hash(string key)
    {
        int ret = (hashValue(key)&(0x7fffffff)) % M;
        return ret;
    }

    int search(string key)
    {
        int idx = hash(key);

        Node* now = ht[idx];

        while(now != NULL)
        {
            probecnt++;

            if(now->key == key)
                return now->val;

            now = now->nxt;
        }

        return INT_MIN; /*not found*/
    }

    bool insert(string key,int val)
    {
        int idx = hash(key);

        assert(idx<M);

        Node* now = ht[idx];

        while(now != NULL)
        {
            if(now->key == key)
                return false; /*already exists*/

            now = now->nxt;
        }

        if(ht[idx] != NULL) collisionCnt++;

        ht[idx] = new Node(key,val,ht[idx]);

        return true;
    }

    void erase(string key)
    {
        int idx = hash(key);

        Node* prv = NULL;
        Node* now = ht[idx];

        while(now != NULL)
        {
            if(now->key == key)
            {
                if(prv) prv->nxt = now->nxt;
                else  ht[idx] = now->nxt;

                delete (now);
                return;
            }

            prv = now;
            now = now->nxt;
        }
    }

    void print()
    {
        for(int i=0;i<M;i++)
        {
            cout<<"Chain "<<i<<" : ";

            Node* now = ht[i];
            while(now != NULL) cout<< now->key<<" " , now = now->nxt;
            cout<<endl;
        }
    }

    void printChainLengths()
    {
        for(int i=0;i<M;i++)
        {
            int cnt = 0;

            Node* now = ht[i];
            while(now != NULL) now = now->nxt , cnt++;
            cout<<endl;

            cout<<"Chain "<<i<<" : "<<cnt<<endl;
        }
    }
};

int hashF1(string s)
{
    int h = 0 , p = 31;
    for(int i=0;i<(int)s.size();i++)
    {
        h = (h * p + s[i]);
    }
    return h;
}

int hashF2(string s)
{
    int h = 0 , prime = 31 , p = 1 , mod = 1e9+7;
    for(int i=0;i<(int)s.size();i++)
    {
        h = ((h%mod) + (p * s[i])%mod) % mod;

        p = ((p%mod) * (prime%mod))%mod;
    }
    return h;
}

int32_t main()
{
    HashTable_SeparateChaining h1(hashF1);
    HashTable_SeparateChaining h2(hashF2);

//    freopen("in.txt", "r", stdin);

    int q;
    cin>>q;

    int num_of_inputs = q;
    int num_of_search = 0;

    int val1 = 1 , val2  = 1;

    while(q--)
    {
        string type;
        cin>>type;

        string s;
        cin>>s;

        if(type=="I")
        {
            if(h1.insert(s,val1)) val1++;
            if(h2.insert(s,val2)) val2++;
        }
        else if(type=="F")
        {
            int ret1 = h1.search(s);
            int ret2 = h2.search(s);
//            cout<<ret<<endl;
            num_of_search++;
        }
        else if(type=="E")
        {
            h1.erase(s);
            h2.erase(s);
        }

//        h.print();
    }

    cout<<"N : "<<num_of_inputs<<" , Hash Function 1 :: Number of collsion : "<<h1.collisionCnt<<" , Average Probes : "<<setprecision(3)<<(h1.probecnt*1.0)/num_of_search<<endl;
    cout<<"N : "<<num_of_inputs<<" , Hash Function 2 :: Number of collsion : "<<h2.collisionCnt<<" , Average Probes : "<<setprecision(3)<<(h2.probecnt*1.0)/num_of_search<<endl;
//    h.printChainLengths();

    #ifndef ONLINE_JUDGE
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"<<endl;
    cout<<endl;
    #endif

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
