#include <cstdio>
#include <vector>
using namespace std;
vector<bool> SieveOfEratosthenes(unsigned long less)
{
								// Create a boolean array "prime[0..n]" and initialize
								// all entries it as true. A value in prime[i] will
								// finally be false if i is Not a prime, else true.
								vector<bool> prime(less + 1);
								fill(begin(prime), end(prime), true);

								for (unsigned long p = 2; p*p <= less; p++)
								{
																// If prime[p] is not changed, then it is a prime
																if (prime[p] == true)
																{
																								// Update all multiples of p
																								for (unsigned long i = p * 2; i <= less; i += p)
																																prime[i] = false;
																}
								}

								return prime;

								// Print all prime numbers
								//for (unsigned long p = 2; p <= less; p++)
								//	if (prime[p] == true)
								//		cout << p << " ";
}

unsigned long get_nth_prime_with_basic_sieve(unsigned long n) {
								unsigned long precompute_max_count = 100000;

								do
								{
																if (precompute_max_count >= numeric_limits<unsigned long>::max())
																								break;

																auto prime = SieveOfEratosthenes(precompute_max_count);

																// how manay 'true' exist?
																unsigned long primes_length = count(begin(prime) + 2, end(prime), true);

																if (primes_length < n) {
																								precompute_max_count *= 2; // double the limit & try again
																								continue;
																}

																// get index nth true locates
																unsigned long nth = 0;

																// from prime[2] - (prime[0] and prime[1] are true, but not prime numbers),
																// if n is equal to the summed up prime numbers, then return the location.
																auto it = find_if(begin(prime) + 2, end(prime), [nth, n](bool e) mutable {
																								if (e) { // find the true elements
																																nth++; // and increment the count
																																if (nth == n) // and we found Nth number,
																																								return true;
																								}
																								return false;
																});

																// get the value of found index points to.
																auto d = distance(begin(prime), it);

																return d;

								} while (true);

								return 0;
}
int main()
{
								unsigned long n;
								scanf("%ld",&n);
								printf("%ld",get_nth_prime_with_basic_sieve(n));
}
