package sistemabiblioteca;

public class Usuario{
    private String nome;
    private int matricula;

    public Usuario(String nome, int matricula){
        this.nome = nome;
        this.matricula = matricula;
    }

    public void pegar_livro(Livro book){
        if(book.getDisponivel() == 1){
            book.setDisponivel(0);
            System.out.println("Empréstimo realizado");       
        }else
            System.out.println("Livro não está disponvível");
    }

    public void devolver_livro(Livro book){
        book.setDisponivel(1);
        System.out.println("Devolução realizada");
    }
}
