#include <stdio.h>

int main(){
    int n, present = 0, absent = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        (arr[i]) ? present++ : absent++;
    }
    printf("%d %d", present, absent);
}