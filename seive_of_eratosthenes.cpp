#include <iostream>
#include <vector>
using namespace std;
#define SIZE 100005
#define int long long
#define pb push_back

vector<int> allPrimes;

void seive() { 
    vector<bool> isPrime(SIZE, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i < SIZE; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < SIZE; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for (int i = 2; i < SIZE; i++) {
        if (isPrime[i]) {
            allPrimes.pb(i);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seive();

    for (int i : allPrimes) {
        cout << i << " ";
    }

    return 0;
}
