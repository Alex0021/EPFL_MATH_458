#include <iostream>

int main(int argc, char* argv[]) 
{
    std::cout << "CHAPTER 2 - EXERCISE 3" << std::endl;

    int i=0;
    int num=0;
    int sum=0;
    do {
        std::cout << "Enter number " << i+1 << ": ";
        std::cin >> num;
        if (num == -2) {
            std::cout << "Resetting sum to 0" << std::endl;
            i=0;
            sum=0;
            num=0;
        }
        else if (num > 0) {
            sum += num;
            i++;
        }
    } while (num >= 0 && sum <= 100);
    if (sum > 100) {
        std::cout << "Sum exceeded 100" << std::endl;
    } else {
        std::cout << "Sum of all numbers: " << sum << std::endl;
    }

    return 0;
}