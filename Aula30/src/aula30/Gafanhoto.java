package aula30;
public class Gafanhoto extends Pessoa {
    private String Login;
    private int totAssistido;

    public Gafanhoto(String Login, String nome, int idade, String sexo) {
        super(nome, idade, sexo);
        this.Login = Login;
        this.totAssistido = 0;
    }

    public int getTotAssistido() {
        return totAssistido;
    }

    public void setTotAssistido(int totAssistido) {
        this.totAssistido = totAssistido;
    }

    public String getLogin() {
        return Login;
    }

    public void setLogin(String Login) {
        this.Login = Login;
    }

    public void viuMaisUm() {
        totAssistido++;
    }

    @Override
    public String toString() {
        return "Gafanhoto{" + super.toString() + "Login=" + Login + ", totAssistido=" + totAssistido + '}';
    }

}
