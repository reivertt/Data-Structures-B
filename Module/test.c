#include <stdio.h>

void func(){
    printf("Riil");
}

void func3(){
    printf("fek");
}

void func2(void (*f)()){
    if (f == NULL) return;
    else if (*f == func) f();

}

int main(){
    func2(func3);
}