//---------------------------------------------------------------------
// Arquivo	: stack.hpp
// Conteudo	: definicoes do TAD PILHA
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef STACK_H
#define STACK_H

template<typename S>
// Descricao:  Construtor da classe No que cria um nó com um dado n.
// Entrada: Recebe um valor 'n' do tipo 's' que será armazenado no nó.
// Saida: Constrói um nó com o valor n e define seu link como nulo.
class No{ 
public:
No( S n);// construtor da classe;
  S data;
  No* link;
};

template <typename S>
class Stack{
  private:
     No<S>* top;

  public:
  // Descricao: Construtor da classe 'Stack' que inicializa a pilha vazia.
  // Entrada: Não tem entrada explicita.
  // Saida: Inicializa uma pilha vazia (define 'top' como nulo).
    Stack();


  // Descricao: Destrutor da classe 'Stack' que libera a memoria de todos os nós da pilha.
  // Entrada: Não tem entrada explicita.
  // Saida: Libera a memoria de todos os nós da pilha.
    ~Stack();


  // Descricao:Adiciona um elemento à pilha.
  // Entrada: Recebe um valor data do tipo S que deve ser adicionado à pilha.
  // Saida: Adiciona o elemento data ao topo da pilha.
    void push(S data);


  // Descricao: Remove o elemento do topo da pilha.
  // Entrada: Não tem entrada explícita.
  // Saida: Remove o elemento no topo da pilha.
    void pop();


  // Descricao: Exibe os elementos da pilha.
  // Entrada: Não tem entrada explícita.
  // Saida: Exibe os elementos da pilha na ordem em que foram empilhados.
  // Por exemplo, se a pilha contém os elementos 1, 2 e 3, a saída será "1 -> 2 -> 3".
    void display();


  // Descricao:Verifica se a pilha esta vazia.
  // Entrada: Não tem entrada explicita
  // Saida: Retorna true se a pilha estiver vazia e false caso contrário.
    bool isEmpty()const;


  // Descricao:Retorna o elemento no topo da pilha.
  // Entrada: Não tem entrada explicita
  // Saida: Retorna o elemento no topo da pilha (o valor do tipo S armazenado no nó do topo)
  // Se a pilha estiver vazia, pode gerar uma exceção ou encerrar o programa (dependendo da implementação).
    S topElement() const;
};

#endif
