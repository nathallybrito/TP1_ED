#include "stack.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename S>
No<S>::No(S n){
    this -> data =n;
    this -> link= NULL;

}

template <typename S>
Stack<S>::Stack() {
    top=NULL;
    
}

template <typename S>
Stack<S>::~Stack() {
    while(!isEmpty()){
            pop();

    }
}

template <typename S>
void Stack<S>::push(S data) {
    No<S>* temp = new No<S>(data); //cria o nó temo que aloca memoria na heap
    if(!temp){
        cout<<"A Pilha está cheia"<<endl;
        exit(1);
    }// checa se a pilha está cheia 
    temp-> data = data;// incializa o dado dento do temp
    temp->link=top;// aponta pra ponta do ponteiro
    top=temp;//make temp as top of stack
    
}

template <typename S>
 void Stack<S>::pop() {
    No<S>* temp;
    if(top==NULL){
        cout<< "A PILHA ESTÁ VAZIA"<<endl;
        exit(1);
    }
    else{
        temp = top; // coloca o dado na pilha
        top = top->link; // coloca o segundo no

            // This will automatically destroy
            // the link between first node and second node
 
            // Release memory of top node
            // i.e delete the node
        delete(temp);


    }
}


template <typename S>
void Stack<S>::display() { // função q impreme os elementos da pilha
    No<S>* temp;
 if (top==NULL){
      cout<<" A PILHA ESTA VAZIA " <<endl;
      exit(1);
    }
else{
    temp= top;
    while(temp != NULL){
        cout<< temp ->data;
        temp = temp ->link;
        if( temp != NULL)
            cout<<" ->";
    }
    }
    
}

template <typename S>
bool Stack<S>::isEmpty()const{ // ve se a pilha esta cheia ou não
    return top == NULL;
}

template <typename S>
S Stack<S>::topElement()const{ //  retorna o elemento do topo da pilha
    if(!isEmpty()){
        return top ->data;
    }
    else
        exit(1);
}
template class Stack <bool>;
template class Stack <char>;