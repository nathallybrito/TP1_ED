//---------------------------------------------------------------------
// Arquivo	: main.cpp
// Conteudo	: programa de avaliação do trabalho
// Autor	: Náthally Fernandes. (nathallyfernandes@ufmg.br)
//---------------------------------------------------------------------
#include <iostream>
#include <string>
#include "avaliador.hpp"
#include "arvore.hpp"
#include "stack.hpp"

using namespace std;

void uso()
//Descrição:imprime as opções de uso
//A saída é a impressão das opções de linhas de comando no makefile 
{
   cout<< " \t -a  \t Avaliação de Expressões \n" <<endl;
   cout<< " \t -s \t Satisfabilidade \n "<<endl;
   
}

int parse_args(int argc,char** argv, string& optescolhida, string& expression, string& valuation)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida
{
    if (argc != 4){
        cerr<< "Uso incorreto."<< endl;
        uso();
        return 1;
    }
    optescolhida = argv[1];
    expression = argv[2];
    valuation = argv[3];

    return 0;

}

int main(int argc, char** argv)
// Descricao: programa principal para execucao das avaliações de expressões e satisfabilidade
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
    string optescolhida,expression,valuation;
    if(parse_args(argc,argv,optescolhida,expression,valuation)!= 0){
        return 1;
    }

    try {
        if (optescolhida == "-a"){
            AvaliadorExpressaoLogica evaluator(expression, valuation);
            bool result = evaluator.avaliar(expression);
            cout << result << endl;

        } else if( optescolhida == "-s"){
            /*std::string val_expression = valuation;
            std::string exp = expression;
            ArvoreBinaria tree(val_expression, exp);
            unsigned int lowerbound = tree.encontraQuanti(valuation, 0);*/
            AvaliadorExpressaoLogica avaliacao(expression,valuation);
            avaliacao.satisfabilidade(expression,valuation);

        } else{
            cerr<< "Opção inválida. Use -a ou -s"<<endl;
            uso();
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
      
    }

    return 0;

}