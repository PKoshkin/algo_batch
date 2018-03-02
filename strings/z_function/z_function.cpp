#include "z_function.h"


void build_z_function(std::vector<int>& z_function, const std::string& string) {
    int length = string.size();
    z_function.resize(length);
    if (length == 0) {
        return;
    }
    int left = 0;
    int right = 1;
    z_function[0] = length;
    for (int current = 1; current < length; ++current) {
        if (right < current) {
            int counter = 0;
            while (
                (string[current + counter] == string[counter]) &&
                (current + counter < length)
            ) {
                ++counter;
            }
            z_function[current] = counter;
            left = current;
            right = current + counter;
        } else {
            int equivalent = current - left;
            if (right < current + z_function[equivalent]) {
                z_function[current] = z_function[equivalent];
            } else {
                int counter = 0;
                while (
                    (string[right + counter] == string[right - current + counter]) &&
                    (right + counter < length)
                ) {
                    ++counter;
                }
                z_function[current] = right - current + counter;
                left = current;
                right = right + counter;
            }
        }
    }
}


std::vector<int> find(const std::string& str_where_to_find, const std::string& str_to_find) {
    std::vector<int> result;
    std::vector<int> z_function;
    if (str_to_find.size() > str_where_to_find.size()) {
        return result;
    }
    std::string z_function_str = str_to_find + '$' + str_where_to_find;
    build_z_function(z_function, z_function_str);
    for (int i = 0; i < z_function.size(); ++i) {
        if (z_function[i] == str_to_find.size()) {
            result.push_back(i - str_to_find.size() - 1);
        }
    }
    return result;
}
