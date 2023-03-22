#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    float income, expense, net;
}stall;

void sorting(stall data[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(data[j].net < data[j+1].net){
                stall temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
            else if(data[j].net == data[j+1].net){
                if(strcmp(data[j].name, data[j+1].name) > 0){
                    stall temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
    }
}

int main(){
    FILE *fp = fopen("2_11i.txt", "r+");
    FILE *fp2 = fopen("2_11o.txt", "w+");
    int count = 0, total = 0;;
    stall stall[100];

    for(int i = 0; i < 100; i++){
        fscanf(fp, "%s %f %f", stall[i].name, &stall[i].income, &stall[i].expense);
        if (!strcmp(stall[i].name, "xxxxxx")) break;
        stall[i].net = stall[i].income - stall[i].expense;
        total += stall[i].net;
        count += 1;
    }

    sorting(stall, count);
    
    fprintf(fp2, "================ Report ================\n");
    fprintf(fp2, "Rankings\n");
    for(int i = 0; i < count; i++){
        fprintf(fp2, "%3d.%s\t%.2f\n", i+1, stall[i].name, stall[i].net);
    }
    fprintf(fp2, "\nTotal: \t\t%d\n", total);
    fprintf(fp2, "========================================\n");
}