public class ErroLexico extends RuntimeException {

    private char caractereEncontrado;
    private String caracteresAceitos;

    // Método para guardar o caractere errado
    public ErroLexico(char caractereEncontrado, String caracteresAceitos) {
        this.caractereEncontrado = caractereEncontrado;
        this.caracteresAceitos = caracteresAceitos;
    }

    @Override
    public String toString() {
        return "Caractere não pertencente à linguagem: " + ((char) this.caractereEncontrado) + "\nOs caracteres aceitos são: " + this.caracteresAceitos;
    }

}