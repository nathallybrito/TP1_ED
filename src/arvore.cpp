//---------------------------------------------------------------------
// Arquivo	: arvore.cpp
// Conteudo	: implementação do TAD raiz
// Autor	: Náthally Fernandes (nathallyfernandes@ufmg.br)
// Historico	: 2022-04-01 - arquivo criado
//---------------------------------------------------------------------
#include <iostream>
#include "../include/arvore.hpp"
#include "../include/avaliador.hpp"


NO::NO(std:: string &valor_){
    valor=valor_;
    esq=nullptr;
    dir=nullptr;
    item=-1;
}

ArvoreBinaria::ArvoreBinaria( std::string &entrada,std::string &expressao_):raiz(nullptr),expressao(expressao_){
    raiz= constroi(entrada,0);
}

ArvoreBinaria::~ArvoreBinaria(){
    apagaRecursivo(raiz);
}

unsigned int ArvoreBinaria::encontraQuanti(std::string expressao, unsigned int index){
    unsigned int index_pos=0;
    while (index_pos < expressao.length() && expressao[index_pos] != 'e' && expressao[index_pos] != 'a')
     {
    index_pos++;
     }

  return index_pos;
}

void ArvoreBinaria::funcoesAvaliador( std::string &expression, std::string &valuation){
    AvaliadorExpressaoLogica evaluator(expression,valuation);
    bool result=evaluator.avaliar(expression);

}

NO *ArvoreBinaria::constroi(std::string &entrada,size_t index){
    NO *no = new NO(entrada);
    for(auto i= index;i<entrada.length();i++){
        if(entrada[i]=='e' || entrada[i]=='a'){
            std:: string valor_esq = entrada;
            valor_esq[i]='0';
            no->esq = constroi(valor_esq,i+1);

               std:: string valor_dir = entrada;
               valor_dir[i]='1';
                no->dir = constroi(valor_dir,i+1);

                break;

        }
    }
    return no;
}


 std::string ArvoreBinaria::avalia(int start=0){
    avaliaRecursivo(raiz,expressao,start);

    if(raiz->item==0){
        return "0";
    }
    return "1 " + raiz->valor;
 }

void ArvoreBinaria::avaliaRecursivo(NO*raiz ,std:: string &expressao,int index){
    if(!raiz){
            return;
    }
    avaliaRecursivo(raiz->esq, expressao,index+1);
    avaliaRecursivo(raiz->dir,expressao,index+1);

    if(raiz->esq == nullptr && raiz->dir == nullptr){
        avaliaFolha(raiz);
        return;
    }
    const unsigned int str_size = raiz->valor.length();
    int esq_result= raiz->esq->item;
    int dir_result= raiz->dir->item;
    unsigned int index_pos= encontraQuanti(raiz->valor,index);
    
    const int resultado0 = 0;
    const int resultado1 = 1;

    if(esq_result == resultado1 && dir_result == esq_result){
        for(unsigned int i = 0;i<str_size;i++){
            if(raiz -> dir->valor[i] != raiz->esq->valor[i]){
            raiz->valor[i] = 'a';
         }else{
            raiz->valor[i]= raiz->dir->valor[i];
            }
        }
        raiz->item= resultado1;   
     } else if  ( esq_result || dir_result){
    if(raiz->valor[index_pos]== 'a'){
        raiz->item = resultado0;
        return;  
    }
    std::string valor = dir_result ? raiz->dir->valor : raiz->esq->valor;
    raiz->valor = valor;
    raiz->item = resultado1;
  } else {
    raiz->item = resultado0;
    raiz->valor[index] = '0';
  }
}
void ArvoreBinaria:: avaliaFolha(NO *no){
    AvaliadorExpressaoLogica *evaluator = new AvaliadorExpressaoLogica(expressao,valuation);
    no->item = evaluator->avaliar(no->valor);
}

void ArvoreBinaria::apagaRecursivo( NO*no){
  if(!no){
    return;
  }
  apagaRecursivo(no->esq);
  apagaRecursivo(no->dir);
  delete no;
}

