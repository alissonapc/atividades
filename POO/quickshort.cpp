#include <iostream>
#include <vector>
#include <string>
#include <locale>

bool compararNomes(const std::string& a, const std::string& b, const std::locale& loc) {
    const auto& collate = std::use_facet<std::collate<char>>(loc);
    // compare retorna < 0 se 'a' for menor que 'b'
    return collate.compare(a.data(), a.data() + a.size(), 
                           b.data(), b.data() + b.size()) <= 0;
}


void trocar(std::string& a, std::string& b) {
    std::string temp = a;
    a = b;
    b = temp;
}

