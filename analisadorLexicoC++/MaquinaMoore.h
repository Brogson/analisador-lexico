//Linguagens formais e autômatos - Analisador Léxico
//Leandro Grazziotin e Victor Toniato

#ifndef MAQUINAMOORE_H
#define MAQUINAMOORE_H

#include "AnalisadorLexico.h"

class MaquinaMoore : public AnalisadorLexico {
public:
    explicit MaquinaMoore(const std::string& nome);

    void s0();
    void s1();
    void s2();
    void s3();
    void s4();
    void s5();
    void s6();
    void s7();
    void s8();
    void s9();
    void s10();
};

#endif