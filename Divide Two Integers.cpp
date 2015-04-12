#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
	const int MAX_INT = (unsigned)(-1)>>1;
	const int MIN_INT = (unsigned)(~MAX_INT);

	if(dividend == divisor) return 1;
	if(divisor == 0 || (dividend == MIN_INT && divisor == -1)) return MAX_INT;
	if(divisor == MIN_INT) return 0;
	if(divisor == 1) return dividend;
	if(divisor == -1) return -dividend;

	bool negtive = (dividend < 0) ^ (divisor < 0);
	long _dividend, _divisor;
	if(dividend < 0)
	{
		if(dividend == MIN_INT)
			_dividend = (long) MAX_INT + 1l;
		else
			_dividend = -dividend;
	}else{
		_dividend = dividend;
	}

	_divisor = (divisor < 0) ? -divisor : divisor;

	int result = 0;
	while(_divisor <= _dividend)
	{
		int ans = 1;
		long div_tmp = _divisor;
		while(_dividend >> 1 >= div_tmp)
		{
			ans <<= 1;
			div_tmp <<= 1;
		}
		result += ans;
		_dividend -= div_tmp;
	}
	return (negtive) ? -result : result;
}

int main()
{
	printf("%d\n", divide(-2147483648, 2));
}