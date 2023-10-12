//---------------------------------------------------------------------
// Arquivo	: avaliador.hpp
// Conteudo	: definicoes da classe usada para avaliar a expressão lógica.
// Autor	: Náthally Fernandes (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
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
    AvaliadorExpressaoLogica(const char* expression, const char* valuation);
    void avaliarEntrada( std::string& expression, std::string& valuation);
    bool  avaliar(const std:: string& expression);
    int precedencia(char op);
    void aplicarOperador();
    
   
     
private:
    std::string exp_;
    std::string valuation_;
    const char *expression ;
    const char *valuation;
    Stack<bool> valores_;
    Stack<char> operadores_;
    
    
};
//criar uma herança de Avaliador-- que vai ser uma árvore que vai utilizar os métodos

#endif
