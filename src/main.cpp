#include <iostream>
#include "avaliador.h"

using namespace std;

/*void uso()
//Descrição:imprime as opções de uso
//A saída é a impressão das opções de linhas de comando no makefile 
{
   cout<< " \t-a  \t Avaliação de Expressões \n";
   cout<< " \t -s \t Satisfabilidade \n ";
   
}

int parse_args(int argc,char** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida
{

}*/

int main(){
    string expression, valuation;
    cout << "Digite a fórmula lógica: ";
    getline(cin, expression);
    
    cout << "Digite a valoração (string binária): ";
    getline(cin, valuation);

    try {
        AvaliadorExpressaoLogica evaluator(expression, valuation);
        bool result = evaluator.avaliar();
       cout << "Resultado da expressão: " << result << endl;
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;

}