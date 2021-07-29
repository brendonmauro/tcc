#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
	long long int n, b, x = 1, y = 1, dir = 0;
	
	scanf("%lld %lld", &n, &b);
	b--;
	n--;
	
	while (b - 4*(n +(n-2)+(n-4) + (n-6))  >= 0)
	{
		b -= 4*n + 4*(n-2) + 4*(n-4) + 4*(n-6);
		n-=8;
		x+=4;
		
	}
	
	
	while (b - 4*n >= 0)
	{
		b -= 4*n;
		n-=2;
		x++;
		
	}
	
	y = x;
	
	while (b)
	{
		if (!dir)
		{
			if (b - n >= 0)
			{
				x+= n;
				b -= n;
			}
			else
			{
				x+= b;
				b = 0;
			}
		}
		else if (dir == 1)
		{
			if (b - n >= 0)
			{
				y+= n;
				b -= n;
			}
			else
			{
				y+= b;
				b = 0;
			}
		}
		else if (dir == 2)
		{
			if (b - n >= 0)
			{
				x-= n;
				b -= n;
			}
			else
			{
				x-= b;
				b = 0;
			}
		}
		else if (dir == 3)
		{
			if (b - n >= 0)
			{
				y-= n;
				b -= n;
			}
			else
			{
				y-= b;
				b = 0;
			}
		}
		dir++;
	}
	
	printf("%lld %lld\n", y,x);
	return 0;
}

