#include <iostream>
#include <string>
#include <stdexcept>

#include "avaliador.hpp"

AvaliadorExpressaoLogica::AvaliadorExpressaoLogica(const std::string& expression, const std::string& valuation) 
    : expression_(expression), valuation_(valuation) {};

   bool AvaliadorExpressaoLogica:: avaliar() {
        for (char c : expression_) {
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
            } else if (std::isdigit(c)) { // Variáveis representadas por inteiros
                int variableIndex = c - '0'; // Converte o caractere para índice da variável
                bool variableValue = valuation_[variableIndex] == '1';
                valores_.push(variableValue);
            } else {
                throw std::invalid_argument("Caractere inválido na expressão: " + std::string(1, c));
            }
        }

        while (!operadores_.isEmpty()) {
            aplicarOperador();
        }

        /*if (valores_.size() != 1) {
            throw std::runtime_error("Expressão mal formada.");
        }*/

        return valores_.topElement();
    }

    int AvaliadorExpressaoLogica:: precedencia(char op) {
        if (op == '(' || op == ')') return 1;
        if (op == '~') return 2;
        if (op == '&') return 3;
        if (op == '|') return 4;
        return -1; // Operador inválido
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
    };
    

   
