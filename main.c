#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void preenche_vetor_primos(int *vetor, int t){

    int aux=0, k=0, i=0, j=0;

    for(i=2; k<t; i++){
        if(i<=3){
            vetor[k]=i;
            k++;
        }
        else{
            if(i%2!=0){
                aux=0;
                for(j=3; j<=sqrt(i); j+=2){
                    if(i%j==0)
                        aux++;
                }
                if(aux<1){
                    vetor[k]=i;
                    k++;
                }
            }
        }
    }
}

int calcula_posicao(int n, int vet[], int soma, int i){

    if(i<=n){
        return calcula_posicao(n, vet, ((soma+vet[n-i])%i), i+1);
    }
    else
        return ++soma;
}

int main(){

    int n, vetor_primos[3501], vetor_result[200], result=0, k=0, j=0;

    preenche_vetor_primos(vetor_primos, 3501);

    do{

        scanf("%d", &n);

        if(n!=0){

            int i=1, soma=0;

            result = calcula_posicao(n, vetor_primos, soma, i);

            vetor_result[k]=result;
            k++;
        }

    }while(n!=0);

    for(j=0; j<k; j++)
        printf("%d\n", vetor_result[j]);

    return 0;
}
