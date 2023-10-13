//---------------------------------------------------------------------
// Arquivo	: arvore.cpp
// Conteudo	: implementação do TAD raiz
// Autor	: Náthally Fernandes (nathallyfernandes@ufmg.br)
// Historico	: 2022-04-01 - arquivo criado
//---------------------------------------------------------------------
#include <iostream>
#include <string>
#include "../include/arvore.hpp"
#include "../include/avaliador.hpp"


NO::NO(std:: string &item_){
    item= item_;
    esq= nullptr;
    dir= nullptr;
    valor= -1;
}


/*ArvoreBinaria::ArvoreBinaria( std::string &entrada,std::string &expressao_):raiz(nullptr),expressao(expressao_){
    raiz = constroi(entrada,0);
}*/

/*ArvoreBinaria::~ArvoreBinaria(){
    apagaRecursivo(raiz);
}*/

/*unsigned int ArvoreBinaria::encontraQuanti(std::string expressao, unsigned int index){
    unsigned int index_pos = index;
    bool found_e = false;
    
    while (index_pos < expressao.length() && (expressao[index_pos] != 'e' || found_e)) {
        if (expressao[index_pos] == 'e') {
            found_e = true;
        }
        index_pos++;
    }
    
    if (!found_e) {
        index_pos = index;
        while (index_pos < expressao.length() && expressao[index_pos] != 'a') {
            index_pos++;
        }
    }

    return index_pos;
}*/


NO *ArvoreBinaria::constroi(std::string &entrada,size_t index){
    NO *no = new NO(entrada);
    for(auto i= index; i < entrada.length(); i++){
        if(entrada[i] == 'e' || entrada[i]== 'a'){
            std:: string item_esq = entrada;
            item_esq[i]= '0';
            no->esq = constroi(item_esq,i + 1);

            std:: string item_dir = entrada;
            item_dir[i] = '1';
            no->dir = constroi(item_dir, i + 1);

                break;

        }
    }
    return no;
}


 std::string ArvoreBinaria::avalia(int start = 0){
    // std::cout << raiz->item << std::endl;
    avaliaRecursivo(raiz, expressao, start);
         if(raiz->valor == 0){
            return "0";
             }
    std::cout << raiz->item << std::endl;
    // std::cout << raiz->valor << std::endl;
    return "1 " + raiz->item;
 }

void ArvoreBinaria::avaliaRecursivo(NO*raiz ,std:: string &expressao, int index){
    if(raiz==nullptr) return;

    avaliaRecursivo(raiz->esq, expressao , index + 1 );
    avaliaRecursivo(raiz->dir, expressao , index + 1 );
    //std::cout<<raiz->valor <<std::endl;
    if(raiz->esq == nullptr && raiz->dir == nullptr){
        avaliaFolha(raiz);
        return;
    }
    const unsigned int str_size = raiz->item.length();
    

    if((raiz->esq->valor == 1) && (raiz->dir->valor == 1)){
        for(unsigned int i = 0; i < str_size; i++){
            if(raiz -> dir->item[i] != raiz->esq->item[i]){
            raiz->item[i] = 'a';
         }else{
            raiz->item[i]= raiz->esq->item[i];
            }
        }
        raiz->valor= 1;  
     } 
    else if  ( (raiz->esq->valor ) || (raiz->dir->valor)){
            unsigned int index_pos = index;
            while (index_pos < raiz->item.length() && raiz->item[index_pos] != 'e' && expressao[index_pos] != 'a' ) {
                index_pos++;
            }
            if (raiz->item[index_pos] == 'a'){
            raiz->valor = 0;
            return;  
        }
        std::string value;  
        if (raiz->dir->valor) value= raiz->dir->valor;
        else {value= raiz->esq->valor;}
        for(unsigned int i = index_pos; i<str_size; i++){
            if (raiz->item[i] == 'e'){
                raiz->item[i] = '1';
            }
        }
        raiz->item[index_pos] = '1';
        raiz->valor = 1;
    } 

  else {
    raiz->valor = 0;
    raiz->item[index] = '0';
  }
}
void ArvoreBinaria:: avaliaFolha(NO *no){   
    AvaliadorExpressaoLogica evaluator(expressao, no->item);
    //evaluator.avaliarEntrada(expressao, no->item);
    // std::cout << no->item << std::endl;
    no->valor = evaluator.avaliar(no->item);
    
    //  std::cout << no->valor << std::endl;
}

void ArvoreBinaria::apagaRecursivo( NO*no){
  if(no==nullptr) return;
  apagaRecursivo(no->esq);
  apagaRecursivo(no->dir);
  delete no;
}