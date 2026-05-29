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

int rato, saida;
pilha *pi;


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
int top(pilha *p){
    if (p==NULL || *p==NULL) return -20;
    return (*p)->dado;
}

int mostrar(pilha *p){
    if (p==NULL || *p==NULL) return 0;
    No* no = *p;
    while (no!=NULL)
    {
        printf("%d ",no->dado);
        no=no->prox;
    }
    
}



int campo [30][30];
int posi[2]={0,29};

void gerar_campo(){
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
     
    for (int i=0; i<100; i++)
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
    saida=(saidai*100)+saidaj;
    rato= posR;
    
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
    
    
}

void desenharcampo(){
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
            }else if(campo[i][j] == 4){
                printf("%c",177);
            }
            else if(campo[i][j] == 5){
                printf(".");
            }
            else{
                printf(" ");
            }
        
        }
    printf("\n");
    }
}

void definirCaminho(int posR, int posS){
    int posx,posy;
    posx=posR/100;
    posy=posR%100;

    
if (posR!=posS)
{


    if (campo[posx][posy+1] == 0 || campo[posx][posy+1] == 3 || campo[posx][posy+1] == 2)
    {

        
        push(pi,posR);
        campo[posx][posy]=5;
        campo[posx][posy+1]=3; 
        posy++;
        posR=(posx*100)+posy;
        printf("%d ",posR);
        system("cls");
        desenharcampo();
        definirCaminho(posR,posS);
    
    } else if (campo[posx+1][posy] == 0 || campo [posx+1][posy]==3 || campo [posx+1][posy]==2){
        push(pi,posR);
        campo[posx][posy]=5; 
        campo[posx+1][posy]=3; 
        posx++;
        posR=(posx*100)+posy;
        printf("aaaa %d ",posR);
        system("cls");
        desenharcampo();
        definirCaminho(posR,posS);
    } else if (campo[posx-1][posy]==0 || campo[posx-1][posy]==3 || campo[posx-1][posy]==2){
        push(pi,posR);
        campo[posx][posy]=5;
        desenharcampo();
        printf("%d ",posx);
        printf("%d ", top(pi));
        printf("aaaa %d ",posR);
        campo[posx-1][posy]=3; 
         
        posx--;
        posR=(posx*100)+posy;
        system("cls");
        desenharcampo();
        printf("%d ",posR);
        definirCaminho(posR,posS);
    }   else if (campo[posx][posy-1]==0 || campo[posx][posy-1]==3 || campo[posx][posy-1]==2){
        push(pi,posR);
        campo[posx][posy]=5;
        campo[posx][posy-1]=3;  
        posy--;
        posR=(posx*100)+posy;
        system("cls");
        desenharcampo();
        printf("%d ",posR);
        definirCaminho(posR,posS);
    }
    else{
        pop(pi);
        desenharcampo();
        posR=top(pi);
        //volta muito; perde o caminho; verificar se tem caminho já visitado
        campo[posx][posy]=4;
        posx=posR/100;
        posy=posR%100;
        campo[posx][posy]=3;
        system("cls");
        

        definirCaminho(posR,posS);
        
    }
}
}

int main(int argc, char const *argv[])
{
    gerar_campo();
    pi= Criar_pilha();
    pilha *Pilha = Criar_pilha();
    printf("%d %d",rato, saida);
    definirCaminho(rato,saida);
    system("cls");
    desenharcampo();
    printf("caminho encontrado");
    mostrar(pi);
    return 0;

}
