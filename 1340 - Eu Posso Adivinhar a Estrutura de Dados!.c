#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipo_sacola {

 int elemento_fila[1001];
 int comeco_fila, final_fila;
 int elemento_pilha[1001];
 int indice_pilha;
 int nLp[1001];
 int iLp;

} tipo_sacola;

void in_fila ( int valor, tipo_sacola *dado ){
    dado->elemento_fila[ dado->final_fila++ ] = valor;
}

int rmv_fila ( tipo_sacola*dado ) {
    if ( dado->comeco_fila == dado->final_fila ) {
        return -10000000;
    }
    return dado->elemento_fila[ dado->comeco_fila++ ];
}

void in_pilha ( int valor, tipo_sacola *dado ){
    dado->elemento_pilha[ ++dado->indice_pilha ] = valor;
}

int remove_pilha ( tipo_sacola *dado ){
    if ( dado->indice_pilha <= 0 ) {
        return  -10000000;
    }
    return dado->elemento_pilha[ dado->indice_pilha-- ];
}

void in_lista_prioridade ( int valor, tipo_sacola *dado ){
    int indexador_auxiliar;
    indexador_auxiliar = ++dado->iLp;
    while ( indexador_auxiliar > 1 ) {
        if ( dado->nLp[ indexador_auxiliar/2 ] < valor ) {
            dado->nLp[ indexador_auxiliar ] = dado->nLp[ indexador_auxiliar/2 ];
            indexador_auxiliar=indexador_auxiliar/2;
        } else
            break;
    }
    dado->nLp[ indexador_auxiliar ] = valor;
}

int rmvLp ( tipo_sacola *dado ) {
    int temporario, atual, proximo;
    if ( dado->iLp <= 0 ) {
        return  -10000000;
    }

    temporario = dado->nLp[ 1 ];
    atual = 1;
    proximo = 2;
    dado->iLp --;
    while ( proximo <= dado->iLp ) {
        if ( proximo < dado->iLp && dado->nLp[ proximo+1 ] > dado->nLp[ proximo ] ) {
            proximo++;
        }
        if( dado->nLp[ proximo ] > dado->nLp[ dado->iLp+1 ] ) {
            dado->nLp[ atual ] = dado->nLp[ proximo ];
            atual = proximo;
            proximo = atual*2;
        } else
            break;
    }
    dado->nLp[ atual ] = dado->nLp[ dado->iLp+1 ];
    return temporario;
}

int main ( int argc, char *argv[] ) {
    int comando, valor;
    int n, i;
    int flag[ 3 ];
    int recebido;

    tipo_sacola data;

    while ( scanf ( "%d", &n ) != EOF ) {
        memset ( flag, 0, sizeof( flag ) );

        data.comeco_fila = 0;
        data.final_fila = 0;
        data.indice_pilha = 0;
        data.iLp = 0;

        for ( i=0; i<n; i++ ) {
            scanf( "%d %d", &comando, &valor );

            if ( comando == 1 ){
                in_fila ( valor, &data );
                in_pilha ( valor, &data );
                in_lista_prioridade ( valor, &data );
            }

            else {
                recebido = rmv_fila ( &data );

                if ( recebido != valor ) {
                    flag[0] = 1;
                }
                recebido = remove_pilha ( &data );
                if ( recebido != valor ) {
                    flag[1] = 1;
                }
                recebido = rmvLp ( &data );
                if ( recebido != valor ) {
                        flag[2] = 1;
                }
            }
        }

        if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] == 3 )
            printf ( "impossible\n" );

        else
            if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] < 2 )
                printf ( "not sure\n" );
       
        else {
            if ( !flag[0] ) printf ( "queue\n" );
            if ( !flag[1] ) printf ( "stack\n" );
            if ( !flag[2] ) printf ( "priority queue\n" );
        }
    }
    return 0;
}