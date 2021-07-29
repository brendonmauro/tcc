#include <stdio.h>
#include <stdlib.h>

int **mat_adj, **mat_dist,*vet_cid_carga,carga, km = 0,n;

void percorrer(int no, int pai){
  int i, tem_folhas = 1, valor;

  km += mat_dist[no][pai];

  while(tem_folhas){
    tem_folhas = 0;
    for(i = 0; i < n; i++){
      if(i != pai && mat_adj[no][i]){
        percorrer(i, no);
        tem_folhas = 1;
      }
    }
  }

  valor = vet_cid_carga[no] > carga ? carga : vet_cid_carga[no];
  vet_cid_carga[no]-= valor;
  vet_cid_carga[pai] += valor;

  if(vet_cid_carga[no] < 1 ){
    mat_adj[no][pai] =0;
    mat_adj[pai][no] =0;
  }
  km += mat_dist[no][pai];
}

int main(void) {
  int i, j, a, b, c, tem_folhas = 1;
  scanf("%d %d", &n, &carga);

  vet_cid_carga = (int*) malloc (sizeof(int) * n);
  for (i = 0; i < n; i++){
    scanf("%d", &vet_cid_carga[i]);
  }

  mat_adj = (int**) malloc(sizeof(int*) * n);
  mat_dist = (int**) malloc(sizeof(int*) * n);
  for(i = 0; i < n; i++){
    mat_adj[i] = (int*) malloc(sizeof(int)*n);
    mat_dist[i] = (int*) malloc(sizeof(int)*n);
    for(j = 0; j < n; j++){
      mat_adj[i][j] = 0;
      mat_dist[i][j] = 0;
    }
  }  

  for(i = 0; i < n -1; i++){
    scanf("%d %d %d", &a, &b, &c);
    mat_adj[a-1][b-1]++;
    mat_adj[b-1][a-1]++;
    mat_dist[a-1][b-1] = c;
    mat_dist[b-1][a-1] = c;
  }
  
 while(tem_folhas){
    tem_folhas = 0;
    for(i = 1; i < n; i++){
      if(mat_adj[i][0]){
        percorrer(i, 0);
        tem_folhas = 1;
      }
    }
  }

  printf("%d\n", km);
  return 0;
}