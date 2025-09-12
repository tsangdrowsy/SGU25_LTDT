#include <iostream>
#include <vector>
using namespace std;


vector<int> generatePrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}


int countPrimeInFactorial(int N, int prime) {
    int count = 0;
    int power = prime;
    while (power <= N) {
        count += N / power;
        power *= prime;
    }
    return count;
}

int main() {
    int N;
    vector<int> primes = generatePrimes(1000);

    while (cin >> N) {
        vector<int> result;
        for (int p : primes) {
            if (p > N) break;
            result.push_back(countPrimeInFactorial(N, p));
        }

        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}