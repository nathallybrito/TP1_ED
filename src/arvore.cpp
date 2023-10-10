//---------------------------------------------------------------------
// Arquivo	: arvore.cpp
// Conteudo	: implementação do TAD ARVORE
// Autor	: Náthally Fernandes (nathallyfernandes@ufmg.br)
// Historico	: 2022-04-01 - arquivo criado
//---------------------------------------------------------------------
#include <iostream>
#include "arvore.hpp"
#include "avaliador.hpp"

NO::NO(std:: string &valor_){
    valor=valor_;
    esq=nullptr;
    dir=nullptr;
    item=-1;
}

ArvoreBinaria::ArvoreBinaria( char &valuation,std::string &expression):arvore(nullptr),expression_(exp){
    arvore = constroi(expression,0);
}

ArvoreBinaria::~ArvoreBinaria(){
    apagaRecursivo->arvore;
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
 /*std::string ArvoreBinaria::avaliaRecursivo(int start=0){
    avaliaRecursivo(arvore,expression,start);

    if(arvore->item==0){
        return "0";
    }
    return"1" + arvore->valor
 }*/

void ArvoreBinaria::avaliaRecursivo(NO*arvore,std:: string &expression_,int index){
    if(!arvore){
            return;
    }
    avaliaRecursivo(arvore->esq, expression_,index+1);
    avaliaRecursivo(arvore->dir,expression_,index+1);

    if(arvore->esq == nullptr && arvore->dir == nullptr){
        avaliaRecursivo(arvore);
        return;
    }
    const unsigned int str_size = arvore->valor.lenght();
    int esq_result= arvore->esq->item;
    int dir_result= arvore->dir->item;
    unsigned int valuationINDEX= avaliarEntrada(arvore->valor_,index);
    
    const int resultado0 = 0;
    const int resultado1 = 1;

    if(esq_result == resultado1 && dir_result == esq_result){
        for(unsigned int i = 0;i<str_size;i++){
            if(arvore->valor[i] = 'a');
        }
        else 
        {
            arvore->valor[i]= arvore->dir->valor[i];
        }
    }
    arvore->item= resultado1;
} else if( esq_result || dir_result){
    if(arvore->valor[valuationIndex]== 'a'){
        
    }
}

