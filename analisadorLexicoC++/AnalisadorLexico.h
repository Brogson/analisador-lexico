//Linguagens formais e autômatos - Analisador Léxico
//Leandro Grazziotin e Victor Toniato

#ifndef ANALISADORLEXICO_H

#define ANALISADORLEXICO_H

#include <string>
#include "Constantes.h"

class AnalisadorLexico {
protected:
    std::string nome;
    char proximoCaractere;
    int linha;
    std::string entrada;
    int posicao;
    Constantes::Token tokenReconhecido;

public:
    explicit AnalisadorLexico(const std::string& nome);
    AnalisadorLexico();

    void leProxCaractere();

    bool proximoCaractereIs(const std::string& s) const;

    Constantes::Token getTokenReconhecido() const;

    std::string getNome() const;

    virtual ~AnalisadorLexico() = default;
};

#endif