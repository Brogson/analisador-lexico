public class Main {
    static public MaquinaMoore scanner;
    
    public static void main(String[] args) {

        try {
            scanner = new MaquinaMoore(args[0]);
            
            // Inicia a leitura do arquivo até o EOF
            do {
                scanner.s0();
                System.out.println(scanner.tokenReconhecido);
            
            } while (scanner.tokenReconhecido != Constantes.Token.EOF);

            System.out.println("Análise léxica do arquivo" + scanner.nome + " realizada com sucesso!");
        }

        catch (ErroLexico erro) {
            System.out.println("============= ERRO LÉXICO ============= \n" + erro.toString());
        }

        catch (RuntimeException erro) {
            System.out.println("=========== ERRO =========== \n" + erro.getMessage());
        }
    }
}