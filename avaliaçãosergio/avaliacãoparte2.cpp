#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

struct DataHora
{

    int dia, mes, ano;
    int hora, min;
};

struct veiculos
{
    string renavan;
    string placaveiculo;
    DataHora horaretirada;
    DataHora horaentrega;
    string lojaretirada;
};

vector<veiculos> ListaVeiculos;

void LerVeiculo(veiculos *lerveiculo)
{
    cout << "digite seu renavan: " << endl;
    getline(cin, lerveiculo->renavan);
    cout << "digite sua placa; " << endl;
    getline(cin, lerveiculo->placaveiculo);
    cout << "digite a loja da retirada: " << endl;
    getline(cin, lerveiculo->lojaretirada);
    cout << " digite data da entrega do formato dia/mes/ano" << endl;
    cin >> lerveiculo->horaentrega.dia >> lerveiculo->horaentrega.mes >> lerveiculo->horaentrega.ano;
    cout << " digite a hora da entrega no formato (hora:min) " << endl;
    cin >> lerveiculo->horaentrega.hora >> lerveiculo->horaentrega.min;
    cout << " digite data da retirada do formato dia/mes/ano" << endl;
    cin >> lerveiculo->horaretirada.dia >> lerveiculo->horaretirada.mes >> lerveiculo->horaretirada.ano;
    cout << " digite a hora da retirada no formato (hora:min) " << endl;
    cin >> lerveiculo->horaretirada.hora >> lerveiculo->horaretirada.min;
}

void MostrarVeiculo()
{
    for (auto it = ListaVeiculos.begin(); it != ListaVeiculos.end(); it++)
    {
        cout << endl;
        cout << "os dados do veiculo : " << endl;
        cout << endl;
        cout << "renavan:" << it->renavan << endl;
        cout << "placa:" << it->placaveiculo << endl;
        cout << "loja:" << it->lojaretirada << endl;
        cout << "data da entrega:" << it->horaentrega.dia << "/" << it->horaentrega.mes << "/" << it->horaentrega.ano << endl;
        cout << "hora da entrega:" << it->horaentrega.hora << ":" << it->horaentrega.min << endl;
        cout << "data da retirada:" << it->horaretirada.dia << "/" << it->horaretirada.mes << "/" << it->horaretirada.ano << endl;
        cout << "hora da retirada:" << it->horaretirada.hora << ":" << it->horaretirada.min << endl;
    }
}

int menuop(void)
{
    int escolha;
    do
    {
        cout << endl;
        cout << "escolha um serviço: " << endl;
        cout << "digite 1 para incluir veiculo" << endl;
        cout << "digite 2 para excluir veiculo" << endl;
        cout << "digite 3 para alterar veiculo" << endl;
        cout << "digite 4 para listar veiculo" << endl;
        cout << "digite 5 para localizar veiculo" << endl;
        cout << "digite 0 para sair " << endl;
        cin >> escolha;
        cin.ignore();

    } while (escolha < 0 || escolha > 5);

    return escolha;
};

void excluirveiculo()
{
    string placa;
    int cont = -1;
    cout << "digite uma placa para excluir veiculo" << endl;
    getline(cin, placa);

    vector<veiculos>::iterator i;
    i = ListaVeiculos.begin();

    for (auto it = ListaVeiculos.begin(); it != ListaVeiculos.end(); it++)
    {
        cont += 1;
        if (placa == it->placaveiculo)
        {
            advance(i, cont);
            ListaVeiculos.erase(i);
            cout << "o veiculo excluido com sucesso " << endl;
        }
    }
}

