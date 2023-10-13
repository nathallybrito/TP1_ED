//---------------------------------------------------------------------
// Arquivo    : stack.cpp
// Conteudo   : implementação do TAD PILHA
// Autor      : Náthally Fernandes (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------

#include "stack.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename S>
No<S>::No(S n) {
    this->data = n;
    this->link = NULL;
}

template <typename S>
Stack<S>::Stack() {
    top = NULL;
}

template <typename S>
Stack<S>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename S>
void Stack<S>::push(S data) {
    No<S>* temp = new No<S>(data); // Cria um novo nó que aloca memória na heap
    if (!temp) {
        cout << "A Pilha está cheia" << endl;
        exit(1);
    }
    temp->data = data;  // Inicializa o dado dentro do nó temp
    temp->link = top;   // Aponta para o topo da pilha anterior
    top = temp;         // Define o temp como o novo topo da pilha
}

template <typename S>
void Stack<S>::pop() {
    No<S>* temp;
    if (top == NULL) {
        cout << "A PILHA ESTÁ VAZIA" << endl;
        exit(1);
    } else {
        temp = top;       // Armazena o nó do topo da pilha
        top = top->link;  // Atualiza o topo da pilha para o próximo nó
        delete(temp);     // Libera a memória do nó removido
    }
}

template <typename S>
void Stack<S>::display() {
    No<S>* temp;
    if (top == NULL) {
        cout << "A PILHA ESTÁ VAZIA" << endl;
        exit(1);
    } else {
        temp = top;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->link;
            if (temp != NULL) {
                cout << " -> ";
            }
        }
    }
}

template <typename S>
bool Stack<S>::isEmpty() const {
    return top == NULL; // Retorna verdadeiro se a pilha estiver vazia
}

template <typename S>
S Stack<S>::topElement() const {
    if (!isEmpty()) {
        return top->data;  // Retorna o elemento no topo da pilha
    } else {
        exit(1);
    }
}

template class Stack<bool>;  // Instanciar a classe Stack com tipos bool e char.
template class Stack<char>;
