/*
Allan Patrick
Daniel Curi
Estevao Gomes

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *distancia_entre_margens, *n_pedras_B,*n_pedras_S;

void aloca_distancia(int d);

int maxima_distancia( int t);



main()
{
    int t,i,maior_distancia;

    printf("NUMERO DE TESTES: ");
    scanf("%d",&t);


    for(i = 0; i < t; i++)
    {
        maior_distancia = maxima_distancia(i+1);

        printf("\n\n> Caso %d: %d\n\n",i+1, maior_distancia);

    }




    return 0;

}

void aloca_distancia(int d)
{
    int j;

    distancia_entre_margens = (int*) malloc(d* sizeof(int));

    for(j=1; j < d; j++)
    {
        distancia_entre_margens[j] = 0;
    }
}

int maxima_distancia( int t)
{
    int i,n,j,d,tmp, m=0, n_simples=0, cont=0, maior_distancia=0;

    char entrada[4];


        printf("\n> TESTE %2d\n    Numero de pedras:                           ", t);
        scanf("%d",&n);
        printf("    Distancia entre as margens:                 ");
        scanf("%d",&d);

        aloca_distancia(d+1);



        for(j = 0; j < n; j++)
        {
            printf("    Pedra %d [<B/S>-<Distancia ate a margem>]:   ", j+1);
            fflush(stdin);
            scanf("%s", entrada);

            if ((entrada[0] == 'B') || (entrada[0] == 'b'))
            {
                tmp = atoi(&entrada[2]);

                distancia_entre_margens[tmp] = 1;
            }
            else
            {

                tmp = atoi(&entrada[2]);
                distancia_entre_margens[tmp] = 2;
                n_simples= n_simples +1;

            }

        }




        for(j=1; j <= d; j++)
        {
            if (distancia_entre_margens[j] != 1)
            {
                m = m + 1;

                if(maior_distancia<m)
                    maior_distancia = m;
            }

            else
            {
                m = 0;
            }

        }


    return maior_distancia;

}

