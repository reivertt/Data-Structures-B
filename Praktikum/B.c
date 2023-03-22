#include <stdio.h>
#include <string.h>
#define NL(i,n) (i == n-1 ? '\n' : ' ')

int main(){
    int N, Q;
    scanf("%d", &N);
    int A[N];
    
    for(int i = 0; i < N; i++){ 
        scanf("%d", &A[i]);
    }

    scanf("%d", &Q);
    while (Q--){
        int t, x;
        scanf("%d", &t);
        char OP[4];
        switch (t){
            case 1: 
                scanf("%s%d", OP, &x);
                switch (OP[0]){
                    case 'X': 
                        for (int j = 0; j < N; j++) A[j] ^= x; 
                    break;
                    case 'A': 
                        for (int j = 0; j < N; j++) A[j] &= x; 
                    break;
                    case 'O': 
                        for (int j = 0; j < N; j++) A[j] |= x; 
                    break;
                }
            break;

            case 2: 
                for (int j = 0; j < N; j++) printf("%d%c", A[j], NL(j, N));
            break;
        }
    }
}