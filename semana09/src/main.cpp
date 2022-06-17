#include "funcoes.hpp"

using namespace std;

/*

EXPLICACAO DO PROBLEMA

Uma cidade eh representada por uma matriz de dimensoes W (comprimeto) e H (altura)
Um ladrao cometeu um crime na cidade e a policia foi acionada 
A policia fechou as saidas da cidade por T unidades de tempo
Durante esse tempo a policia recebeu varias mesnsagens informando que o ladrao nao foi visto em uma certa area no instante t
Com essas informacoes precisamos descobrir/deduzir a localizacao exata do ladrao nos instantes de tempo t

LOGICA DO CODIGO

- ler as informacoes
- criar uma matriz da cidade para cada insante de tempo t
- verificar as informacoes recebidas e atualizar essas matrizes
- procurar a primeira localizacao exata do ladrao
- procurar a ultima localizacao exata do ladrao
- construir um grafo que representa os lugares que o ladrao pode ter passado
- rodar um algoritmo de busca, nesse caso o DFS
- informar o caminho encontrado

*/

int main(){

    int W;            // comprimento da matriz q representa a cidade
    int H;            // altura da matriz que representa a cidade
    int T;            // unidades de tempo em que a cidade ficou fechada
    int qntdMsgs;     // qntd de mensagens que serao fornecidas
    int contador = 1; // contador para auxiliar nos prints

    while(cin >> W >> H >> T){ // realiza a leitura dos primeiros dados de cada problema
        if (W == 0 && H == 0 && T == 0){ // caso os dados fornecidos forem iguais ao criterio de parada encerramos o programa
            exit(0);
        }

        printf("Robbery #%d\n", contador++);

        vector<vector<vector<bool>>> matrizes; // essa matriz tridimensional armazena as matrizes da cidade em cada tempo t
        Grafo grafo;                           // esse sera o grafo que sera usado na hora de encontrar o caminho do ladrao

        // para cada tempo t, o ladrao pode estar presente em cada celula das matrizs que representa a cidade ate que seja realizada a apuracao das mensagens fornecidas
        // para isso inicializamos a variavel 'matrizes' com true
        for (int i = 0; i < T; i++){
            vector<vector<bool>> tempo;
            for (int j = 0; j < H; j++){
                vector<bool> linha;
                for (int k = 0; k < W; k++){
                    linha.push_back(true);
                }
                tempo.push_back(linha);
            }
            matrizes.push_back(tempo);
        }

        cin >> qntdMsgs;

        int Ti;               // tempo ao qual a mensagem se refere
        int left;             // borda esquerda 
        int top;              // borda superior
        int right;            // borda direita
        int bottom;           // bordaa inferior
        bool escapou = false; // flag que verifica se o ladrao escapou ou nao

        // para cada mensagem fornecida devemos processa-las e marcar nas matrizes onde o ladrao nao foi visto
        for (int i = 0; i < qntdMsgs; i++){
            cin >> Ti >> left >> top >> right >> bottom;
            if (left == 1 && top == 1 && right == W && bottom == H){ // caso o ladrao nao tenha sido visto em nenhum lugar da cidade em algum instante de tempo t, significa que ele escapou
                escapou = true;
                break;
            }
            for (int j = top-1; j < bottom; j++){ // marcando com false onde o ladrao nao foi visto
                for (int k = left-1; k < right; k++){
                    matrizes[Ti-1][j][k] = false;
                }
            }
        }

        // caso o ladrao tenha escapado printamos isso na tela e passamos para o proximo problema
        if (escapou){
            cout << "The robber has escaped." << endl << endl;
            continue;
        }

        // aqui procuramos a primeira localizacao exata do ladrao
        for (int i = 0; i < T; i++){
            int coord_i = -1;
            int coord_j = -1;

            posicaoExata(matrizes, W, H, i + 1, &coord_i, &coord_j);
            if(coord_i != -1){
                grafo.i_exatoInicial = coord_i;
                grafo.j_exatoInicial = coord_j;
                grafo.tempoExatoInicial = i + 1;
                break;
            }
        }

        // aqui procuramos a ultima localizacao exata do ladrao
        for (int i = T - 1; i >= 0; i--){
            int coord_i = -1;
            int coord_j = -1;

            posicaoExata(matrizes, W, H, i + 1, &coord_i, &coord_j);
            if(coord_i != -1){
                grafo.i_exatoFinal = coord_i;
                grafo.j_exatoFinal = coord_j;
                grafo.tempoExatoFinal = i + 1;
                break;
            }
        }

        // caso nao tenha sido possivel encontrar nenhuma localizacao exata nao podemos concluir nada
        if (grafo.tempoExatoInicial == -1){
            cout << "Nothing known." << endl << endl;
            continue;
        }

        // caso tenha sido encontrado apenas uma localizacoa exata nos instantes de tempo t printamos ela e vamos para o proximo problema
        if (grafo.tempoExatoInicial == grafo.tempoExatoFinal){
            cout << "Time step " << grafo.tempoExatoInicial << ": The robber has been at " << grafo.j_exatoInicial << "," << grafo.i_exatoInicial << "." << endl;
            continue;
        }

        // criando o grafo que sera utilizado para procurar o caminho percorrido pelo ladrao
        int idVertice = 1;
        grafo.inicializaGrafo(matrizes, W, H, T, grafo.tempoExatoInicial, grafo.i_exatoInicial, grafo.j_exatoInicial, &idVertice);

        // apos o grafo ser construido procuramos o caminho percorrido pelo ladrao utilizando o algoritmo DFS
        vector<int>caminho;
        bool achou;
        grafo.DFS(grafo.idVerticeInicial, &caminho, &achou);

        // caso um caminho tenha sido encontrado pelo DFS printamos ele, caso contrario printamos todas as localizacoes exatas durante os instantes de tempo
        if ((int)caminho.size() > 0){
            printCaminho(caminho, grafo);
        }
        else{
            for (int i = 0; i < T; i++){
                int coord_i = -1;
                int coord_j = -1;

                posicaoExata(matrizes, W, H, i + 1, &coord_i, &coord_j);
                if(coord_i != -1){
                    cout << "Time step " << i + 1 << ": The robber has been at " << coord_j << "," << coord_i << "." << endl;
                }
            }
            cout << endl;
        }

    }

    return 0;
}