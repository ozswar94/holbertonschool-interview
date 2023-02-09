/**
 ** getbeg - finds number number needed to index first digit of n
 ** @n: number to check
 **
 ** Return: beginning index
 **/
unsigned long getbeg(unsigned long n)
{
	unsigned long beg = 1;

	do
		beg *= 10;

	while (n /= 10);
	return (beg / 10);
}

/**
 ** is_palindrome - checks palindrome
 ** @n: number to check
 **
 ** Return: 1 if palindrome, otherwise 0
 **/
int is_palindrome(unsigned long n)
{
	unsigned long b, e;

	for (b = getbeg(n), e = 1; b > e; b /= 10, e *= 10)
		if (n / b % 10 != n / e % 10)
			return (0);
	return (1);
}