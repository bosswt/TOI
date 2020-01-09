#include <cstdio>
using namespace std;
bool isPrime(unsigned long num)
{
        if (num == 2)
                return true;

        if (num <= 1 || num % 2 == 0) // 0, 1, and all even numbers
                return false;

        for (unsigned long x = 3; x*x <= num; x += 2) {
                if (num % x == 0)
                        return false;
        }

        return true;
}
unsigned long get_nth_prime_without_sieve(unsigned long n) {

        if (n == 0) return 0;
        if (n == 1) return 2;

        unsigned long prime_num = 3;
        unsigned long local_n = 2; // 2th prime number is 3

        while (local_n != n) {

                // check next prime number candidate
                prime_num += 2; // 3,5,7,9... check only odd numbers

                if (isPrime(prime_num) == true) {
                        local_n++;
                }
        }

        return prime_num;
}
int main()
{
        unsigned long n;
        scanf("%ld",&n);
        printf("%ld",get_nth_prime_without_sieve(n));
}
