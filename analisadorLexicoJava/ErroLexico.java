public class ErroLexico extends RuntimeException {

    private char caractereEncontrado;
    private String caracteresAceitos;

    public ErroLexico(char caractereEncontrado, String caracteresAceitos) {
        this.caractereEncontrado = caractereEncontrado;
        this.caracteresAceitos = caracteresAceitos;
    }

    @Override
    public String toString() {
        String caractere;

        switch (this.caractereEncontrado) {
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
                caractere = Character.toString(this.caractereEncontrado);
        }

        return "Caractere não pertencente à linguagem: "
                + caractere
                + "\nOs caracteres aceitos são: "
                + this.caracteresAceitos;
    }
}