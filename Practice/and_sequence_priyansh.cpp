/* Priyansh Agarwal*/

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef Priyansh31dec
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

// std::ostream&
// operator<<( std::ostream& dest, __int128_t value )
// {
// 	std::ostream::sentry s( dest );
// 	if ( s ) {
// 		__uint128_t tmp = value < 0 ? -value : value; char buffer[ 128
// ]; 		char* d = std::end( buffer );
// 		do {	-- d; *d = "0123456789"[ tmp % 10 ]; tmp /= 10;} while (
// tmp != 0 ); 		if ( value < 0 ) {-- d; *d = '-';} 		int len
// = std::end( buffer ) - d; 		if ( dest.rdbuf()->sputn( d, len ) !=
// len ) {dest.setstate( std::ios_base::badbit );}
// 	}
// 	return dest;
// }

// __int128 read() {
// 	__int128 x = 0, f = 1;
// 	char ch = getchar();
// 	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
// 	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
// 	return x * f;
// }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef __int128 ell;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
// tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
// void _print(ell t) {cerr << t;}

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";}
// cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v) {
    if (b == 0) {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
}  // pass an arry of size1 3
ll mminv(ll a, ll b) {
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
}  // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n) {
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0) {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}  // only for prime m
ll phin(ll n) {
    ll number = n;
    if (n % 2 == 0) {
        number /= 2;
        while (n % 2 == 0) n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1) number = (number / n * (n - 1));
    return number;
}  // O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
const int nMax = 2 * 1e5 + 10;
void solve() {
    int t;
    cin >> t;
    ll fact[nMax];
    fact[0] = 1;
    for (ll i = 1; i < nMax; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
    }
    while (t--) {
        int n;
        cin >> n;
        ll arr[n];
        map<ll, ll> m1;
        ll val = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i == 0) val = arr[i];
            val = val & arr[i];
            m1[arr[i]]++;
        }
        ll ways = 1;
        if (m1.find(val) == m1.end() || m1[val] < 2) {
            cout << 0 << nline;
            continue;
        }
        cout << m1[val] << endl;
        ways = mod_mul(ways, m1[val], MOD);
        m1[val]--;
        ways = mod_mul(ways, m1[val], MOD);
        cout << ways << endl;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if ((val & arr[i]) != val) {
                counter = 1;
                break;
            }
        }
        if (counter == 1) {
            cout << 0 << nline;
            continue;
        }
        cout << mod_mul(fact[n - 2], ways, MOD) << nline;
    }
}

int main() {
#ifdef Priyansh31dec
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Priyansh31dec
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}