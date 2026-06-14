#include "ErroLexico.h"

ErroLexico::ErroLexico(char caractereEncontrado,
                       const std::string& caracteresAceitos)
    : caractereEncontrado(caractereEncontrado),
      caracteresAceitos(caracteresAceitos)
{
    std::string caractere;

    switch (this->caractereEncontrado) {

        case '\n':
            caractere = "\\n";
            break;

        case '\r':
            caractere = "\\r";
            break;

        case '\t':
            caractere = "\\t";
            break;

        case '\0':
            caractere = "EOF";
            break;

        default:
            caractere = std::string(1, this->caractereEncontrado);
    }

    mensagem =
        "Caractere não pertencente à linguagem: "
        + caractere
        + "\nOs caracteres aceitos são: "
        + this->caracteresAceitos;
}

const char* ErroLexico::what() const noexcept {
    return mensagem.c_str();
}