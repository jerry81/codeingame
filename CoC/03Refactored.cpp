#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

int main() {
    std::unordered_map<std::string, std::string> lookup = {
        { ":slight_smile:", ":)" },
        { ":disappointed:", ":(" },
        { ":loud_laugh:", "XD" },
        { ":open_mouth:", ":o" },
        { ":stuck_out_tongue:", ":p" }
    };

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> spl = split(input, " ");
    std::string news;
    bool init = false;
    for (const std::string& s : spl) {
        if (lookup.find(s) != lookup.end()) {
            if (init) {
                news += " ";
            }
            init = true;
            news += lookup[s];
        } else {
            if (init) {
                news += " ";
            }
            init = true;
            news += s;
        }
    }
    std::cout << news << std::endl;

    return 0;
}

/*

Refactoring steps:

Added necessary headers and changed the return type of split() to std::vector<std::string>.
Updated the split() function to use std::string and std::vector<std::string>.
Declared and initialized the lookup unordered map with key-value pairs.
Moved the declaration of lookup inside the main() function.
Renamed the string type to std::string for consistency.
Replaced getline(cin, s) with std::getline(std::cin, input).
Removed the str.data() usage in strtok() since it is unnecessary in C++.
Replaced the use of nullptr with NULL in strtok() with the std::string approach.
Used range-based for loop to iterate over the split tokens.
Changed the condition from !lookup[s].empty() to lookup.find(s) != lookup.end() to check if the token exists in the lookup map.
Replaced cout with std::cout and endl with std::endl.
Added return 0; at the end of main().

*/