//Os usuarios podem adicionar uma despesa com uma descrição e um valor.
//Os usuarios podem atualizar uma despesa.
//Os usuarios podem excluir uma despesa.
//Os usuarios podem visualizar todas as despesas.
//Os usuarios podem visualizar um resumo de todas as despesas.
//Os usuarios podem visualizar um resumo das despesas de um mês específico (do ano corrente)

#include <iostream>
#include <string>
using namespace std;

int acao;
float gasto;
float ganho;

struct despesa{
    string nome;
    float valor;
    string categoria;
};
void menu(){
    cout <<"------- MENU --------"<<endl;
    cout <<"1 - adicionar despesa"<< endl;
    cout <<"2 - atualizar despesa "<< endl;
    cout <<"3 - excluir despesa "<< endl;
    cout <<"4 - visualizar todas as despesas "<< endl;
    cout <<"5 - visualizar valor atual de cada categoria "<< endl;
}

despesa adicionardespesa (){
    despesa a;
    cout << "Digite qual e a despesa:"<< endl;
    cin >> a.nome;
    cout << "Digite qual e o valor da despesa:"<< endl;
    cin >> a.valor;
    cout << "Digite qual e a categoria da despesa:"<< endl;
    cin >> a.categoria;
    return a;
}

int main(){

menu();
cout << "Digite a opcao desejada:"<< endl;
cin >>acao;


switch (acao) {
    case(1):
     adicionardespesa();
     cout <<"Despesa adicionada com sucesso!"<< endl;
     break;
   case(2):
     break;

    

}

}