#include <iostream>
#include <stdexcept>

#include "MaquinaMoore.h"
#include "ErroLexico.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Uso: " << argv[0]
                  << " <arquivo_entrada>" << std::endl;
        return 1;
    }

    try {
        MaquinaMoore scanner(argv[1]);

        do {
            scanner.s0();

            switch (scanner.getTokenReconhecido()) {

                case Constantes::Token::ABREPAR:
                    std::cout << "ABREPAR";
                    break;

                case Constantes::Token::FECHAPAR:
                    std::cout << "FECHAPAR";
                    break;

                case Constantes::Token::ABRECOL:
                    std::cout << "ABRECOL";
                    break;

                case Constantes::Token::FECHACOL:
                    std::cout << "FECHACOL";
                    break;

                case Constantes::Token::ABRECHV:
                    std::cout << "ABRECHV";
                    break;

                case Constantes::Token::FECHACHV:
                    std::cout << "FECHACHV";
                    break;

                case Constantes::Token::NUM:
                    std::cout << "NUM";
                    break;

                case Constantes::Token::VAR:
                    std::cout << "VAR";
                    break;

                case Constantes::Token::OP:
                    std::cout << "OP";
                    break;

                case Constantes::Token::EOF_TOKEN:
                    std::cout << "EOF";
                    break;
            }

            std::cout << std::endl;

        } while (scanner.getTokenReconhecido()
                 != Constantes::Token::EOF_TOKEN);

        std::cout << "Análise léxica do arquivo "
                  << scanner.getNome()
                  << " realizada com sucesso!"
                  << std::endl;
    }

    catch (const ErroLexico& erro) {
        std::cout << "============= ERRO LÉXICO ============="
                  << std::endl
                  << erro.what()
                  << std::endl;
    }

    catch (const std::exception& erro) {
        std::cout << "=========== ERRO ==========="
                  << std::endl
                  << erro.what()
                  << std::endl;
    }

    return 0;
}