#include <iostream>
#include <queue>
#include <stack>

typedef struct q{
    std::string NRP, Name;
}queue_t;

typedef struct s{
    std::string NRP, Name, Title;
    int Day, Month, Year;
}log_t;

void reversePrint(std::stack<log_t> stacc){
    if(stacc.empty()) return;

    log_t temp = stacc.top();
    stacc.pop();
    reversePrint(stacc);
    std::cout << "NRP           : " << temp.NRP << std::endl << "Name          : " << temp.Name << std::endl << "Book Title    : " << temp.Title \
              << std::endl << "Current Date  : " << temp.Day << " " << temp.Month << " " << temp.Year << std::endl;
    printf("--------------------------------------------------------\n");
}

int main(){
    std::queue<queue_t> Queue;  
    std::stack<log_t> Log;  
    while(1){
        printf("\n");
        int choice;
        std::cout << "Choose an operation!" << std::endl;
        std::cout << "1. Borrow a book\n2. Return a book\n3. Process queue\n4. Display queue\n9. Exit" << std::endl;
        std::cout << "\n";
        std::cin >> choice;
        std::cout << "\n";
        if (choice == 1) {
            log_t temp;
            std::cout << "~~ You are about to borrow a book ~~" << std::endl;
            std::cout << "NRP                       : "; std::cin >> temp.NRP;
            std::cout << "Name                      : "; std::getline(std::cin >> std::ws, temp.Name);
            std::cout << "Book Title                : "; std::getline(std::cin >> std::ws, temp.Title);
            std::cout << "Current Date (dd mm yyyy) : "; std::cin >> temp.Day >> temp.Month >> temp.Year;
            std::cout << "\nInputted data is as follows:" << std::endl << "NRP           : " << temp.NRP << std::endl << "Name          : " \
                      << temp.Name << std::endl << "Book Title    : " << temp.Title << std::endl << "Current Date  : " << temp.Day \
                      << " " << temp.Month << " " << temp.Year << std::endl << "Confirm Submission? (y/n) ";
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y') {
                Log.push(temp);
                std::cout << "Operation Success" << std::endl;
            }
            else std::cout << "Operation Cancelled" << std::endl;
        }
        else if (choice == 2) {
            queue_t temp;
            std::cout << "~~ You are about to return a book ~~" << std::endl;
            std::cout << "NRP   : "; std::cin >> temp.NRP;
            std::cout << "Name  : "; std::getline(std::cin >> std::ws, temp.Name);
            std::cout << "\nInputted data is as follows: " << std::endl << "NRP: " << temp.NRP << std::endl << "Name: " << temp.Name << std::endl \
                      << "Confirm Submission? (y/n) "; 
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y') Queue.push(temp);
            else std::cout << "Operation Cancelled" << std::endl;
        }
        else if (choice == 3) {
            //! if found
            //! if not found (also include if stack / queue empty)
            std::stack<log_t> temp;
            while(Queue.front().NRP.compare(Log.top().NRP)){
                temp.push(Log.top());
                Log.pop();
            }
            std::cout << "Data Found!" << std::endl << "NRP           : " << Log.top().NRP << std::endl << "Name          : " << Log.top().Name \
                      << std::endl << "Book Title    : " << Log.top().Title << std::endl << "Current Date  : " << Log.top().Day << " " \
                      << Log.top().Month << " " << Log.top().Year << std::endl;
            Log.pop();
            //! prob error here
            while(temp.empty()){
                Log.push(temp.top());
                temp.pop();
            }
        }
        else if (choice == 4) {
            reversePrint(Log);
        }
        else if (choice == 9) break;
    }
    return 0;
}