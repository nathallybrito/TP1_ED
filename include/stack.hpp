#ifndef STACK_H
#define STACK_H

template<typename S>
//cria o nó encadeado para a lista
class No{ 
public:
No( S n);// construtor;
  S data;
  No* link;
};

template <typename S>
class Stack :{
  private:
     No<S>* top;

  public:
    Stack();
    ~Stack();

    void push(S data);
    void pop();
    void display();
    bool isEmpty()const;
    S topElement() const;
};
class ArvoreBinaria: public Stack { // Insere e limpa pode reaproveitar talvez
  public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    //void Insere( char item);
    void Caminha( int tipo);
    void limpa();
  private:
    void InsereRecursivo (charNo* &p, char item);
    void ApagaRecursivo(charNo* p);
    void PorNivel();
    void PreOrdem(charNo* p);
    void InOrdem(charNo* p);
    void PosOrdem(charNo* p);
    charNo* raiz;
  
}

#endif
