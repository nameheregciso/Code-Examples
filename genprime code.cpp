void genprime(int num)
{
	// there are about n/ln(n) primes upto n

	int prime[num+1], p = 2;
	int listofprime[num];
	
	//initially all nnumbers are primes
	for (int i = 0; i < num+1; ++i)
	{
		prime[i] = 1;
	}

	prime[0] = prime[1] = 0;	//1 and 0 are not primes
	
	while(p*p <= num)
	{
		if(prime[p] == 1)
		{
			for (int i = p*p; i < num+1; i+=p)
			{
				prime[i] = 0;
			}
		}
		p+=1;
	}
	pctr = 0;
	for (int i = 0; i < num+1; ++i)
	{
		if(prime[i] != 0)
			listofprime[pctr++] = i;
	}

	//prime : an array of length 'num'.
	//		  prime[i] = 1 if i is prime
	//listofprime : an array containing only primes from 1 to num
}