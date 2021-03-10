
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

    int collisionCnt = 0 , probecnt = 0;

    vector<Node*>ht;

    function<int(string)> hashValue;
    function<int(string)> auxhashValue;
    function<int(int,int)> probeFunction;

    template<typename T1,typename T2>
    HashTable_OpenAddressing(T1 func1,T1 func2,T2 func3)
    {
        N = 10000;
        M = 10007; /*N > M*/

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

        while(true)
        {
            probecnt++;

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
        }
    }

    bool insert(string key,int val)
    {
        int idx = hash(key);
        int init_offset = idx;
        int firstDeletedIdx = -1;
        int x = 1; /*probe parameter*/

        while(true)
        {
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

//                collisionCnt += (x-1);

                return true;
            }

            idx = normalize(init_offset + probe(key,x));
            x++;

            collisionCnt++;
        }
    }

    int erase(string key)
    {
        int idx = hash(key);
        int init_offset = idx;
        int firstDeletedIdx = -1;
        int x = 1; /*probe parameter*/

        while(true)
        {
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
        }
    }

    void print()
    {
        int cnt = 0;
        for(int i=0;i<M;i++) cnt += (ht[i]==NULL);

//        DBG(cnt);
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
    HashTable_OpenAddressing h1(hashF1,auxhashF,doubleHashingProbe);
    HashTable_OpenAddressing h2(hashF2,auxhashF,doubleHashingProbe);

    HashTable_OpenAddressing h3(hashF1,auxhashF,customHashingProbe);
    HashTable_OpenAddressing h4(hashF2,auxhashF,customHashingProbe);

//    freopen("in.txt", "r", stdin);

    int q;
    cin>>q;

    int num_of_inputs = q;
    int num_of_search = 0;

    int val1 = 1 , val2 = 1 , val3 = 1 , val4 = 1;

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
            if(h3.insert(s,val3)) val3++;
            if(h4.insert(s,val4)) val4++;
        }
        else if(type=="F")
        {
            int ret1 = h1.search(s);
            int ret2 = h2.search(s);
            int ret3 = h3.search(s);
            int ret4 = h4.search(s);

            num_of_search++;

//            if(ret != INT_MIN) cout<<"Value : "<<ret<<endl;
//            else cout<<"Not Present"<<endl;
        }
        else if(type=="E")
        {
//            int ret = h.erase(s);
//            if(ret != INT_MIN) cout<<"Deleted Value : "<<ret<<endl;
//            else cout<<"Not Present"<<endl;
        }

//        h.print();
    }


    cout<<"Double Hashing"<<endl;
    cout<<"N : "<<num_of_inputs<<" , Hash Function 1 :: Number of collsion : "<<h1.collisionCnt<<" , Average Probes : "<<setprecision(3)<<(h1.probecnt*1.0)/num_of_search<<endl;
    cout<<"N : "<<num_of_inputs<<" , Hash Function 2 :: Number of collsion : "<<h2.collisionCnt<<" , Average Probes : "<<setprecision(3)<<(h2.probecnt*1.0)/num_of_search<<endl;

    cout<<"Custom Probing"<<endl;
    cout<<"N : "<<num_of_inputs<<" , Hash Function 1 :: Number of collsion : "<<h3.collisionCnt<<" , Average Probes : "<<setprecision(3)<<(h3.probecnt*1.0)/num_of_search<<endl;
    cout<<"N : "<<num_of_inputs<<" , Hash Function 2 :: Number of collsion : "<<h4.collisionCnt<<" , Average Probes : "<<setprecision(3)<<(h4.probecnt*1.0)/num_of_search<<endl;

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
