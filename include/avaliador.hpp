#ifndef AVALIADOR_H
#define AVALIADOR_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "stack.hpp"

class AvaliadorExpressaoLogica {
public:
    AvaliadorExpressaoLogica( std::string& expression,  std::string& valuation);
    void avaliarEntrada( std::string& expression, std::string& valuation);
    bool avaliar();
    int precedencia(char op);
    void aplicarOperador();
     
private:
    std::string expression_;
    std::string valuation_;
    Stack<bool> valores_;
    Stack<char> operadores_;
    
    
};
//criar uma herança de Avaliador-- que vai ser uma árvore que vai utilizar os métodos

#endif
