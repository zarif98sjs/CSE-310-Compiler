
/*
 *
 * Hash Table : Open Addressing Method
 *
 * - Md. Zarif Ul Alam
 * Staring at : 18 November 2020 2:35pm
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

    bool isDeletedBefore; /*marker*/

    Node(){ this->isDeletedBefore = true; }

    Node(string key,int val,bool isDeletedBefore = false)
    {
        this->key = key;
        this->val = val;

        this->isDeletedBefore = isDeletedBefore;
    }
};

/*
 * N > M to handle collisions
 * */

struct HashTable_OpenAddressing
{
    int N; /* initial number of assumed data */
    int M; /* initial hast table size */

    vector<Node*>ht;

    function<int(string)> hashValue;
    function<int(string)> auxhashValue;
    function<int(int,int)> probeFunction;

    template<typename T1,typename T2>
    HashTable_OpenAddressing(int table_size,T1 func1,T1 func2,T2 func3)
    {
        N = 10000;
        M = table_size; /* M > N , M prime */

        ht = vector<Node*>(M,NULL);

        hashValue = func1;
        auxhashValue = func2;
        probeFunction = func3;
    }

    int hash(string key)
    {
        int ret = (hashValue(key)&(0x7fffffff)) % M;
        return ret;
    }

    int auxhash(string key)
    {
        int ret = (auxhashValue(key)&(0x7fffffff)) % M;
        return ret == 0 ? 1 : ret;
    }

    int normalize(int val)
    {
        return (val & 0x7fffffff)%M;
    }

    int probe(string key,int x)
    {
        int aux = auxhash(key);
        return probeFunction(x,aux);
    }

    int search(string key)
    {
        int idx = hash(key);
        int init_offset = idx;
        int firstDeletedIdx = -1;
        int x = 1; /*probe parameter*/

        int num_of_op = 0;

        while(true)
        {
            num_of_op++;

            if(ht[idx] != NULL && ht[idx]->isDeletedBefore == true)
            {
                if(firstDeletedIdx == -1) firstDeletedIdx = idx;
            }
            else if(ht[idx] != NULL)
            {
                if(ht[idx]->key == key)
                {
                    int ret = ht[idx]->val;

                    if(firstDeletedIdx != -1)
                    {
                        ht[firstDeletedIdx] = ht[idx];
                        ht[idx] = new Node("marker",INT_MIN,true); /*rip marker*/
                    }

                    return ret;
                }
            }
            else if(ht[idx] == NULL) return INT_MIN;

            idx = normalize(init_offset + probe(key,x));
            x++;

            if(num_of_op>M)
            {
                cout<<"Modulo Ring Created , Choose Hash Table Size to be prime to avoid Modulo Ring"<<endl;
                return INT_MIN;
            }
        }
    }

    bool insert(string key,int val)
    {
        int idx = hash(key);
        int init_offset = idx;
        int firstDeletedIdx = -1;
        int x = 1; /*probe parameter*/

        int num_of_op = 0;

        while(true)
        {
            num_of_op++;

            if(ht[idx] != NULL && ht[idx]->isDeletedBefore == true)
            {
                if(firstDeletedIdx == -1) firstDeletedIdx = idx;
            }
            else if(ht[idx] != NULL)
            {
                if(ht[idx]->key == key)
                {
                    if(firstDeletedIdx != -1)
                    {
                        ht[firstDeletedIdx] = ht[idx];
                        ht[idx] = new Node("marker",INT_MIN,true); /*rip marker*/
                    }
                    return false;
                }
            }
            else if(ht[idx] == NULL)
            {
                if(firstDeletedIdx != -1)
                {
                    ht[firstDeletedIdx] = new Node(key,val);
                }
                else
                {
                    ht[idx] = new Node(key,val);
                }

                return true;
            }

            idx = normalize(init_offset + probe(key,x));
            x++;

            if(num_of_op>M)
            {
                cout<<"Modulo Ring Created , Choose Hash Table Size to be prime to avoid Modulo Ring"<<endl;
                return false;
            }
        }
    }

    int erase(string key)
    {
        int idx = hash(key);
        int init_offset = idx;
        int firstDeletedIdx = -1;
        int x = 1; /*probe parameter*/

        int num_of_op = 0;

        while(true)
        {
            num_of_op++;

            if(ht[idx] != NULL && ht[idx]->isDeletedBefore == true)
            {
                continue;
            }
            else if(ht[idx] != NULL)
            {
                if(ht[idx]->key == key)
                {
                    int ret = ht[idx]->val;

                    ht[idx] = ht[idx] = new Node("marker",INT_MIN,true); /*rip marker*/
                    return ret;
                }
            }
            else if(ht[idx] == NULL) return INT_MIN; /*item not found*/

            idx = normalize(init_offset + probe(key,x));
            x++;

            if(num_of_op>M)
            {
                cout<<"Modulo Ring Created , Choose Hash Table Size to be prime to avoid Modulo Ring"<<endl;
                return INT_MIN;
            }
        }
    }

    void print()
    {
//        int cnt = 0;
//        for(int i=0;i<M;i++) cnt += (ht[i]==NULL);
//        DBG(cnt);

        for(int i=0;i<M;i++)
        {
            if(ht[i]==NULL) cout<<"NULL ";
            else cout<<ht[i]->key<<" ";
        }
        cout<<endl;
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

int auxhashF(string s)
{
    int h = 7 , p = 31;
    for(int i=0;i<(int)s.size();i++)
    {
        h = (h * p + s[i]);
    }
    return h;
}


int doubleHashingProbe(int x,int aux)
{
    return x*aux;
}

int customHashingProbe(int x,int aux)
{
    return (x*aux + x*x)>>1;
}

int32_t main()
{
    int table_size;
    cin>>table_size;

    table_size = 10007;

    HashTable_OpenAddressing h(table_size,hashF1,auxhashF,doubleHashingProbe);
//    HashTable_OpenAddressing h(table_size,hashF2,auxhashF,doubleHashingProbe);
//
//    HashTable_OpenAddressing h(table_size,hashF1,auxhashF,customHashingProbe);
//    HashTable_OpenAddressing h(table_size,hashF2,auxhashF,customHashingProbe);

    int q;
    cin>>q;

    int val = 1;

    while(q--)
    {
        string type;
        cin>>type;

        if(type=="P")
        {
            h.print();
            continue;
        }

        string s;
        cin>>s;

        if(type=="I")
        {
            if(h.insert(s,val)) val++;
            else cout<<"Not inserted "<<s<<endl;
        }
        else if(type=="F")
        {
            int ret = h.search(s);
            if(ret != INT_MIN) cout<<"Value : "<<ret<<endl;
            else cout<<"Not Present "<<s<<endl;
        }
        else if(type=="E")
        {
            int ret = h.erase(s);
            if(ret != INT_MIN) cout<<"Deleted Value : "<<ret<<endl;
            else cout<<"Not Present "<<s<<endl;
        }

//        h.print();

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
