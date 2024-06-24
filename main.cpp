/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Larissa Ávila.                             Matrícula: 2024.1.08.031
 *
 * Projeto que armazena informações sobre diferentes veículos, e permite manipular
 * esse armazenamento, pesquisando, adicionando e retirando informações, e ainda 
 * fornecendo dados numéricos sobre o total de veículos
 */

#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <valarray>
#include <math.h>

using namespace std;

const int TAM = 100;

typedef struct{
    string modelo;
    string marca;
    string tipo;
    int ano;
    int quilometragem;
    string potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string portas;
    string placa;
    float valor;
    bool valido;
} Veiculo;

/*
 */
int main(int argc, char** argv) {
    
    ifstream arquivo("BD_veiculos.txt");
    Veiculo lista[TAM];
    string auxiliar, busca, modelobarato, modelocaro, placa1, placa2;
    int qtd, i, opcao, teste, retirada, // variáveis gerais
            vinicial, vfinal; // variáveis do case 6
    float hatch, seda, suv, picape, van, total, flex, gasolina, diesel, etanol, barato, caro,
            velhos, kmvelhos, validos, parcela, seguro;
    
    if(!arquivo.is_open()){
        cout<<"O arquivo não existe."<<endl;
        return 1;
    }
    
    cout<<"Banco de veículos"<<endl;
    
    arquivo>>auxiliar;
    
    qtd = 0;
    
    while(auxiliar != "FIM"){
        lista[qtd].modelo = auxiliar;
        arquivo >> lista[qtd].marca;
        arquivo >> lista[qtd].tipo;
        arquivo >> lista[qtd].ano;
        arquivo >> lista[qtd].quilometragem;
        arquivo >> lista[qtd].potencia;
        arquivo >> lista[qtd].combustivel;
        arquivo >> lista[qtd].cambio;
        arquivo >> lista[qtd].direcao;
        arquivo >> lista[qtd].cor;
        arquivo >> lista[qtd].portas;
        arquivo >> lista[qtd].placa;
        arquivo >> lista[qtd].valor;
        lista[qtd].valido = true;
        qtd++;
        arquivo>>auxiliar;
    }
    
    arquivo.close();
    
    for(i=0; i<qtd; i++){
        cout<< lista[i].modelo<<" ";
        cout<< lista[i].marca<<" ";
        cout<< lista[i].tipo<<" ";
        cout<< lista[i].ano<<" ";
        cout<< lista[i].quilometragem<<" ";
        cout<< lista[i].potencia<<" ";
        cout<< lista[i].combustivel<<" ";
        cout<< lista[i].cambio<<" ";
        cout<< lista[i].direcao<<" ";
        cout<< lista[i].cor<<" ";
        cout<< lista[i].portas<<" ";
        cout<< lista[i].placa<<" ";
        cout<< lista[i].valor<<" ";
        cout<<endl;
    }
    
    do{
        cout<<endl<<"Opção 1: Imprimir a lista."<<endl;
        cout<<"Opção 2: Incluir um veículo na lista."<<endl;
        cout<<"Opção 3: Buscar veículo pela placa e excluí-lo."<<endl;
        cout<<"Opção 4: Buscar veículos pelo seu tipo."<<endl;
        cout<<"Opção 5: Buscar veículos pelo câmbio."<<endl;
        cout<<"Opção 6: Buscar veículos por uma faixa de valores."<<endl;
        cout<<"Opção 7: Relatório do banco de dados."<<endl;
        cout<<"Opção 0: Finalizar o programa"<<endl;
        cout<<"Digite sua opção"<<endl;
        
        cin>>opcao;
        cout<<endl;
        
        switch(opcao){
            case 1:
                for(i=0; i<qtd; i++){
                    if(lista[i].valido == true){
                        cout<< lista[i].modelo<<" ";
                        cout<< lista[i].marca<<" ";
                        cout<< lista[i].tipo<<" ";
                        cout<< lista[i].ano<<" ";
                        cout<< lista[i].quilometragem<<" ";
                        cout<< lista[i].potencia<<" ";
                        cout<< lista[i].combustivel<<" ";
                        cout<< lista[i].cambio<<" ";
                        cout<< lista[i].direcao<<" ";
                        cout<< lista[i].cor<<" ";
                        cout<< lista[i].portas<<" ";
                        cout<< lista[i].placa<<" ";
                        cout<< lista[i].valor<<" ";
                        cout<<endl;
                    }
                }
                cout<<endl;
                break;
                
            case 2:
                teste = 0;
                for(i=0; i<qtd; i++){
                    if(lista[i].valido == false){
                        cout<<"Digite o modelo do carro: ";
                        cin>>lista[i].modelo;
                        cout<<"Digite a marca do carro: ";
                        cin>>lista[i].marca;
                        cout<<"Digite o tipo do carro: ";
                        cin>>lista[i].tipo;
                        cout<<"Digite o ano do carro: ";
                        cin>>lista[i].ano;
                        cout<<"Digite a quatidade de quilômetros rodados: ";
                        cin>>lista[i].quilometragem;
                        cout<<"Digite a potência do motor do carro: ";
                        cin>>lista[i].potencia;
                        cout<<"Digite o tipo de combustível que o carro aceita, ou se é flex: ";
                        cin>>lista[i].combustivel;
                        cout<<"Digite o tipo de câmbio do carro: ";
                        cin>>lista[i].cambio;
                        cout<<"Digite o tipo de direção do carro: ";
                        cin>>lista[i].direcao;
                        cout<<"Digite a cor do carro: ";
                        cin>>lista[i].cor;
                        cout<<"Digite a quantidade de portas do carro: ";
                        cin>>lista[i].portas;
                        cout<<"Digite a placa do veículo: ";
                        cin>>lista[i].placa;
                        cout<<"Digite o valor do veículo: ";
                        cin>>lista[i].valor;
                        lista[i].valido = true;
                        teste = 1;
                        break;
                    }
                }
                
                if(teste==0){
                    cout<<"Digite o modelo do carro: ";
                    cin>>lista[qtd].modelo;
                    cout<<"Digite a marca do carro: ";
                    cin>>lista[qtd].marca;
                    cout<<"Digite o tipo do carro: ";
                    cin>>lista[qtd].tipo;
                    cout<<"Digite o ano do carro: ";
                    cin>>lista[qtd].ano;
                    cout<<"Digite a quatidade de quilômetros rodados: ";
                    cin>>lista[qtd].quilometragem;
                    cout<<"Digite a potência do motor do carro: ";
                    cin>>lista[qtd].potencia;
                    cout<<"Digite o tipo de combustível que o carro aceita, ou se é flex: ";
                    cin>>lista[qtd].combustivel;
                    cout<<"Digite o tipo de câmbio do carro: ";
                    cin>>lista[qtd].cambio;
                    cout<<"Digite o tipo de direção do carro: ";
                    cin>>lista[qtd].direcao;
                    cout<<"Digite a cor do carro: ";
                    cin>>lista[qtd].cor;
                    cout<<"Digite a quantidade de portas do carro: ";
                    cin>>lista[qtd].portas;
                    cout<<"Digite a placa do veículo: ";
                    cin>>lista[qtd].placa;
                    cout<<"Digite o valor do veículo: ";
                    cin>>lista[qtd].valor;
                    lista[qtd].valido = true;
                    qtd++; 
                }
                cout<<endl;
                break;
                
            case 3:
                teste = 0;
                cout<<"Digite a placa do carro que você está buscando: ";
                cin>>busca; cout<<endl;
                for (i=0; i<qtd; i++){
                    if(lista[i].valido == true && lista[i].placa == busca){
                        cout<<lista[i].modelo<<" ";
                        cout<<lista[i].marca<<" ";
                        cout<<lista[i].tipo<<" ";
                        cout<<lista[i].ano<<" ";
                        cout<<lista[i].quilometragem<<" ";
                        cout<<lista[i].potencia<<" ";
                        cout<<lista[i].combustivel<<" ";
                        cout<<lista[i].cambio<<" ";
                        cout<<lista[i].direcao<<" ";
                        cout<<lista[i].cor<<" ";
                        cout<<lista[i].portas<<" ";
                        cout<<lista[i].placa<<" ";
                        cout<<lista[i].valor<<" ";
                        cout<<endl;
                        teste = i;
                    } 
                }
                
                if(teste == 0){
                    cout<<"O carro não está na lista.";
                    break;
                }else{
                    cout<<endl<<"Para retirar o carro da lista, digite 1. Para voltar ao menu, digite qualquer outra tecla. ";
                    cin>>retirada;
                    if(retirada == 1){
                        lista[teste].valido = false;
                        cout<<"Veículo retirado."<<endl;
                    }
                }
                cout<<endl;
                break;
                
            case 4:
                teste = 0;
                cout<< "Digite o tipo do veículo que você está buscando: "<<endl;
                cout<< "Tipos disponíveis: Hatch, Sedã, SUV, Pick-up, Van (Leve em conta letras maiúsculas e pontuação)"<<endl;
                cin>>busca; cout<<endl;
                for(i=0; i<qtd; i++){
                    if(lista[i].valido == true && lista[i].tipo == busca){
                        cout<<lista[i].modelo<<" ";
                        cout<<lista[i].marca<<" ";
                        cout<<lista[i].tipo<<" ";
                        cout<<lista[i].ano<<" ";
                        cout<<lista[i].quilometragem<<" ";
                        cout<<lista[i].potencia<<" ";
                        cout<<lista[i].combustivel<<" ";
                        cout<<lista[i].cambio<<" ";
                        cout<<lista[i].direcao<<" ";
                        cout<<lista[i].cor<<" ";
                        cout<<lista[i].portas<<" ";
                        cout<<lista[i].placa<<" ";
                        cout<<lista[i].valor<<" ";
                        cout<<endl;
                        teste = 1;
                    }
                }
                if(teste == 0){
                    cout<<" Não temos carro do tipo "<< busca<<" na lista."<<endl;
                }
                break;
                
            case 5:
                teste = 0;
                cout<< "Digite o câmbio do veículo que você está buscando: ";
                cin>>busca; cout<<endl;
                for(i=0; i<qtd; i++){
                    if(lista[i].valido == true && lista[i].cambio == busca){
                        cout<<lista[i].modelo<<" ";
                        cout<<lista[i].marca<<" ";
                        cout<<lista[i].tipo<<" ";
                        cout<<lista[i].ano<<" ";
                        cout<<lista[i].quilometragem<<" ";
                        cout<<lista[i].potencia<<" ";
                        cout<<lista[i].combustivel<<" ";
                        cout<<lista[i].cambio<<" ";
                        cout<<lista[i].direcao<<" ";
                        cout<<lista[i].cor<<" ";
                        cout<<lista[i].portas<<" ";
                        cout<<lista[i].placa<<" ";
                        cout<<lista[i].valor<<" ";
                        cout<<endl;
                        teste = 1;
                    }
                }
                if(teste == 0){
                    cout<<" Não temos carros com o cambio "<<busca<<" na lista."<<endl;
                }
                cout<<endl;
                break;
                
            case 6:
                teste = 0;
                cout<<"Digite o valor mínimo que você está procurando: ";
                cin>>vinicial;
                cout<<endl<<"Digite o valor máximo que você está procurando: ";
                cin>>vfinal; cout<<endl;
                for(i=0; i<qtd; i++){
                    if(lista[i].valido == true && lista[i].valor >= vinicial && lista[i].valor <= vfinal){
                        cout<<lista[i].modelo<<" ";
                        cout<<lista[i].marca<<" ";
                        cout<<lista[i].tipo<<" ";
                        cout<<lista[i].ano<<" ";
                        cout<<lista[i].quilometragem<<" ";
                        cout<<lista[i].potencia<<" ";
                        cout<<lista[i].combustivel<<" ";
                        cout<<lista[i].cambio<<" ";
                        cout<<lista[i].direcao<<" ";
                        cout<<lista[i].cor<<" ";
                        cout<<lista[i].portas<<" ";
                        cout<<lista[i].placa<<" ";
                        cout<<lista[i].valor<<" ";
                        cout<<endl;
                        teste = 1;
                    }
                }
                if(teste == 0){
                    cout<<"Desculpe. Não temos opções nesta faixa de valores. "<<endl;
                }
                cout<<endl;
                break;
                
            case 7:
                hatch = 0;
                seda = 0;
                picape = 0;
                suv = 0;
                van = 0;
                total = 0;
                flex = 0;
                gasolina = 0;
                etanol = 0;
                diesel = 0;
                barato = lista[0].valor;
                caro = 0;
                velhos = 0;
                kmvelhos = 0;
                for(i=0; i<qtd; i++){
                    if(lista[i].tipo == "Hatch"){
                        hatch++;
                    }else
                        if(lista[i].tipo == "Sedã"){
                            seda++; 
                        }else
                            if(lista[i].tipo == "Pick-up"){
                                picape++;
                            }else
                                if(lista[i].tipo == "SUV"){
                                    suv++;
                                }else
                                    if(lista[i].tipo == "Van"){
                                        van++;
                                    }
                    if(lista[i].valido == true){
                        total++;
                    }
                    if(lista[i].combustivel == "Flex"){
                        flex++;
                    }else
                        if(lista[i].combustivel == "Diesel"){
                            diesel++;
                        }else
                            if(lista[i].combustivel == "Gasolina"){
                                gasolina++;
                            }else
                                if(lista[i].combustivel == "Etanol"){
                                    etanol++;
                                }
                    if(lista[i].potencia == "1.0" && lista[i].valor <= barato && lista[i].valido == true){
                        barato = lista[i].valor;
                        modelobarato = lista[i].modelo;
                        placa1 = lista[i].placa;
                    }
                    if(lista[i].direcao == "Hidráulica" && lista[i].cambio == "Automático" && lista[i].valor >= caro
                            && lista[i].valido == true){
                        caro = lista[i].valor;
                        modelocaro = lista[i].modelo;
                        placa2 = lista[i].placa;
                    }
                    
                    if(lista[i].ano <= 2019 ){
                        velhos++;
                        kmvelhos = kmvelhos + lista[i].quilometragem;
                    }
                    
                    if(lista[i].valido == true){
                        validos++;
                    }
                        
                    
                }
                
                //cálculos de porcentagem dos tipos
                hatch = hatch*100 / validos;
                seda = seda*100 / validos;
                suv = suv*100 / validos;
                picape = picape*100 / validos;
                van = van*100 / validos;
                
                cout<<"Porcentagem das categorias por tipo: "<<endl;
                cout<<"Hatch: "<<hatch<<endl;
                cout<<"Sedã: "<<seda<<endl;
                cout<<"SUV: "<<suv<<endl;
                cout<<"Pick-up: "<<picape<<endl;
                cout<<"Van: "<<van<<endl<<endl;
                
                //cálculos de porcentagem por combustível
                gasolina = gasolina*100 / validos;
                etanol = etanol*100 / validos;
                flex = flex*100 / validos;
                diesel = diesel*100 / validos;
                
                cout<<"Porcentagem de veículos por combustível: "<<endl;
                cout<<"Gasolina: "<<gasolina<<endl;
                cout<<"Etanol: "<<etanol<<endl;
                cout<<"Flex: "<<flex<<endl;
                cout<<"Diesel: "<<diesel<<endl<<endl;
                
                //cálculo da parcela
                parcela =  barato *  pow((1+(1.56/100)), 60) * (1+0.38/100) - barato;
                /* o valor do montante foi calculado considerando taxa de juros de 1,56% (média
                 * das 30 menores taxas do BCB de janeiro a maio de 2024), e considerando taxa de IOF
                 * (Imposto sobre Operações Financeiras) atual de 1,38% */
                
                
                cout<<endl<<"Veículo mais barato, com potência igual a 1.0: "<<modelobarato<<" ("<<placa1<<"). Preço: R$"
                        <<barato;
                cout<<endl<< "Valor total do veículo dividido em 60 parcelas, com juros: R$"<<parcela<<endl;
                parcela = parcela/60;
                cout<<"Valor de cada parcela: R$"<<parcela<<endl<<endl;
                
                
                //cálculo do seguro
                seguro = 5.8/100 * caro;
                /*De acordo com o índice de preços do seguro auto (IPSA), em Abril de 2024, o valor do seguro
                 * era de, em média, 5,8% sobre o valor do carro, aproximadamente */
                
                cout<< "Veículo mais caro, com direção hidráulica e câmbio automático: "<<modelocaro<<" ("<<placa2<<"). Preço: R$"
                        <<caro;
                cout<<endl<<"Valor do seguro estimado sobre o valor do carro: R$"<<seguro<<endl<<endl;
                
                cout<<endl<<"Quantidade de veículos com 5 anos ou mais: "<<velhos;
                cout<<endl<<"Média de quilômetragem: "<<kmvelhos/velhos<<endl<<endl;
                
                break;
                
        }
        
    }while(opcao != 0);
    
    cout<<"Obrigada por acessar!"<<endl<<endl;
    cout<<"Lista final: "<<endl;
    
    for(i=0; i<qtd; i++){
        if(lista[i].valido == true){
            cout<< lista[i].modelo<<" ";
            cout<< lista[i].marca<<" ";
            cout<< lista[i].tipo<<" ";
            cout<< lista[i].ano<<" ";
            cout<< lista[i].quilometragem<<" ";
            cout<< lista[i].potencia<<" ";
            cout<< lista[i].combustivel<<" ";
            cout<< lista[i].cambio<<" ";
            cout<< lista[i].direcao<<" ";
            cout<< lista[i].cor<<" ";
            cout<< lista[i].portas<<" ";
            cout<< lista[i].placa<<" ";
            cout<< lista[i].valor<<" ";
            cout<<endl;
        }
    }
    
    ofstream arquivo2("BD_veiculos.txt");
    
    for(i=0; i<qtd; i++){
        if(lista[i].valido == true){
            arquivo2<< lista[i].modelo<<" ";
            arquivo2<< lista[i].marca<<" ";
            arquivo2<< lista[i].tipo<<" ";
            arquivo2<< lista[i].ano<<" ";
            arquivo2<< lista[i].quilometragem<<" ";
            arquivo2<< lista[i].potencia<<" ";
            arquivo2<< lista[i].combustivel<<" ";
            arquivo2<< lista[i].cambio<<" ";
            arquivo2<< lista[i].direcao<<" ";
            arquivo2<< lista[i].cor<<" ";
            arquivo2<< lista[i].portas<<" ";
            arquivo2<< lista[i].placa<<" ";
            arquivo2<< lista[i].valor<<" ";
            arquivo2 <<endl;
        }
    }
    
    arquivo2<< "FIM";
    
    arquivo.close();

    return 0;
}

