#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long w, h, d, n;
    cin >> w >> h >> d >> n;

    for (long long a = 1; a * a * a <= n; a++) {
        if (n % a != 0) continue;
        long long n1 = n / a;

        for (long long b = 1; b * b <= n1; b++) {
            if (n1 % b != 0) continue;
            long long c = n1 / b;

            long long x[3] = {a, b, c};
            long long dims[3] = {w, h, d};

            sort(x, x + 3);
            do {
                if (dims[0] % x[0] == 0 &&
                    dims[1] % x[1] == 0 &&
                    dims[2] % x[2] == 0) {

                    cout << x[0] - 1 << " "
                         << x[1] - 1 << " "
                         << x[2] - 1 << "\n";
                    return 0;
                }
            } while (next_permutation(x, x + 3));
        }
    }

    cout << -1 << "\n";
    return 0;
}
