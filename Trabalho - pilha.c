#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct ele{
    int dado;
    struct ele *prox;
}No;

typedef No* pilha;

pilha * Criar_pilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if (p != NULL){
        *p = NULL;
    }
    return p;
}


pilha *pi=NULL;

int push(pilha *p,int x){
    if(p==NULL ) return 0;
    No* no = (No*) malloc(sizeof(No));
    if (no==NULL) return 0;
    no->dado=x;
    no->prox= (*p);
    *p=no;
    return 1;
}

int pop(pilha *p){
    if (p==NULL || *p==NULL) return 0;
    No *no = *p;
    *p = no->prox;
    free(no);
    return 1;   
}



int campo [30][30];
int posi[2]={0,29};

int gerar_campo(){
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            campo[i][j] = 0;
            if (i==0 || i==29 || j==0 || j==29)
            {
                campo[i][j] = 1;
            }
        }
        
    }
    srand(time(NULL));

    int saidai;
    int saidaj = rand() % (29) + 1;
    if (saidaj==0 || saidaj==29)
    {
        int numero;
        do {
            saidai = rand() % (29);
        } while (numero == 0);
     
    }else{
         saidai = posi[rand() % 2];
    }
     
    for (int i=0; i<50; i++)
    {
   
        int num1 = rand() % (28) + 1;
        int num2 = rand() % (28) + 1;
        campo[num1][num2] = 1;
    }

        int num1 = rand() % (29) + 1;
        int num2 = rand() % (29) + 1;
        campo[num1][num2] = 3;
        int posR=(num1*100)+num2;
        
    
    
    campo[saidai][saidaj] = 2;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            

            if(campo[i][j] == 1){
                printf("#");
            }else if(campo[i][j] == 2){
                printf("S");
            }else if(campo[i][j] == 3){
                printf("X");
            }else{
                printf(" ");
            }
        
        }
    printf("\n");
    }
    return posR;
}

void definirCaminho(int posR){
    int posx,posy;
    posx=posR/100;
    posy=posR%100;

    

    if (campo[posx][posy+1] == 0 || campo[posx][posy+1] == 3)
    {
        push(pi,posR);
        posy++;
        posR=(posx*100)+posy;
        definirCaminho(posR);
    
    } else if (campo[posx+1][posy] == 0 || campo [posx])
}


int main(int argc, char const *argv[])
{
    int rato=gerar_campo();
    pilha *Pilha = Criar_pilha();

    return 0;

}
