#include <iostream>
#include <time.h>

int randd(int a, int b){
    int offset = rand() / (RAND_MAX + 1.0) * (b - a + 1);
    return a + offset;
}

int main(int argc, char const *argv[]){
    srand(time(0));
    int tot = 0;
    for (int i = 0; i < 20; i++){
        printf("=====   Game %d   =====\n", i+1);
        int dice = randd(1, 6); dice += randd(1, 6);
        std::cout << "rolls " << dice << std::endl;
        if (dice % 2 != 0) {
            tot -= 5; 
            std::cout << "//loses $5" << std::endl;
            continue;
        }

        std::cout << "lucky roll, cmon cmon" << std::endl;

        int deck = randd(1,52) % 13;
        std::cout << "draws a " << deck << std::endl;
        if ((deck < 10) && (deck % 2 != 0)) {
            tot += deck + 5;
            std::cout << "//wins $" << deck + 5 << std::endl;
        }
        else {
            tot -= 5;
            std::cout << "//loses $5" << std::endl;
        }
    }
    float avg = (float)tot / 20.00;
    if (tot > 0) std::cout << "LUCKYYY!! ";
    else std::cout <<"Gambling is bad for you kids, ";
    std::cout << "he got a total of " << tot << " dollars with an average of " << avg << " dolars per run" << std::endl;
    return 0;
}
