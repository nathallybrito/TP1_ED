//---------------------------------------------------------------------
// Arquivo    : arvore.cpp
// Conteudo   : implementação do TAD arvore
// Autor      : Náthally Fernandes (nathallyfernandes@ufmg.br)
// Historico  : 2022-04-01 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include "../include/arvore.hpp"
#include "../include/avaliador.hpp"

NO::NO(std::string &item_) {
    item = item_;   
    esq = nullptr;  
    dir = nullptr;  
    valor = -1;     
}

ArvoreBinaria::ArvoreBinaria(std::string &entrada, std::string &expressao_) : raiz(nullptr), expressao(expressao_) {
    raiz = constroi(entrada, 0);
}

ArvoreBinaria::~ArvoreBinaria() {
    apagaRecursivo(raiz);
}

NO* ArvoreBinaria::constroi(std::string &entrada, size_t index) {
    NO* no = new NO(entrada);

    for (auto i = index; i < entrada.length(); i++) {
        if (entrada[i] == 'e' || entrada[i] == 'a') {
            // Cria um nó esquerdo
            std::string item_esq = entrada;
            item_esq[i] = '0';
            no->esq = constroi(item_esq, i + 1);

            // Cria um nó direito
            std::string item_dir = entrada;
            item_dir[i] = '1';
            no->dir = constroi(item_dir, i + 1);

            break;
        }
    }
    return no;
}

void ArvoreBinaria::apagaRecursivo(NO* no) {
    if (no == nullptr) return;
    apagaRecursivo(no->esq);
    apagaRecursivo(no->dir);
    delete no;
}

std::string ArvoreBinaria::avalia(int start = 0) {
    avaliaRecursivo(raiz, expressao, start);

    // Verificação se o nó é igual a 0
    if (raiz->valor == 0) {
        return "0";
    }

    // Tira os caracteres desnecessários para a avaliação
    std::string input = raiz->item;
    std::string filtro = "";
    for (char c : input) {
        if (c == 'a' || c == 'e' || c == '0' || c == '1') {
            filtro += c;
        }
    }
    raiz->item = filtro;

    
    return "1 " + raiz->item;
}

void ArvoreBinaria::avaliaRecursivo(NO* raiz, std::string &expressao, int index) {
    if (raiz == nullptr) return;

    // Chamadas recursivas para os filhos esquerdo e direito
    avaliaRecursivo(raiz->esq, expressao, index + 1);
    avaliaRecursivo(raiz->dir, expressao, index + 1);

    if (raiz->esq == nullptr && raiz->dir == nullptr) {
        avaliaFolha(raiz);
        return;
    }

    bool esqValor = raiz->esq->valor;
    bool dirValor = raiz->dir->valor;

    if (esqValor && dirValor) {
        for (unsigned int i = 0; i < raiz->item.length(); i++) {
            if (raiz->dir->item[i] != raiz->esq->item[i]) {
                raiz->item[i] = 'a';
            } else {
                raiz->item[i] = raiz->esq->item[i];
            }
        }
        raiz->valor = 1;
    } else if (esqValor || dirValor) {
        unsigned int index_pos = index;
        while (index_pos < raiz->item.length() && raiz->item[index_pos] != 'e' && expressao[index_pos] != 'a') {
            index_pos++;
        }
        if (raiz->item[index_pos] == 'a') {
            raiz->valor = 0;
            return;
        }

        std::string valoracao;
        if (dirValor) valoracao = raiz->dir->valor;
        else {
            valoracao = esqValor;
        }
        for (unsigned int i = index_pos; i < raiz->item.length(); i++) {
            if (raiz->item[i] == 'e') {
                raiz->item[i] = '1';
            }
        }
        raiz->item[index_pos] = '1';
        raiz->valor = 1;
    } else {
        raiz->valor = 0;
        raiz->item[index] = '0';
    }
}

void ArvoreBinaria::avaliaFolha(NO *no) {
    AvaliadorExpressaoLogica evaluator(expressao, no->item);
    no->valor = evaluator.avaliar(no->item);
}
