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

    //Descrição: Construtor da classe AvaliadorExpressaoLogica.
    //Entrada: Recebe duas referências para strings, expression e valuation.
    //Saída: Inicializa a classe AvaliadorExpressaoLogica.
    AvaliadorExpressaoLogica (std::string& expression, std::string& valuation);


    //Descrição: Este método avalia a entrada da expressão com base
    // na valuation (string s) fornecida, substituindo os valores
    // na expressão pela valuation(string p).
    //Entrada: Recebe duas referências para strings, expression e valuation.
    //Saída: Retorna a expressão com os valores substituídos.
    std::string avaliarEntrada ( std::string& expression, std::string& valuation);

    //Descrição: Este método avalia a expressão lógica e retorna o resultado da avaliação.
    //Entrada: Recebe uma string expression que representa a expressão lógica a ser avaliada.
    //Saída: Retorna true se a expressão for verdadeira e false se for falsa.
    bool avaliar (const std:: string& expression);


    //Descrição: Este método determina a precedência de operadores lógicos.
    //Entrada: Recebe um caractere op que representa o operador lógico.
    //Saída: Retorna um valor inteiro representando a precedência do operador.
    int precedencia (char op);

    //Descrição: Este método aplica um operador à pilha de valores durante a avaliação da expressão.
    //Entrada: Não possui entrada explícita.
    //Saída: Realiza as operações necessárias com base no operador.
    void aplicarOperador();
    
   
     
private:
    std::string exp_;
    std::string valuation_;
    Stack<bool> valores_; // declara o tipo de pilha utilizada.
    Stack<char> operadores_;
    
    
};


#endif
