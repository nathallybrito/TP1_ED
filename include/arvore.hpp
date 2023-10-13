//---------------------------------------------------------------------
// Arquivo	: arvore.hpp
// Conteudo	: definicoes do TAD ARVORE 
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>
#include <string>

// Struct que representa um nó da árvore.
struct NO{

        std::string item;  // conteudo do no
        NO *esq;           // Filho  esquerdo 
        NO *dir;           // Filho direito
        int valor;         // valor associado ao nó
        NO(std::string &valor_);  
          
       };    


//Classe que representa um árvore binária.
class ArvoreBinaria{
  public:
   // Descricao:Construtor da classe ArvoreBinaria.
   // Entrada: Recebe uma referência para strings 'entrada' e expressao_'
   // Saida: Inicializa a árvore com base na entrada e expressao fornecida.
     ArvoreBinaria( std:: string &entrada,std::string &expressao_);


   // Descricao:Destrutor da classe ArvoreBinaria.
   // Entrada:Não tem entrada específica.
   // Saida:Desaloca a memória utilizada pela arvore;
     ~ArvoreBinaria();
     std::string expressao;// expressão lógica associada a árvore


   // Descricao: Verifica se a pilha esta vazia.
   //Entrada: Recebe uma referência para a string entrada e um índice index.
   // Saida: Constrói a árvore recursivamente a partir da entrada e retorna um ponteiro para o nó raiz.
     NO *constroi(std::string &entrada,size_t index);


   // Descricao:Construir a árvore a partir de uma string de entrada
   // Entrada:Aceita um parâmetro inteiro start (com um valor padrão de 0).
   // Saida: Avalia a árvore com base na expressão lógica e retorna uma string que representa o resultado da avaliação.
     std::string avalia(int start);
     NO* raiz; // Raiz da árvore

  private:
   // Descricao:Método para avaliar a árvore de forma recursiva
   // Entrada: Recebe um ponteiro para o nó raiz, uma referência para uma string expressao e um índice index.
   // Saida: Avalia a árvore de forma recursiva com base na expressão lógica.
     void avaliaRecursivo (NO *arvore,std:: string &expressao,int index);

    // Descricao: Método para apagar a árvore de forma recursiva
    // Entrada: Recebe um ponteiro para um nó no.
    // Saida: Remove recursivamente os nós da árvore e libera a memória.
     void apagaRecursivo(NO *no);


    // Descricao: Método para avaliar uma folha de uma árvore
    // Entrada: Recebe um ponteiro para um nó
    // Saida: Avalia uma folha da árvore com base na expressão lógica e atualiza o valor do nó.
     void avaliaFolha(NO *no);
     
};


#endif
