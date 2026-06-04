public interface Constantes {
    enum Token {EOF, ABREPAR, FECHAPAR, ABRECOL, FECHACOL, ABRECHV, FECHACHV, NUM, VAR, OP};

    String EOF = "\0";
    String ABREPAR = "(";
    String FECHAPAR = ")";
    String ABRECOL = "[";
    String FECHACOL = "]";
    String ABRECHV = "{";
    String FECHACHV = "}";

    String NUM = "0123456789";
    String LETRAS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String RESTO_VAR = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    String OP = "+-/*";
}