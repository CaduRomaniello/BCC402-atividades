#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Vertice{
    public:

        //Atributos
        int id;                 // id do vertice
        bool visitado;          // flag para indicar se o vertice foi visitado
        int t;                  // indica o tempo ao qual esse vertice pertence
        int i;                  // coordenada i do vertice no tempo t
        int j;                  // coordenada j do vertice no tempo t
        vector<int> adjacencia; // vetor que contem inteiros representando o id dos vertices alcancaveis

        //Metodos
        Vertice(int id, bool visitado = false, int t = -1, int i = -1, int j = -1); // construtor
        ~Vertice(); // destrutor

        void printInfo(); // print de debug
};

class Grafo{
    public:

        //Atributos
        int qntd_vertices;        // qntd de vertices do grafo
        vector<Vertice> vertices; // vetor que armazena todos os vertices do grafo

        int tempoExatoInicial; // tempo em que foi encontrado a primeira localizacao exata do ladrao
        int i_exatoInicial;    // coordenada i em que o ladrao estava no tempoExatoInicial
        int j_exatoInicial;    // coordenada j em que o ladrao estava no tempoExatoInicial

        int tempoExatoFinal; // tempo em que foi encontrado a ultima localizacao exata do ladrao
        int i_exatoFinal;    // coordenada i em que o ladrao estava no tempoExatoFinal
        int j_exatoFinal;    // coordenada j em que o ladrao estava no tempoExatoFinal

        int idVerticeInicial; // id do vertice onde o ladrao estava no tempoExatoInicial
        int idVerticeFinal;   // id do vertice onde o ladrao estava no tempoExatoFinal

        //Metodos
        Grafo(); //construtor
        ~Grafo(); // destrutor

        // cria os vertices do grafo
        void inicializaGrafo(vector<vector<vector<bool>>> cidade, int W, int H, int T, int tempoAtual, int i_atual, int j_atual, int* id);
        // algoritmo DFS
        void DFS(int vertice_inicial, vector<int>* caminho, bool* achou);
};

#endif