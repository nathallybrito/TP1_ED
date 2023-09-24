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
class Stack {
private:
     No<S>* top;

public:
    Stack();
    //~Stack();

    void push(S data);
    void pop();
    void display();
    bool isEmpty() const;
    S topElement() const;
};

#endif
