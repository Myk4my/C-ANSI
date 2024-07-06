#include<stdio.h>

struct elemento {
  char id;  /* representa um conjunto de campos, com todos os dados a serem armazenados */
  struct elemento *prox;
  };

struct elemento *inserirInicio(struct elemento *l, char id) {
  struct elemento *aux;
  aux = (struct elemento *) malloc (sizeof(struct elemento));
  aux->id = id;
  aux->prox = l;
  return aux;
  }

void mostrar (struct elemento *outro) {
  while(outro != NULL) {
    printf("%c ", outro->id);
    outro = outro->prox;
    }
  }

void eliminar(struct elemento *outro) {
  struct elemento *aux;
  while(outro) {
    aux = outro->prox;
    free(outro);
    outro = aux;
    }
  }

struct elemento *inserirFinal(struct elemento *l, char id) {
  struct elemento *aux, *ini;
  aux = (struct elemento *) malloc (sizeof(struct elemento));
  aux->id = id;
  aux->prox = NULL;
  if (!l) {
    return aux;
    }
  ini = l;
  while(l->prox != NULL) {
    l = l->prox;
    }
  l->prox = aux;
  return ini;
  }

struct elemento *inserirPosicao(struct elemento *l, char id, int k) {
  struct elemento *aux, *pos;
  aux = (struct elemento *) malloc (sizeof(struct elemento));
  aux->id = id;
  if (!l) {
    aux->prox = NULL;
    return aux;
    }
  if (k == 1) {
    aux->prox = l;
    return aux;
    }
  for(pos = l; pos->prox && k > 2; pos = pos->prox, k--);
  aux->prox = pos->prox;
  pos->prox = aux;
  return l;
  }

main() {
  struct elemento *lista, *aux, *outro;
  int i;

  lista = NULL;

  lista = inserirFinal(lista, 'Z');

  for(i = 0; i < 6; i++) {
    lista = inserirInicio(lista, 'B'+i);
    }

  lista = inserirFinal(lista, 'X');

  lista = inserirPosicao(lista, 'L', 5);

  mostrar(lista);

  eliminar(lista);
  }





















  /*

int achaIndice(char valor) {
  return valor - 'A';
  }

void mostrarFis(struct elemento lista[], int p) {
  int i;
  for (i = 0; i < 26; i++) {
    printf("%c - %d", lista[i].id, lista[i].prox);
    if (i == p)
      printf("     <---\n");
    else
      printf("\n");
    }
  }

void mostrarLog(struct elemento lista[], int p) {
  while (p != -1) {
    printf("%c  ", lista[p].id);
    p = lista[p].prox;
    }
  }


void mostrarLogInv(struct elemento lista[], int p) {
  if (p != -1) {
    //printf("%c  ", lista[p].id);
    mostrarLogInv(lista, lista[p].prox);
    printf("%c  ", lista[p].id);
    }
  }

int inserirInicio(char letra, struct elemento *vet, int primeiro) {
  int indice;
  if (primeiro == -1) {
    return achaIndice(letra);
    }
  indice = achaIndice(letra);
  vet[indice].prox = primeiro;
  return indice;
  }


int inserirFinal(char letra, struct elemento *lista, int p) {
  int indice, ini;
  if (p == -1) {
    return achaIndice(letra);
    }
  ini = p;
  while (lista[p].prox != -1) {
    p = lista[p].prox;
    }
  indice = achaIndice(letra);
  lista[p].prox = indice;
  return ini;
  }

int removerConteudo(char letra, struct elemento *lista, int p) {
  int ini;
  if (lista[p].id == letra) {
    ini = lista[p].prox;
    lista[p].prox = -1;
    return ini;
    }
  ini = p;
  while(lista[p].prox != -1 && lista[lista[p].prox].id != letra) {
    p = lista[p].prox;
    }
  if (lista[p].prox != -1) {
    int temp;
    temp = lista[lista[p].prox].prox;
    lista[lista[p].prox].prox = -1;
    lista[p].prox = temp;
    }
  return ini;
  }


main() {
  int i, primeiro;
  char c;
  struct elemento vet[26];
  for (i = 0; i < 26; i++) {
    vet[i].id = i + 'A';
    vet[i].prox = -1;
    }
  primeiro = -1;

  primeiro = inserirInicio('M', vet, primeiro);
  primeiro = inserirInicio('B', vet, primeiro);
  primeiro = inserirInicio('A', vet, primeiro);
  primeiro = inserirInicio('J', vet, primeiro);
  primeiro = inserirInicio('F', vet, primeiro);

//  primeiro = inserirFinal('K', vet, primeiro);
//  primeiro = inserirFinal('L', vet, primeiro);
//  primeiro = inserirFinal('N', vet, primeiro);


  primeiro = removerConteudo('J', vet, primeiro);


  mostrarFis(vet, primeiro);
  printf("\n\n");

  mostrarLog(vet, primeiro);
  printf("\n\n");

  mostrarLogInv(vet, primeiro);
  printf("\n\n");

  }

*/
