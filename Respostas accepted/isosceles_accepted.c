#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n, *a, d, i, j,k = 2, maior = 1;
	
	scanf("%d", &n);
	a = malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]); 
	
	
	for(i = 1; i < n - 1; i++, k++){
		if(a[i] < k) k = a[i];
		d = k + 1;
		
		while(--d > maior){
			j = i;
			while(++j < n && --d > 1)
				if (a[j] < d) break;
			
			if(d == 1) maior = k;
		}
	}
	printf("%d\n", maior);
	return 0;
}
