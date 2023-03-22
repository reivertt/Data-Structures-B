#include <stdio.h>
#include <string.h>

typedef struct poll{
    char name[50];
    int votes;
} ints;

void sorting(ints *temp, int n){
    ints temp2;
    for(int i = 0; i < 10 - 1; i++){
        for(int j = 0; j < 10 - 1 - i; j++){
            if (n == 1){
                if(temp[j].votes < temp[j+1].votes){
                    temp2 = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = temp2;
                }
                else if (temp[j].votes == temp[j+1].votes){
                    if(strcmp(temp[j].name, temp[j+1].name) > 0){
                        temp2 = temp[j];
                        temp[j] = temp[j+1];
                        temp[j+1] = temp2;
                    }
                }
            }
            else if (n == 0){
                if(strcmp(temp[j].name, temp[j+1].name) > 0){
                    temp2 = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = temp2;
                }
            }
        }
    }
}

int main(){
    ints user[10];
    int x = -1, j = 0;

    FILE *fp = fopen("1_1i.txt", "r");
    while(j < 10) {
        fscanf(fp, "\n%[^\n]%*c", user[j].name);
        user[j].votes = 0;
        j++;
    }
    fclose(fp);

    sorting(user, 0);

    while(x != 0){
        printf("Vote for your favorite candidate!\n");
        for(int i = 0; i < 10; i++) {
            printf("%-2d. %-25s%3d\n", i+1, user[i].name, user[i].votes);
        }
        printf("Enter your vote: ");
        scanf("%d", &x);
        if(x > 0 && x <= 10) user[x-1].votes += 1;
    }

    sorting(user, 1);

    FILE *fp2 = fopen("1_1o.txt", "w");
    j = 0;
    while(j < 10) {
        fprintf(fp2, "%-25s%3d\n", user[j].name, user[j].votes);
        j++;
    }
    fclose(fp2);
}