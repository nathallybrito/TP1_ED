//---------------------------------------------------------------------
// Arquivo	: arvore.cpp
// Conteudo	: implementação do TAD ARVORE
// Autor	: Náthally Fernandes (nathallyfernandes@ufmg.br)
// Historico	: 2022-04-01 - arquivo criado
//---------------------------------------------------------------------
#include <iostream>
#include "arvore.hpp"

NO::NO(std:: string &valor_){
    valor=valor_;
    esq=nullptr;
    dir=nullptr;
    item=-1;
}

ArvoreBinaria::ArvoreBinaria( char &valuation,std::string &expression){
    arvore=nullptr;
    arvore = constroi(expression,0);
}

ArvoreBinaria::~ArvoreBinaria(){
    apagaRecursivo->root;
}

NO *ArvoreBinaria::constroi(std::string &expression,unsigned int valuationIndex){
    NO *no = new NO(expression_);
    for(auto i= valuationIndex;i<expression_.lenght();i++){
        if(expression[i]=='e' || expression[i]=='a'){
            std:: string valor_esq = expression;
            valor_esq[i]='0';
            no->esq = constroi(valor_esq,i+1);

               std:: string valor_dir = expression;
               valor_dir[i]='1';
                no->dir = constroi(valor_dir,i+1);

                break;

        }
    }
    return no;
}
 std::string ArvoreBinaria::avaliaRecursivo (int start=0){
    avaliaRecursivo(arvore,expression,start);

    if(arvore->item==0){
        return "0";
    }
    return"1" + arvore->valor
 }

void ArvoreBinaria::avaliaRecursivo(NO*arvore,std:: string &expression_,int index){
    if(!arvore){
            return;
    }
    avaliaRecursivo(arvore->esq,expression_,index+1);
}