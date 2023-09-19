#ifndef AVALIADOR_H
#define AVALIADOR_H
#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>


using namespace std;

class AvaliadorExpressaoLogica{
public:
    AvaliadorExpressaoLogica(const string& expression, const string& valuation) : expression_(expression),valuation_(valuation){};

    bool avaliar(){};
    int precedencia (char op){};
    void aplicarOperador(){};


private:
    string valuation_;
    string expression_;
    stack<bool> valores_;
    stack<char> operadores_;
    size_t index_;// índice para percorrer a string de valoração 
   
};

#endif
