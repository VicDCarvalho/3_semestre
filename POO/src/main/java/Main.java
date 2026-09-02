import sistemabiblioteca.*;

public class Main{
    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();
        for(int i=0;i<4;i++){
            biblioteca.cadastrarLivros();
        }
        biblioteca.listarLivros();
    }
}
