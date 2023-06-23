// A file to generate random input to 2_12i.txt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    FILE *fp = fopen("2_12i.txt", "w+");
    for(int i = 1; i <= 100; i++){
        fprintf(fp, "%s", "5025221");
        if (i < 10) fprintf(fp, "00");
        else if (i < 100) fprintf(fp, "0");
        fprintf(fp, "%d", i);
        for(int j = 0; j < 6; j++){
            fprintf(fp, " %d", rand() % 2);
        }
        fprintf(fp, "\n");
    }
}