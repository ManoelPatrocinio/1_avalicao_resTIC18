#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DataHora
{
    int Dia, Mes, Ano;
    float hora;
};
struct Cliente
{
    string CPF;
    string Nome;
    DataHora DtNascimento;
    string CNH;
};

struct Veiculo
{
    string Renavan;
    string Placa_do_Veiculo;
    DataHora Data_Hora_Retirada;
    DataHora Data_Hora_Entrega;
    string Loja_Retirada;
};

void incluirCliente(Cliente *clienteDados)
{

    system("clear");
    cout << "Digite o nome do cliente: ";
    getline(cin, clienteDados->Nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin, clienteDados->CPF);
    cout << "Digite o Dia de nascimento do cliente: ";
    cin >> clienteDados->DtNascimento.Dia;
    cout << "Digite o Mes de nascimento do cliente: ";
    cin >> clienteDados->DtNascimento.Mes;
    cout << "Digite o Ano de nascimento do cliente: ";
    cin >> clienteDados->DtNascimento.Ano;
    cin.ignore();
    cout << "Digite a CNH do cliente: ";
    getline(cin, clienteDados->CNH);

    cout << endl;
    cout << "Cliente cadastrado com sucesso!";
    cout << endl;
    cout << endl;

};

void listaClientes(vector<Cliente> listaClientes)
{

    system("clear");
    cout << endl;
    cout << endl;
    cout << "--- Clientes Cadastrados --- " << endl;

    for (auto it = listaClientes.begin(); it != listaClientes.end(); it++)
    {
        cout << "Nome do cliente: " << it->Nome << endl;
        cout << "CPF do cliente: " << it->CPF << endl;
        cout << "CNH do cliente: " << it->CNH << endl;
        cout << "Data de nascimento: " << it->DtNascimento.Dia << "/" << it->DtNascimento.Mes << "/" << it->DtNascimento.Ano << endl;
        cout << endl;
  
    }

    cout << endl;
    cout << endl;
};



void excluirCliente(vector<Cliente> listaClientes)
{

    string cpfDeExclusao;
    int cont = -1;

    system("clear");

    cout << "Digite o CPF do cliente que deseja excluir: ";
    getline(cin, cpfDeExclusao);

    vector<Cliente>::iterator i;
    i = listaClientes.begin();

    for (auto it = listaClientes.begin(); it != listaClientes.end(); it++)
    {
        cont += 1;
        if (cpfDeExclusao == it->CPF)
        {

            advance(i, cont);
            listaClientes.erase(i);
            cout << "Excluído com sucesso !" << endl;
        }
    }
};


void localizaCliente(vector<Cliente> listaClientes)
{

    string cpfDeBusca;

    system("clear");

    cout << "Digite o CPF do cliente que deseja buscar: ";
    getline(cin, cpfDeBusca);

   
    for (auto it = listaClientes.begin(); it != listaClientes.end(); it++)
    {
        if (cpfDeBusca == it->CPF)
        {
            cout << "--- Cliente Encontrado ---" << endl;
            cout << endl;
            cout << "Nome do cliente: " << it->Nome << endl;
            cout << "CPF do cliente: " << it->CPF << endl;
            cout << "CNH do cliente: " << it->CNH << endl;
            cout << "Data de nascimento: " << it->DtNascimento.Dia << "/" << it->DtNascimento.Mes << "/" << it->DtNascimento.Ano << endl;
            cout << endl;
            
        }
    }
};
int menu_cliente(void)
{
    int escolha;
    do
    {
        cout << "--- Gestão de Clientes --- " << endl;
        cout << endl;

        cout << "1 - p/ Incluir cliente" << endl;
        cout << "2 - p/ Excluir um cliente" << endl;
        cout << "3 - p/ Alterar um cliente" << endl;
        cout << "4 - p/ Listar clientes" << endl;
        cout << "5 - p/ Localizar Cliente" << endl;
        cout << "0 - p/ Sair " << endl;
        cout << "Sua escolha: ";
        cin >> escolha;
        cin.ignore();

    } while (escolha < 0 || escolha > 5);

    return escolha;
}

int menu_veiculo(void)
{
    int escolha;
    do
    {
        cout << "--- Gestão de Veículos --- " << endl;
        cout << endl;

        cout << "1 - p/ Incluir veículo" << endl;
        cout << "2 - p/ Excluir um veículo" << endl;
        cout << "3 - p/ Alterar um veículo" << endl;
        cout << "4 - p/ Listar veículos" << endl;
        cout << "5 - p/ Localizar veículo" << endl;
        cout << "0 - p/ Sair " << endl;
        cout << "Sua escolha: ";
        cin >> escolha;
        cin.ignore();

    } while (escolha < 0 || escolha > 5);

    return escolha;
}

int main(void)
{
    Cliente clienteDados;
    vector<Cliente> listaDeClientes;
    int opcaoDeMenu, opcaoDeServico;

    do
    {
        cout << " 1 - P/ Gestão de Clientes" << endl;
        cout << " 2 - P/ Gestão de Clientes" << endl;
        cout << " 0 - P/ Finalizar Programa" << endl;
        cout << " Sua opcao: ";
        cin >> opcaoDeMenu;

        if (opcaoDeMenu == 1)
        {
            do
            {
                opcaoDeServico = menu_cliente();

                switch (opcaoDeServico)
                {
                case 1:
                    incluirCliente(&clienteDados);
                    listaDeClientes.push_back(clienteDados);
                    break;
                case 2:
                    excluirCliente(listaDeClientes);
                    break;

                case 4 :
                    listaClientes(listaDeClientes);
                    break;
                  case 5:
                  localizaCliente(listaDeClientes)  ;
                  break;

                default:
                    break;
                }
            } while (opcaoDeServico != 0);
        }
        else if (opcaoDeMenu == 1)
        {
            opcaoDeServico = menu_veiculo();
        }
    } while (opcaoDeMenu != 0);

    return 0;
}