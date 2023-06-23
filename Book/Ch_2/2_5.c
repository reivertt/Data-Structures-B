/*
Auth : Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem: Write a function that, given two date structures, d1 and d2, returns -1 if d1 comes before d2, \
0 if d1 is the same as d2, and 1 if d1 comes after d2.
*/

#include <stdio.h>

typedef struct {
    int day, month, year;
}date;

int compare(date first, date second){
    if (first.year > second.year) return 1;
    else if (first.year < second.year) return -1;
    else {
        if (first.month > second.month) return 1;
        else if (first.month < second.month) return -1;
        else {
            if (first.day > second.day) return 1;
            else if (first.day < second.day) return -1;
            else return 0;
        }
    }
}

int main(){
    date d1, d2;
    int selisih;
    printf("Input date #1 (dd mm yyyy): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
    printf("Input date #2 (dd mm yyyy): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);
    // year -> month -> day
    int ans = compare(d1,d2);
    if (!ans) printf("same day");
    else if (ans == 1) printf("later");
    else printf("earlier");
}