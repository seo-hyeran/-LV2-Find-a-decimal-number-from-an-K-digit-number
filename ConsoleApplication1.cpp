#include <string>
#include <vector>
#include<regex>
#include<cmath>
using namespace std;

bool isprime(long long n) {
    if (n < 2) {
        return false;
    }
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }

    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string a = "";
    while (1) {

        if (n < k) {
            a += to_string(n % k);
            break;
        }
        a += to_string(n % k);
        n = n / k;

    }
    reverse(a.begin(), a.end());

    a += "0";

    string tmp = "";
    long long b = 0;
    for (int i = 0; i < a.length(); i++) {


        if (a[i] == '0') {
            if (tmp != "") {

                b = stoll(tmp);

                if (isprime(b)) {

                    answer++;
                }
            }
            tmp = "";

        }
        else {
            tmp += a[i];
        }
    }


    return answer;
}