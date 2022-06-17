#include "DFS.hpp"

using namespace std;

/*
======================================================================================================
VERTICE
======================================================================================================
*/

Vertice::Vertice(int id, bool visitado, int t, int i, int j){
    this->id = id;
    this->visitado = visitado;
    this->t = t;
    this->i = i;
    this->j = j;
}
Vertice::~Vertice(){}

void Vertice::printInfo(){
    cout << "--------- Vertice ---------\n";
    cout << "Id                            : " << this->id << "\n" ;
    cout << "Visitado                      : " << this->visitado << "\n" ;
    cout << "T                             : " << this->t << "\n" ;
    cout << "I                             : " << this->i << "\n" ;
    cout << "J                             : " << this->j << "\n" ;
    cout << "Tamanho da lista de adjacencia: " << this->adjacencia.size() << "\n" ;
    cout << "Lista de adjacencia           : ";
    for (int i = 0; i < (int) this->adjacencia.size(); i++){
        cout << this->adjacencia[i] << " ";
    }
    cout << endl << endl;
}

/*
======================================================================================================
GRAFO
====================================================================================================== 
*/

Grafo::Grafo(){
    this->qntd_vertices = 0;

    this->tempoExatoInicial = -1;
    this->i_exatoInicial = -1;
    this->j_exatoInicial = -1;

    this->tempoExatoFinal = -1;
    this->i_exatoFinal = -1;
    this->j_exatoFinal = -1;

    this->idVerticeInicial = -1;
    this->idVerticeFinal = -1;
}
Grafo::~Grafo(){}

// essa funcao cria o grafo para podermos procurar pelo caminho
/*

A contrucao do grafo foi a parte mais "complexa" desse desafio
Supondo tres instantes de tempo (1, 2 e 3) e uma matriz 4x4 onde o valor 0 representa que o ladrao nao foi visto la e 1 que ele pode ter
passado por la

tempo 1 | tempo 2 | tempo 3
0 0 0 0 | 1 1 1 1 | 0 0 0 0
0 0 0 0 | 1 1 1 1 | 0 0 0 1
0 0 0 0 | 1 1 1 1 | 0 0 0 0
0 0 0 1 | 1 1 1 1 | 0 0 0 0

a primeira localizacao exata esta no tempo 1 com indices i=4 e j=4
a ultima localizacao exata esta no tempo 1 com indices i=2 e j=4
no tempo 2 nao foram recebidas informacoes pela policia portanto o ladrao podia estar em qualquer celula

para criar o grafo o raciocinio foi o seguinte:
- o primeiro vertice a ser criado vai ser o vertice que representa a celula no tempo=1 (i=4 j=4)
- os proximos vertices a serem criados serao as celulas que estao a uma unidade de distancia da celula atual (nao foram consideradas as celulas na diagonal) no proximo instante de tempo
- nesse exemplo as celulas que serao verificadas serao as celulas no tempo=2 com indices (i=4 j=3) e (i=3 j=4)
- para cada uma das duas celulas criadas anteriormente tambem verificaremos suas vizinhas no proximo instante de tempo
- isso sera feito ate que o tempoAtual seja igual ao tempoExatoFinal
- nesse exemplo teremos os seguintes vertices{
    - t=1(i=4 j=4) com lista de adjacencia {t=2(i=4 j=3), t=2(i=3 j=4)}
    - t=2(i=4 j=3) com lista de adjacencia { }
    - t=2(i=3 j=4) com lista de adjacencia {t=3(i=2 j=4)}
    - t=3(i=2 j=4) com lista de adjacencia { }
}

*/
void Grafo::inicializaGrafo(vector<vector<vector<bool>>> cidade, int W, int H, int T, int tempoAtual, int i_atual, int j_atual, int* id){

    // caso a celula que estamos olhando nao for true ou caso o tempoAtual passado como parametro seja invalido saimos da funcao
    if (!(cidade[tempoAtual - 1][i_atual - 1][j_atual - 1]) || tempoAtual > this->tempoExatoFinal){
        return;
    }

    // caso os valores passados como parametro correspondam aos valores do verticeInicial atualizamos essa informacao no grafo
    if (tempoAtual == this->tempoExatoInicial && i_atual == this->i_exatoInicial && j_atual == this->j_exatoInicial){
        this->idVerticeInicial = *id;
    }

    // caso os valores passados como parametro correspondam aos valores do verticeFinal atualizamos essa informacao no grafo
    if (tempoAtual == this->tempoExatoFinal && i_atual == this->i_exatoFinal && j_atual == this->j_exatoFinal){
        this->idVerticeFinal = *id;
    }

    // criamos o vertice com os valores passados como parametro
    Vertice v = Vertice(*id, false, tempoAtual, i_atual, j_atual);
    this->vertices.push_back(v);
    int idCriacao = *id;
    (*id)++;

    // caso o tempo passado com parametro seja igual ao tempo da ultima localizacao exata encontrada paramos a funcao por aqui
    if (tempoAtual == this->tempoExatoFinal){
        return;
    }

    // verificando se a celula a cima da atual no proximo tempo t possui o valor true o que significaria que o ladrao poderia estar la no proximo instante t, caso isso for verdade chamamos essa funcao recursivamente
    if (i_atual - 2 >= 0){ // em cima
        if (cidade[tempoAtual][i_atual - 2][j_atual - 1]){
            this->vertices[idCriacao - 1].adjacencia.push_back(*id);
            this->inicializaGrafo(cidade, W, H, T, tempoAtual + 1, i_atual - 1, j_atual, id);
        }
    }

    // verificando se a celula a direita da atual no proximo tempo t possui o valor true o que significaria que o ladrao poderia estar la no proximo instante t, caso isso for verdade chamamos essa funcao recursivamente
    if (j_atual < W){ // direita
        if (cidade[tempoAtual][i_atual - 1][j_atual]){
            this->vertices[idCriacao - 1].adjacencia.push_back(*id);
            this->inicializaGrafo(cidade, W, H, T, tempoAtual + 1, i_atual, j_atual + 1, id);
        }
    }

    // verificando se a celula a baixo da atual no proximo tempo t possui o valor true o que significaria que o ladrao poderia estar la no proximo instante t, caso isso for verdade chamamos essa funcao recursivamente
    if (i_atual < H){ // baixo
        if (cidade[tempoAtual][i_atual][j_atual - 1]){
            this->vertices[idCriacao - 1].adjacencia.push_back(*id);
            this->inicializaGrafo(cidade, W, H, T, tempoAtual + 1, i_atual + 1, j_atual, id);
        }
    }
    
    // verificando se a celula a esquerda da atual no proximo tempo t possui o valor true o que significaria que o ladrao poderia estar la no proximo instante t, caso isso for verdade chamamos essa funcao recursivamente
    if (j_atual -2 >= 0){ // esquerda
        if (cidade[tempoAtual][i_atual - 1][j_atual - 2]){
            this->vertices[idCriacao - 1].adjacencia.push_back(*id);
            this->inicializaGrafo(cidade, W, H, T, tempoAtual + 1, i_atual, j_atual - 1, id);
        }
    }
}

