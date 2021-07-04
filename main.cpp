#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv) {
    ifstream arq(argv[1]);
    if (!arq.is_open()) {
        perror("erro ao abrir arquivo ");
        return errno;
    }

    //lista das palavras ja lidas//

    string w;
    list <string>ordem;
    //declaração tabela hash//
    unordered_map<string, int> tab;
    int cont = 1;

    while (arq >> w) {
        //se a plalavra ja existe na tabela//
        if (tab.count(w) > 0) {
            //incrementa//
            tab[w]++;
        } else {
            tab[w] = 1;
        }
    }
    for (auto & item: tab) {
        // mostra a chave (par.first) seguido do valor (par.second)
        cout << item.first << ": " << item.second << endl;
        //adiciona em uma lista para classificar//
        ordem.push_front(item.first);

    }
    cout<<endl;
    //ordena a lista//
    ordem.sort();
    //printa a lista ordenada//
    for (auto & x: ordem) {
        // mostra a chave (par.first) seguido do valor (par.second)
        cout <<x<<": "<< tab[x]<<endl;
    }

}