#include <stdio.h>
#include <stdlib.h>

int maior1 = 0, maior2 = 0, d1 = 0, e1 = 0;

int maior(int a, int b)
{
	return a > b? a : b;
}

int menor(int a, int b)
{
	return a < b? a : b;
}

void resolverE1(int ** arv, int j, int cont)
{
	cont++;
	e1 = cont;
	if(arv[j][1])
		resolverE1(arv, arv[j][1] - 1, cont);
}

void resolverD1(int ** arv, int j, int cont)
{
	cont++;
	d1 = cont;
	if(arv[j][0])
		resolverD1(arv, arv[j][0] - 1, cont);
}
void resolverArv1(int ** arv, int j, int tam, int cont)
{
	cont++;
	if(cont > maior1) maior1 = cont;
	if(arv[j][1])
		resolverArv1(arv,  arv[j][1] - 1, tam, cont);  
	if(arv[j][0]) 
		resolverArv1(arv, arv[j][0] - 1, tam, 0);
}

void resolverArv2(int ** arv, int j,int tam, int cont)
{
	cont++;
	if(cont > maior2) maior2 = cont;
	if(arv[j][0])
		resolverArv2(arv,  arv[j][0] - 1, tam, cont);  
	if(arv[j][1]) 
		resolverArv2(arv, arv[j][1] - 1, tam, 0);
}

int main(int argc, char **argv)
{
	int n, m, j, x;
	int i,l,k;
	int p,q,r;
	int **d,**e, raiz;
	scanf("%d", &n);
	
	e = malloc(sizeof(int*) *n);
	
	for(j = 0; j < n; j++)
		e[j] = calloc(2,sizeof(int));
	
	for(j = 0; j < n; j++){
		scanf("%d %d %d",&i,&l,&k);
		e[i - 1][0] = l;
		e[i - 1][1] = k;
	}
	
	raiz = 1;
	for(j = 0; j < n; j++){
		if(e[j][0] == raiz || e[j][1] == raiz){
			raiz++;
			j = -1;
		}
	}
	
	resolverArv1(e, raiz - 1, n,0);
	resolverE1(e, raiz - 1,0);
	scanf("%d", &m);
	
	d = malloc(sizeof(int*) *m);
	
	for(j = 0; j < m; j++)
		d[j] = calloc(2,sizeof(int));
		
	for(j = 0; j < m; j++){
		scanf("%d %d %d",&p, &q, &r);
		d[p - 1][0] = q;
		d[p - 1][1] = r;
	}
	
	raiz = 1;
	for(j = 0; j < m; j++){
		if(d[j][0] == raiz || d[j][1] == raiz){
			raiz++;
			j = -1;
		}
	}
	
	resolverArv2(d, raiz - 1, m, 0);
	resolverD1(d, raiz - 1, 0);
	printf("%d\n",n+m - maior( menor(e1, maior2), menor(d1,maior1)));
	free(d);
	free(e);
	return 0;
}