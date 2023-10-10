//---------------------------------------------------------------------
// Arquivo	: arvore.hpp
// Conteudo	: definicoes do TAD ARVORE 
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>

class arvoreNo{
    public:
        char No(){
          item.SetChave(-1);
          esq = NULL;
          dir = NULL;
        };
    private:
        char Item item;
        cha rNo *esq;
        charNo *dir;
        friend class ArvoreBinaria;
};

class ArvoreBinaria{
  public:
    ArvoreBinaria(){
    raiz= NULL;
    }
    ~ArvoreBinaria(){
    Limpa();
    }
    void Insere(char item){
    InsereRecursivo( raiz,item);
    }
    void Caminha(int tipo);
    void Limpa();
  private:
    void InsereRecursivo (charNo* &p, char item){
      if(p==NULL){
      P= new CharNo();
      p-> item=item;
      }
    else{
      if(item.GetChave() < p->item.GetChave())
          InsereRecursivo(p->esq,item);
        else
          InsereRecursivo(p -> dir,item);
    }
    }
    void ApagaRecursivo(charNo* p);
    void PorNivel();
    void PreOrdem(CharNo *p);
    void InOrdem(charNo* p);
    void PosOrdem(charNo* p);
  }


#endif