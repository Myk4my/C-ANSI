#include<stdio.h>
#include <stdlib.h>

// FUNÇÕES PARA A PROVA

// FUNÇÕES PARA ARQUIVOS

// ABRE O ARQUIVO arq e adiciona ao ponteiro file
if((file = fopen("arq", "r")) != NULL) printf("Arquivo 1 aberto\n"); 
feof(file)         // verifica se o arquivo acabou
getc(file)        // pega um caractere
fseek(file, 6, SEEK_?) // move o arquivo para SEEK_END=FINAL, SEEK_CUR=ATUAL, SEEK_SET
fclose(file);    // fecha o arquivo
fscanf(file, "%d", &num);              // le do arquivo 
fprintf(file, "%d", &num);            // escreve o conteúdo a ser gravado
fread(&num2, sizeof(int), 1, file);  // le do arquivo em binário
fwrite(&id, sizeof(int), 1, file2); // escreve no arquivo em binario
rename("file", "file2");           // renomeia file para file2
fclose(file);   // fecha o arquivo 
free(memoria); // libera memoria alocada


// INSERE O ELEMENTO DE FORMA ORDENADA 
struct elemento *inserirOrdenada(struct elemento *lista, char id) {
    struct elemento *aux, *cur;
    aux = (struct elemento *) malloc (sizeof(struct elemento));
    aux->id = id;

    if (!lista || id < lista->id) {
        aux->prox = lista;
        return aux;
    } 

    for(cur = lista; cur->prox && cur->prox->id < id; cur = cur->prox);
        aux->prox = cur->prox;
        cur->prox = aux;
        return lista;
    }

// INSERE O ELEMENTO NO INÍCIO 
struct elemento *inserirInicio(struct elemento *l, char id) {
    struct elemento *aux;
    aux = (struct elemento *) malloc (sizeof(struct elemento));
    aux->id = id;
    aux->prox = l;
    return aux;
}

// MOSTA TODOS OS ELEMENTOS
void mostrar (struct elemento *outro) {
    while(outro != NULL) {
        printf("%c ", outro->id);
        outro = outro->prox;
    }
}

// ELIMINA UM ELEMENTO
void eliminar(struct elemento *outro) {
    struct elemento *aux;
    while(outro) {
        aux = outro->prox;
        free(outro);
        outro = aux;
    }
}

// INSERE O ELEMENTO NO FINAL DA LISTA 
struct elemento *inserirFinal(struct elemento *l, char id) {
    struct elemento *aux, *ini;
    aux = (struct elemento *) malloc (sizeof(struct elemento));
    aux->id = id;
    aux->prox = NULL;
    
    if (!l) return aux;
  
    ini = l;
    while(l->prox != NULL) l = l->prox;
    l->prox = aux;
    return ini;
}

// MOSTRA A LISTA INVERTIDA
void mostrarInvRec(struct elemento *lista) {
    if (lista) {
        mostrarInvRec(lista->prox);
        printf("%c ", lista->id);
    }
}

// ELIMINA O PRIMEIRO ELEMENTO
char eliminarPrim(struct elemento **lista) {
    struct elemento *aux;
    char letra;
    aux = *lista;
    letra = aux->id;
    *lista = aux->prox;
    free(aux);
    return letra;
}

// ELIMINA O CONTEUDO 
struct elemento *eliminarConteudo(struct elemento *lista, char id) {
    struct elemento *aux, *ini;
    while (lista && lista->id == id) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
    if (!lista) return NULL;
    ini = lista;
    
    while (lista->prox) {
        if (lista->prox->id == id) {
            aux = lista->prox;
            lista->prox = aux->prox;
            free(aux);
        }
        else    lista = lista->prox;
    }
      return ini;
}

// INSERE NUMA DETERMINADA POSIÇÃO
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

// MESCLA AS LISTAS DE FORMA ORDENADA
struct elemento *mesclar(struct elemento *lista, struct elemento *lista2) {
    struct elemento *ri, *rf;
    if (!lista)     return lista2;
    if (!lista2)    return lista;
  
    if (lista->id < lista2->id) {
        ri = rf = lista;
        lista = lista->prox;
    }
    else {
        ri = rf = lista2;
        lista2 = lista2->prox;
    }
  
    while(lista && lista2) {
        if (lista->id < lista2->id) {
            rf->prox = lista;
            lista = lista->prox;
            rf = rf->prox;
        }
        else {
            rf->prox = lista2;
            lista2 = lista2->prox;
            rf = rf->prox;
        }
    }
    if (!lista) rf->prox = lista2;
    else  rf->prox = lista;

  return ri;
}

