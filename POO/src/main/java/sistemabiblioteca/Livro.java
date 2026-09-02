package sistemabiblioteca;

public class Livro{
    private String nome;
    private String autor;
    private int ano;
    private int disponivel = 1;

    public Livro(String nome, String autor, int ano){
        this.nome = nome;
        this.autor = autor;
        this.ano = ano;
    }

    public void exibeLivro() {
        System.out.println(this.nome + " " + this.autor + " " + this.ano);
    }

    public int getDisponivel(){
        return this.disponivel;
    }

    public void setDisponivel(int disponibilidade){
        this.disponivel = disponibilidade;
    }
}
