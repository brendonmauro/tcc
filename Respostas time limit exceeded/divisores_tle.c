#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b,c,d, num;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	num  = a;
	while(num <= c)
	{
		if(num % a == 0 && num % b != 0 && c % num == 0 && d % num != 0 )
		{
			printf("%d\n",num);
			return 0;
		}
		num += a;
	}
	printf("%d\n",-1);
	
	return 0;
}