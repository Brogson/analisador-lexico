#ifndef CONSTANTES_H

#define CONSTANTES_H

#include <string>

namespace Constantes {

    enum class Token {
        EOF,
        ABREPAR,
        FECHAPAR,
        ABRECOL,
        FECHACOL,
        ABRECHV,
        FECHACHV,
        NUM,
        VAR,
        OP
    };

    const char EOF_CHAR = '\0';

    const std::string ABREPAR = "(";
    const std::string FECHAPAR = ")";
    const std::string ABRECOL = "[";
    const std::string FECHACOL = "]";
    const std::string ABRECHV = "{";
    const std::string FECHACHV = "}";

    const std::string NUM = "0123456789";

    const std::string LETRAS =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const std::string RESTO_VAR =
        "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    const std::string OP = "+-/*";

    const std::string SEPARADOR = "\t\r\n ";
}

#endif
