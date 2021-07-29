#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  **mat_dist,*vet_cid_carga,carga, km = 0,n;

void percorrer(int no, int pai){
  int i, tem_folhas = 1, valor;


  for(i = 0; i < n; i++){
    if(i != pai && mat_dist[no][i]){
      percorrer(i, no);
    }
  }

  valor = ceil((float)vet_cid_carga[no] / carga);
  vet_cid_carga[pai] += vet_cid_carga[no];
  vet_cid_carga[no] = 0;
  
  km += mat_dist[no][pai] * 2 * valor;
}

int main(void) {
  int i, j, a, b, c, tem_folhas = 1;
  scanf("%d %d", &n, &carga);

  vet_cid_carga = (int*) malloc (sizeof(int) * n);
  for (i = 0; i < n; i++){
    scanf("%d", &vet_cid_carga[i]);
  }

  mat_dist = (int**) malloc(sizeof(int*) * n);
  for(i = 0; i < n; i++){
    mat_dist[i] = (int*) malloc(sizeof(int)*n);
    for(j = 0; j < n; j++){
      mat_dist[i][j] = 0;
    }
  }  

  for(i = 0; i < n -1; i++){
    scanf("%d %d %d", &a, &b, &c);
    mat_dist[a-1][b-1] = c;
    mat_dist[b-1][a-1] = c;
  }
  
  for(i = 1; i < n; i++){
    if(mat_dist[i][0]){
      percorrer(i, 0);

    }
  }
  
  printf("%d\n", km);
  return 0;
}