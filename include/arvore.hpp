//---------------------------------------------------------------------
// Arquivo	: arvore.hpp
// Conteudo	: definicoes do TAD ARVORE 
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>
#include <string>
#include "avaliador.hpp"

struct NO{
        std::string valor;
        NO *esq;
        NO *dir;
        int item ;
        NO(std::string &valor_);
          
};    
      

class ArvoreBinaria{
  public:
    ArvoreBinaria( char &valuation,std::string &expression);
    ~ArvoreBinaria();
    NO *constroi(std::string &expression,unsigned int valuationIndex);
    void avaliaRecursivo (NO *arvore,std:: string &expression_,int index);
    void apagaRecursivo(NO *no);
    void avaliaFolha();
  private:

      NO* arvore;
      std::string expression_;
};


#endif