void localizarveiculo()
{
    string placa;
    cout << "digite a placa do carro " << endl;
    getline(cin, placa);
    for (auto it = ListaVeiculos.begin(); it != ListaVeiculos.end(); it++)
    {
        if (placa == it->placaveiculo)
        {
            cout << endl;
            cout << endl;
            cout << " o veiculo é " << endl;

            cout << " renavan " << it->renavan << endl;
            cout << " placa " << it->placaveiculo << endl;
            cout << " loja " << it->lojaretirada << endl;
            cout << "data de entrega:" << it->horaentrega.dia << "/" << it->horaentrega.mes << "/" << it->horaentrega.ano << endl;
            cout << "hora de entrega:" << it->horaentrega.hora << "/" << it->horaentrega.min;
            cout << "data de retirada:" << it->horaretirada.dia << "/" << it->horaretirada.mes << "/" << it->horaretirada.ano << endl;
            cout << "hora de retirada:" << it->horaretirada.hora << "/" << it->horaretirada.min;

            cout << endl;
            cout << endl;
        }
    }
}

void alterardados()
{
    string placa;
    cout << "digite a placa do veiculo" << endl;
    getline(cin, placa);
    for (auto it = ListaVeiculos.begin(); it != ListaVeiculos.end(); it++)
    {
        if (placa == it->placaveiculo)
        {
            cout << endl;
            cout << endl;
            cout << " o veiculo é " << endl;

            cout << " renavan " << it->renavan << endl;
            cout << " placa " << it->placaveiculo << endl;
            cout << " loja " << it->lojaretirada << endl;
            cout << "data de entrega:" << it->horaentrega.dia << "/" << it->horaentrega.mes << "/" << it->horaentrega.ano << endl;
            cout << "hora de entrega:" << it->horaentrega.hora << "/" << it->horaentrega.min;
            cout << "data de retirada:" << it->horaretirada.dia << "/" << it->horaretirada.mes << "/" << it->horaretirada.ano << endl;
            cout << "hora de retirada:" << it->horaretirada.hora << "/" << it->horaretirada.min;

            cout << endl;
            cout << endl;

            char novorenavan;
            char novoplaca;
            char novoloja;
            char novodataentrada;
            char novodataretirada;
            cout << "Deseja altera o renavan? (S/N) " << endl;
            cin >> novorenavan;
            if (novorenavan == 'S' || novorenavan == 's')
            {
                cout << "novo renavan: " << endl;
                cin >> it->renavan;
            };

            cout << "Deseja alterar sua placa? (S/N) " << endl;
            cin >> novoplaca;
            if (novoplaca == 'S' || novoplaca == 's')
            {
                cout << "nova placa :" << endl;
                cin >> it->placaveiculo;
            };

            cout << "Deseja alterar a loja ? (S/N) " << endl;
            cin >> novoloja;
            if (novoloja == 'S' || novoloja == 's')
            {
                cout << "nova cnh: " << endl;
                cin >> it->lojaretirada;
            };

            cout << "Deseja alterar a data de entrega? (S/N) " << endl;
            cin >> novodataentrada;
            if (novodataentrada == 'S' || novodataentrada == 's')
            {
                cout << "nova data de entrada:" << endl;
                cin >> it->horaentrega.dia >> it->horaentrega.mes >> it->horaentrega.ano;
                cout << "nova hora de entrega" << endl;
                cin >> it->horaentrega.hora >> it->horaentrega.min;
            };
            cout << "Deseja alterar a data de retirada? (S/N) " << endl;
            cin >> novodataretirada;
            if (novodataretirada == 'S' || novodataretirada == 's')
            {
                cout << "nova data de retirada:" << endl;
                cin >> it->horaretirada.dia >> it->horaretirada.mes >> it->horaretirada.ano;
                cout << "nova hora de retirada" << endl;
                cin >> it->horaretirada.hora >> it->horaretirada.min;
            }

            cout << "dados alterados com sucesso " << endl;
        }
    }
}

int main()
{

    veiculos veiculoDados;

    int opcao;

    do
    {
        opcao = menuop();

        switch (opcao)
        {
        case 1:
            LerVeiculo(&veiculoDados);
            ListaVeiculos.push_back(veiculoDados);
            break;
        case 2:
            excluirveiculo();
            break;
        case 3:
            alterardados();
            break;
        case 4:
            MostrarVeiculo();
            break;
        case 5:
            localizarveiculo();
            break;
        }
    } while (opcao != 0);

    return 0;
}