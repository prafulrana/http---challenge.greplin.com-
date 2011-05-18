// fibonacci numbers
// fast memoization will give us O(n) generation time for fibonacci

//seed our static counters
static unsigned long long FNminus2 = 0; 
static unsigned long long FNminus1 = 1;
static unsigned long long F = 1;

void iterateNextFibonacci()
{
    F = FNminus1 + FNminus2;

    FNminus2 = FNminus1;
    FNminus1 = F;
}


// primality test funciton
// O[N] 

int isPrime(unsigned long long n)
{
    unsigned long long i = 0;
    
    unsigned long long stoppingPoint = ( unsigned long long ) n/2;
    
    if(n < 2)
        return 1;

    
    // if its divisble by any number less than its half its not a prime number.
    for (i = 2; i <= stoppingPoint; i++)
    {
        if ((n % i) == 0 )
            return 0;
    }
    
    return 1;
}


// find sum of prime divisors
// O[N^2]
// sweep through all the numbers less than n/2 as i; if n % i == 0 and isPrime(i) 
// then i is a prime divisor O[N]

unsigned long long getSumOfPrimeDivisors(unsigned long long n)
{
    unsigned long long i = 0;
    unsigned long long res = 0;
    
    for (i = 2; i < n / 2; i++)
    {
        if ( ((n % i) == 0 ) && isPrime(i) )
        {
            res += i;
        }
    }
    
    return res;
}


// testing 

void testIsPrime()
{
    printf("1 is %d\n", isPrime(1));
    printf("15 is %d\n", isPrime(15));
    printf("37 is %d\n", isPrime(37));
    printf("4 is %d\n", isPrime(4));
    printf("912390213 is %d\n ", isPrime(912390213));
}

// test our FIB logic
void generate100FIBs()
{
    int i = 0;
    
    for (i = 0; i < 100; i++)
    {
        iterateNextFibonacci();
        printf("The %dth FIB number is %llu\n", i + 2, F);
    }
}

int main()
{
    // test prime
    // testIsPrime();
    
    // test our FIB logic
    // generate100FIBs();
    
    
    unsigned long long minimum = 227000;
    unsigned long long i = 0;
    
    // iterate past minimum threshold
    while ( F < minimum )
        iterateNextFibonacci();

    // iterate to next Fib prime
    while ( ! isPrime(F) )
        iterateNextFibonacci();
    
    printf("The answer is %llu\n", getSumOfPrimeDivisors(F+1));
    
    return 0;
}