/*
Auth : Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem : A data file contains registration information for six courses—CS20A, CS21A, CS29A, CS30A, \
CS35A, and CS36A. Each line of data consists of a seven-digit student registration number followed  \
by six (ordered) values, each of which is 0 or 1. A value of 1 indicates that the student is        \
registered for the corresponding course; 0 means the student is not. Thus, 1 0 1 0 1 1 means that   \
the student is registered for CS20A, CS29A, CS35A, and CS36A, but not for CS21A and CS30A. You may  \
assume that there are no more than 100 students and a registration number 0 ends the data. Write a  \
program to read the data and produce a class list for each course. Each list consists of the        \
registration numbers of those students taking the course.
*/

// This solution uses an additional code (2_12g.c) to generate input data (2_12i.txt) and prints the output to their respective txt files

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