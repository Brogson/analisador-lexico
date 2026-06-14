#include "MaquinaMoore.h"
#include "ErroLexico.h"

MaquinaMoore::MaquinaMoore(const std::string& nome)
    : AnalisadorLexico(nome)
{
}

void MaquinaMoore::s0() {

    while (proximoCaractereIs(Constantes::SEPARADOR)) {
        leProxCaractere();
    }

    if (proximoCaractereIs(Constantes::ABREPAR)) {
        leProxCaractere();
        s1();
    }

    else if (proximoCaractereIs(Constantes::ABRECOL)) {
        leProxCaractere();
        s2();
    }

    else if (proximoCaractereIs(Constantes::ABRECHV)) {
        leProxCaractere();
        s3();
    }

    else if (proximoCaractereIs(Constantes::FECHAPAR)) {
        leProxCaractere();
        s4();
    }

    else if (proximoCaractereIs(Constantes::FECHACOL)) {
        leProxCaractere();
        s5();
    }

    else if (proximoCaractereIs(Constantes::FECHACHV)) {
        leProxCaractere();
        s6();
    }

    else if (proximoCaractereIs(Constantes::NUM)) {
        leProxCaractere();
        s7();
    }

    else if (proximoCaractereIs(Constantes::LETRAS)) {
        leProxCaractere();
        s8();
    }

    else if (proximoCaractere == Constantes::EOF_CHAR) {
        leProxCaractere();
        s10();
    }

    else if (proximoCaractereIs(Constantes::OP)) {
        leProxCaractere();
        s9();
    }

    else {
        throw ErroLexico(
            proximoCaractere,
            Constantes::NUM
            + Constantes::RESTO_VAR
            + Constantes::OP
            + Constantes::ABRECHV
            + Constantes::ABRECOL
            + Constantes::ABREPAR
            + Constantes::FECHACHV
            + Constantes::FECHACOL
            + Constantes::FECHAPAR
        );
    }
}

void MaquinaMoore::s1() {
    tokenReconhecido = Constantes::Token::ABREPAR;
}

void MaquinaMoore::s2() {
    tokenReconhecido = Constantes::Token::ABRECOL;
}

void MaquinaMoore::s3() {
    tokenReconhecido = Constantes::Token::ABRECHV;
}

void MaquinaMoore::s4() {
    tokenReconhecido = Constantes::Token::FECHAPAR;
}

void MaquinaMoore::s5() {
    tokenReconhecido = Constantes::Token::FECHACOL;
}

void MaquinaMoore::s6() {
    tokenReconhecido = Constantes::Token::FECHACHV;
}

void MaquinaMoore::s7() {

    tokenReconhecido = Constantes::Token::NUM;

    if (proximoCaractereIs(Constantes::NUM)) {

        leProxCaractere();
        s7();
    }

    else if (!(proximoCaractereIs(Constantes::SEPARADOR)
            || proximoCaractere == Constantes::EOF_CHAR
            || proximoCaractereIs(Constantes::ABREPAR)
            || proximoCaractereIs(Constantes::ABRECHV)
            || proximoCaractereIs(Constantes::ABRECOL)
            || proximoCaractereIs(Constantes::FECHAPAR)
            || proximoCaractereIs(Constantes::FECHACOL)
            || proximoCaractereIs(Constantes::FECHACHV)
            || proximoCaractereIs(Constantes::OP))) {

        throw ErroLexico(
            proximoCaractere,
            "separador ou fim de Token"
        );
    }
}

void MaquinaMoore::s8() {

    tokenReconhecido = Constantes::Token::VAR;

    if (proximoCaractereIs(Constantes::RESTO_VAR)) {

        leProxCaractere();
        s8();
    }

    else if (!(proximoCaractereIs(Constantes::SEPARADOR)
            || proximoCaractere == Constantes::EOF_CHAR
            || proximoCaractereIs(Constantes::ABREPAR)
            || proximoCaractereIs(Constantes::ABRECHV)
            || proximoCaractereIs(Constantes::ABRECOL)
            || proximoCaractereIs(Constantes::FECHAPAR)
            || proximoCaractereIs(Constantes::FECHACOL)
            || proximoCaractereIs(Constantes::FECHACHV)
            || proximoCaractereIs(Constantes::OP))) {

        throw ErroLexico(
            proximoCaractere,
            "separador ou fim de Token"
        );
    }
}

void MaquinaMoore::s9() {
    tokenReconhecido = Constantes::Token::OP;
}

void MaquinaMoore::s10() {
    tokenReconhecido = Constantes::Token::EOF_TOKEN;
}