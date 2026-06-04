import java.io.IOException;

public class MaquinaMoore extends AnalisadorLexico {

    public MaquinaMoore(String nome) {
        super(nome);
    }

    public void s0() {
        if (this.proximoCaractereIs(ABREPAR)) {
            leProxCaractere();
            s1();
        }

        else if (this.proximoCaractereIs(ABRECOL)) {
            leProxCaractere();
            s2();
        }

        else if (this.proximoCaractereIs(ABRECHV)) {
            leProxCaractere();
            s3();
        }

        else if (this.proximoCaractereIs(FECHAPAR)) {
            leProxCaractere();
            s4();
        }

        else if (this.proximoCaractereIs(FECHACOL)) {
            leProxCaractere();
            s5();
        }

        else if (this.proximoCaractereIs(FECHACHV)) {
            leProxCaractere();
            s6();
        }

        else if (this.proximoCaractereIs(NUM)) {
            leProxCaractere();
            s7();
        }

        else if (this.proximoCaractereIs(LETRAS)) {
            leProxCaractere();
            s8();
        }

        else if (this.proximoCaractereIs(OP)) {
            leProxCaractere();
            s9();
        }

        else if (this.proximoCaractereIs(EOF)) {
            leProxCaractere();
            s10();
        }

        else {
            throw new ErroLexico(this.proximoCaractere, NUM + RESTO_VAR + OP + ABRECHV + ABRECOL + ABREPAR + FECHACHV + FECHACOL + FECHAPAR);
        }
    }

    public void s1() {
        this.tokenReconhecido = Token.ABREPAR;
    }

    public void s2() {
        this.tokenReconhecido = Token.ABRECOL;
    }

    public void s3() {
        this.tokenReconhecido = Token.ABRECHV;
    }

    public void s4() {
        this.tokenReconhecido = Token.FECHAPAR;
    }

    public void s5() {
        this.tokenReconhecido = Token.FECHACOL;
    }

    public void s6() {
        this.tokenReconhecido = Token.FECHACHV;
    }

    public void s7() {
        this.tokenReconhecido = Token.NUM;

        if (this.proximoCaractereIs(NUM)) {
            leProxCaractere();
            s7();
        }        
    }
    
    public void s8() {
        this.tokenReconhecido = Token.VAR;

        if (this.proximoCaractereIs(RESTO_VAR)) {
            leProxCaractere();
            s8();
        }
    }
    
    public void s9() {
        this.tokenReconhecido = Token.OP;
    }
    
    public void s10() {
        this.tokenReconhecido = Token.EOF;
    }
}