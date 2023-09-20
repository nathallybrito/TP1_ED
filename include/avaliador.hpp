#ifndef AVALIADOR_H
#define AVALIADOR_H
#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>

class AvaliadorExpressaoLogica {
public:
    AvaliadorExpressaoLogica(const std::string& expression, const std::string& valuation);
    
    bool avaliar();
    int precedencia(char op);
    void aplicarOperador();
     
private:
    std::string expression_;
    std::string valuation_;
    std::stack<bool> valores_;
    std::stack<char> operadores_;
    size_t index_; // Índice para percorrer a string de valoração

    
};

#endif
