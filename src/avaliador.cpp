//---------------------------------------------------------------------
// Arquivo	: avaliador.cpp
// Conteudo	: implementação da classe "avalidor.hpp"
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdexcept>
#include "avaliador.hpp"

AvaliadorExpressaoLogica::AvaliadorExpressaoLogica ( std::string& expression, std::string& valuation) 
: exp_(expression), valuation_(valuation) {};

std::string  AvaliadorExpressaoLogica:: avaliarEntrada ( std::string& expression, std::string& valuation){
    unsigned valuationIndex = 0; // Inicializa o índice de valuation como 0

        for (unsigned i = 0; i < expression.size(); i++) {
        char ch = expression[i];

        if (ch != '|' && ch != '&' && ch != '~' && ch != '(' && ch != ')' && ch != ' ') {
            // Verifica se o valuationIndex está dentro dos limites da valuation string
            if (valuationIndex < valuation.size()) {
                expression[i] = valuation[valuationIndex++]; // Atribui o valor de valuation e incrementa o índice
                }
            }
        }
    return expression;
    } 

   bool AvaliadorExpressaoLogica:: avaliar(const std:: string& expression){ 
       {
        for (unsigned int i = 0; i<expression.size(); ++i){
            char c = expression[i];

            if (c == ' ') {
                continue; // Ignora espaços em branco
            } else if (c == '0') {
                valores_.push(false);
            } else if (c == '1') {
                valores_.push(true);
            } else if (c == '~' || c == '∼') { // Operador de negação
                operadores_.push('~');
            } else if (c == '(') {
                operadores_.push(c);
            } else if (c == ')') {
                while (!operadores_.isEmpty() && operadores_.topElement() != '(') {
                    aplicarOperador();
                }

                if (!operadores_.isEmpty() && operadores_.topElement() == '(') {
                    operadores_.pop();
                } else {
                    throw std::runtime_error("Parênteses desbalanceados.");
                }
            } else if (c == '&' || c == '|') { // Operadores lógicos
                while (!operadores_.isEmpty() && precedencia(c) <= precedencia(operadores_.topElement())) {
                    aplicarOperador();
                }

                operadores_.push(c);
            } else if (std::isdigit(c)) {//coloca na pilha o valor da variável
                valores_.push(c=='1');
            } else {
                throw std::invalid_argument("Caractere inválido na expressão: " + std::string(1, c));
            } 
        }

        while (!operadores_.isEmpty()) {
            aplicarOperador();
        } 

        return valores_.topElement();
         }
    } 
   
    int AvaliadorExpressaoLogica:: precedencia(char op) {
        if (op == '~') {
            return 3;
        } else if (op == '&') {
            return 2;
        } else if (op == '|') {
            return 1;
        } else {
            return 0;
        }
    }


    void  AvaliadorExpressaoLogica:: aplicarOperador() {
        char op = operadores_.topElement();
        operadores_.pop();

        if (op == '~') { // Operador de negação
            bool operand = valores_.topElement();
            valores_.pop();
            valores_.push(!operand);
        } else { // Operadores lógicos
            bool operand2 = valores_.topElement();
            valores_.pop();
            bool operand1 = valores_.topElement();
            valores_.pop();

            if (op == '&') {
                valores_.push(operand1 && operand2);
            } else if (op == '|') {
                valores_.push(operand1 || operand2);
            }
        }
    }


   