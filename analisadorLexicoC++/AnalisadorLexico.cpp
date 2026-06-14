#include "AnalisadorLexico.h"

#include <fstream>
#include <stdexcept>

AnalisadorLexico::AnalisadorLexico(const std::string& nome)
    : nome(nome),
      proximoCaractere(Constantes::EOF_CHAR),
      linha(1),
      entrada(""),
      posicao(0)
{
    std::ifstream arquivo(nome);

    if (!arquivo.is_open()) {
        throw std::runtime_error(
            "Erro de leitura no arquivo " + nome
        );
    }

    char c;

    while (arquivo.get(c)) {
        entrada += c;
    }

    arquivo.close();

    leProxCaractere();
}

AnalisadorLexico::AnalisadorLexico()
    : AnalisadorLexico("entrada.txt")
{
}

void AnalisadorLexico::leProxCaractere() {
    if (posicao < static_cast<int>(entrada.size())) {

        proximoCaractere = entrada[posicao];

        if (proximoCaractere == '\n') {
            linha++;
        }

        posicao++;
    }
    else {
        proximoCaractere = Constantes::EOF_CHAR;
    }
}

bool AnalisadorLexico::proximoCaractereIs(
        const std::string& s) const {

    return s.find(proximoCaractere) != std::string::npos;
}

Constantes::Token
AnalisadorLexico::getTokenReconhecido() const {
    return tokenReconhecido;
}

std::string AnalisadorLexico::getNome() const {
    return nome;
}