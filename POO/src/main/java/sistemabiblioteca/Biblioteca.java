
package sistemabiblioteca;

import java.util.ArrayList;
import java.util.Scanner;

public class Biblioteca {
    private ArrayList<Livro> livros;
    private ArrayList<Usuario> usuarios;
    Scanner scanner = new Scanner(System.in);
    

    public Biblioteca(){
        livros = new ArrayList<>();
        usuarios = new ArrayList<>();
    }

    public void cadastrarLivros(){
        System.out.println("Cadastro de livros");
        System.out.println("Título: ");
        String nome = scanner.nextLine();

        System.out.println("Autor: ");
        String autor = scanner.nextLine();

        System.out.println("Ano de publicação: ");
        int ano = Integer.parseInt(scanner.nextLine().trim());

        Livro book = new Livro(nome, autor, ano);
        livros.add(book);
    }

    public void cadastrarUsuario(){
        System.out.println("Cadastro de usuários");
        System.out.println("Nome: ");
        String nome = scanner.nextLine();

        System.out.println("Matrícula: ");
        int mat = Integer.parseInt(scanner.nextLine().trim());

        Usuario person = new Usuario(nome, mat);
        usuarios.add(person);
    }

    public void listarLivros(){
        for(Livro livroAtual : this.livros){
            livroAtual.exibeLivro();
        }
    }

    public void listarUsuarios(){
        int i;
        for(i=0;i<usuarios.size();i++){
            System.out.println(usuarios.get(i));
        }
    }
}
