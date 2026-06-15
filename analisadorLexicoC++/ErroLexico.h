//Linguagens formais e autômatos - Analisador Léxico
//Leandro Grazziotin e Victor Toniato

#ifndef ERROLEXICO_H
#define ERROLEXICO_H

#include <exception>
#include <string>

class ErroLexico : public std::exception {
private:
    char caractereEncontrado;
    std::string caracteresAceitos;
    std::string mensagem;

public:
    ErroLexico(char caractereEncontrado,
               const std::string& caracteresAceitos);

    const char* what() const noexcept override;
};

#endif