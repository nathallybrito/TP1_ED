//---------------------------------------------------------------------
// Arquivo	: arvore.hpp
// Conteudo	: definicoes do TAD ARVORE 
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>
#include <string>

struct NO{
        std::string item; // expressão
        NO *esq;
        NO *dir;
        int valor;//boolean result ;
        NO(std::string &valor_);
          
    };    
      

class ArvoreBinaria{
  public:
    //ArvoreBinaria( std:: string &entrada,std::string &expressao_);
    //~ArvoreBinaria();
    NO *constroi(std::string &entrada,size_t index);
    unsigned int encontraQuanti(std::string expression,unsigned int index);
    std::string avalia(int start);
    void avaliaRecursivo (NO *arvore,std:: string &genericStr,int index);
    void apagaRecursivo(NO *no);
    void avaliaFolha(NO *no);
     NO* raiz;

  

      
      std::string expressao;
      std::string valuation;
};


#endif
