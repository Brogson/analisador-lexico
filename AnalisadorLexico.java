import java.io.FileReader;
import java.io.IOException;

public class AnalisadorLexico implements Constantes {

    protected String nome;
    protected char proximoCaractere;
    protected int linha = 1;
    protected StringBuffer entrada = new StringBuffer();
    protected int posicao = 0;
    protected Token tokenReconhecido;

    public AnalisadorLexico(String nome) {
        this.nome = nome;
        try {
            FileReader file = new FileReader(nome);
            int c;
            while((c = file.read()) != -1) {
                this.entrada.append((char) c);
            }
            file.close();
            leProxCaractere();
        }

        catch (IOException erro) {
            throw new RuntimeException("Erro de leitura no arquivo" + nome);
        }
    }

    public AnalisadorLexico() {
        this.nome = "entrada.txt";
        try {
            FileReader file = new FileReader(nome);
            int c;
            while((c = file.read()) != -1) {
                this.entrada.append((char) c);
            }
            file.close();
            leProxCaractere();
        }

        catch (IOException erro) {
            throw new RuntimeException("Erro de leitura no arquivo" + nome);
        }
    }

    public void leProxCaractere() {
        try {
            this.proximoCaractere = this.entrada.charAt(this.posicao);
            posicao++;
        }

        catch (IndexOutOfBoundsException e) {
            this.proximoCaractere = EOF.charAt(0);
        }
    }

    public boolean proximoCaractereIs(String s) {
        return (s.indexOf(this.proximoCaractere) != -1);
    }
}