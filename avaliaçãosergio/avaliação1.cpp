#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

struct DataHora{

int dia,mes,ano;
int hora,min;
};

struct clientes
{
    string nome;
    string cpf;
    string cnh;
    DataHora datanascimento;

};

struct veiculos
{
   string renavan;
   string placaveiculo;
   DataHora horaretirada;
   DataHora horaentrega;
   string lojaretirada;
};


vector<clientes>ListaClientes;
vector<veiculos>ListaVeiculos;


void LerCliente(clientes *lercliente){
    cout<<"digite seu nome: "<<endl;
    getline(cin,lercliente->nome);
    cout<<"digite seu cpf; "<<endl;
    getline(cin,lercliente->cpf);
    cout<<"digite sua cnh : "<<endl;
    getline(cin,lercliente->cnh);
    cout<<"digite sua data de nascimento no formato dia/mes/ano "<<endl;
    cin>>lercliente->datanascimento.dia>>lercliente->datanascimento.mes>>lercliente->datanascimento.ano;

}

void MostrarCliente(){
 for (auto it = ListaClientes.begin();it != ListaClientes.end(); it++ ){
    cout<<"os dados do cliente são: "<<endl;
    cout<<"cliente:"<<it->nome<<endl;
    cout<<"cpf:"<<it->cpf<<endl;
    cout<<"cnh:"<<it->cnh<<endl;
    cout<<"data de nascimento:"<<it->datanascimento.dia<<"/"<< it->datanascimento.mes<<"/"<<it->datanascimento.ano<<endl;
 }   
}

int menuop(void)
{
    int escolha;
    do
    {
        cout << "escolha um serviço: " << endl;
        cout << "digite 1 para incluir cliente" << endl;
        cout << "digite 2 para excluir cliente" << endl;
        cout << "digite 3 para alterar cliente" << endl;
        cout << "digite 4 para listar cliente" << endl;
        cout << "digite 5 para localizar cliente" << endl;
        cout << "digite 0 para sair " << endl;
        cin >> escolha;
        cin.ignore();

    } while (escolha < 0 || escolha > 5);

    return escolha;
};

void excluircpf()
{
    string cpf;
    int cont = -1;
    cout << "digite seu cpf para excluir" << endl;
    getline(cin, cpf);

    vector<clientes>::iterator i;
    i = ListaClientes.begin();

    for (auto it = ListaClientes.begin(); it != ListaClientes.end(); it++)
    {
        cont += 1;
        if (cpf == it->cpf)
        {
            advance(i, cont);
            ListaClientes.erase(i);
            cout << "o cliente excluido com sucesso " << endl;
        }
    }
}



void localizarcpf()
{
    string cpf;
    cout << "digite seu cpf" << endl;
    getline(cin, cpf);
    for (auto it = ListaClientes.begin(); it != ListaClientes.end(); it++)
    {
        if (cpf == it->cpf)
        {
            cout << endl;
            cout << endl;
            cout << " o cliente é " << endl;

            cout << " seu nome " << it->nome << endl;
            cout << " seu cpf " << it->cpf << endl;
            cout << " sua cnh " << it->cnh << endl;
            cout <<"data de nascim0ento:"<<it->datanascimento.dia<<"/"<< it->datanascimento.mes<<"/"<<it->datanascimento.ano<<endl;

            cout << endl;
            cout << endl;
        }
    }
}

void alterardados()
{
    string cpf;
    int valor;
    cout << "digite seu cpf" << endl;
    getline(cin, cpf);
    for (auto it = ListaClientes.begin(); it != ListaClientes.end(); it++)
    {
        if (cpf == it->cpf)
        {
            cout << endl;
            cout << endl;
            cout << " o cliente é " << endl;

            cout << " seu nome " << it->nome << endl;
            cout << " seu cpf " << it->cpf << endl;
            cout << " sua cnh " << it->cnh << endl;
            cout <<"data de nascim0ento:"<<it->datanascimento.dia<<"/"<< it->datanascimento.mes<<"/"<<it->datanascimento.ano<<endl;

            cout << endl;
            cout << endl;
            cout<< "Deseja alterar algum dado?"<<endl;
            cout<< "digite 1 para nome "<<endl;
            cout<< "digite 2 para cpf "<<endl;
            cout<< "digite 3 para cnh "<<endl;
            cout<< "digite 4 para data de nascimento "<<endl;
            cin>>valor;
           
            
        }
    }
}




int main(){

    clientes clienteDados;
    
    
    int opcao;

    do
    {
        opcao = menuop();

        switch (opcao)
        {
        case 1:
            LerCliente(&clienteDados);
            ListaClientes.push_back(clienteDados);
            break;
        case 2:
            excluircpf(); 
            break;
        case 3:
           alterardados();
            break;
        case 4:   
            MostrarCliente();
            break;
        case 5:
             localizarcpf();
            break;
        }
    } while (opcao != 0);



    return 0;
}

