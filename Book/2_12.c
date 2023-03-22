#include <stdio.h>
#include <string.h>

typedef struct {
    char s_nrp[11];
    int num_choice[7];
}input;

typedef struct {
    char s_nrp[101][11];
    int count;
}course;

int main(){
    FILE *fp = fopen("2_12i.txt", "r");
    char s_links[6][20] = {"2_12_CS20A.txt", "2_12_CS21A.txt", "2_12_CS29A.txt", "2_12_CS30A.txt", "2_12_CS35A.txt", "2_12_CS36A.txt"};
    input input[101];
    course course[7];
    for(int y = 0; y < 6; y++) course[y].count = 0;
    for(int i = 0; i > -1; i++){
        fscanf(fp, "%s", input[i].s_nrp);
        if (!strcmp(input[i].s_nrp, "0")) break;
        for(int j = 0; j < 6; j++){
            fscanf(fp, "%d", &input[i].num_choice[j]);
            if(input[i].num_choice[j]) strcpy(course[j].s_nrp[course[j].count++], input[i].s_nrp);
        }
    }
    for(int k = 0; k < 6; k++){
        FILE *fp = fopen(s_links[k], "w");
        fprintf(fp, "Computer Science Class, %d Students\n", course[k].count);
        for(int l = 0; l < course[k].count; l++){
            fprintf(fp, "- %s\n", course[k].s_nrp[l]);
        }
        fclose(fp);
    }
}