void Grafo::DFS(int vertice_inicial, vector<int>* caminho, bool* achou){

    // verifica se o vertice final foi alcancado, em caso verdadeiro eh verificado se o caminho encontrado eh valido de acordo com o tempoExatoInicial e o tempoExatoFinal, caso verdadeiro paramos a recursao
    if (vertice_inicial == this->idVerticeFinal){
        caminho->push_back(vertice_inicial); // insere o vertice final no vetor de caminho
        *achou = true; // seta a flag para true para inidicar que a recursao pode parar

        if ((int)caminho->size() != (this->tempoExatoFinal - this->tempoExatoInicial + 1)){ // caso o tamanho do caminho nao seja valido voltamos a recursao
            caminho->pop_back();
            *achou = false;
            return;
        }

        // reseta a flag visitado de todos os vertices para poder executar o DFS novamente sem problemas
        for (int i = 0; i < (int)this->vertices.size(); i++){
            this->vertices[i].visitado = false;
        }
        return;
    }

    // insere o vertice atual no vetor de caminho e marca ele como visitado
    this->vertices[vertice_inicial - 1].visitado = true;
    caminho->push_back(vertice_inicial);

    // para cada vertice alcancavel a partir do vertice atual
    for (auto i : this->vertices[vertice_inicial - 1].adjacencia){

        if (!this->vertices[i - 1].visitado){ // caso o proximo vertice nao tenha sido visitado ainda, chamamos a funcao recursivamente
            this->DFS(i, caminho, achou);

            // caso o DFS tenha encontrado um caminho valido a recursao eh aprada
            if (*achou){
                return;
            }
        }
    }
    
    // liberamos o vertice para ser visitado novamente e tiramos ele do vetor de caminho
    this->vertices[vertice_inicial - 1].visitado = false;
    caminho->pop_back();

}