//Os usuarios podem adicionar uma despesa com uma descrição e um valor.
//Os usuarios podem atualizar uma despesa.
//Os usuarios podem excluir uma despesa.
//Os usuarios podem visualizar todas as despesas.
//Os usuarios podem visualizar um resumo de todas as despesas.
//Os usuarios podem visualizar um resumo das despesas de um mês específico (do ano corrente)

#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int acao;
float gasto;
float ganho;
sqlite3* db; 

struct despesa{
    string nome;
    float valor;
    string categoria;
};

void menu(){
 cout <<"------- MENU -------"<<endl;
 cout <<"1 - adicionar despesa"<< endl;
 cout <<"2 - visualizar todas as despesas "<< endl;
 cout <<"3 - excluir despesa "<< endl;
 cout <<"4 - atualizar despesa "<< endl;
 cout <<"5 - visualizar valor atual de cada categoria "<< endl;
 cout <<"0 - para sair"<< endl;
}

despesa adicionardespesa (){

    despesa a;

    cout << "Digite qual e a despesa:"<< endl;
    cin.ignore();
    getline(cin,a.nome);
    cout << "Digite qual e o valor da despesa:"<< endl;
    cin >> a.valor;
    cout << "Digite qual e a categoria da despesa:"<< endl;
    cin.ignore();
    getline(cin, a.categoria);
    
    string inserir = "INSERT INTO despesas (nome, valor, categoria) VALUES('" + a.nome + "', " + to_string(a.valor) + ",'" + a.categoria + "');";
    sqlite3_exec(db, inserir.c_str(), nullptr, nullptr, nullptr);
    return a;
}

void printardespesa(){
    sqlite3_stmt* stmt;
    despesa d;

    string sql = " SELECT nome, valor, categoria from despesas";
    //.c_str foi usado pois o sqlite3 aceita apenas C, e como ssql é tipo string é necessario converter
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW){
        //o const char* foi usado pois o sqlite3 apenas devolve em C, para adapatar para string em c++ se usa o  o const char*

        const char* txtnome = (const char*)
        sqlite3_column_text(stmt, 0);
        d.nome= txtnome;

        d.valor = sqlite3_column_double(stmt, 1);

       const char* txtcat = (const char*)
       sqlite3_column_text(stmt, 2);
        d.categoria = txtcat;
        
        cout<< "A despesa e: "<< d.nome<<" o valor: "<< d.valor<<" e a categoria: "<< d.categoria<< endl;
   }

}


int main(){

    string sqlcriartabela = "CREATE TABLE IF NOT EXISTS despesas ("
     "id INTEGER PRIMARY KEY AUTOINCREMENT, "
     "nome TEXT NOT NULL, "
     "valor REAL NOT NULL, "
     "categoria TEXT NOT NULL);";
      sqlite3_open("banco_dados.db", &db);
      sqlite3_exec(db, sqlcriartabela.c_str(), nullptr, nullptr, nullptr);

    do{

        menu();
        cout << "Digite a opcao desejada:"<< endl;
        cin >> acao;

        switch (acao) {

            case(1):
                adicionardespesa();
                cout <<"Despesa adicionada com sucesso!"<< endl;
                break;

            case(2):
                printardespesa();
                break;
            case (0):
            break;
        }
       
    } while(acao != 0);

     sqlite3_close(db);

    return 0;
}