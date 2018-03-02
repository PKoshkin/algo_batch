#include <iostream>
#include <vector>
#include "z_function.h"

int main() {
    std::vector<int> result = find("abacababa", "aba");
    std::vector<int> right_result = {0, 4, 6};
    std::cout << ((result == right_result) ? "True" : "False") << std::endl;
    return 0;
}
