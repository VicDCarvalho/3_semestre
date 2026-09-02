package Lista;

public class lista{
    private Object[] elementos;
    private int tamanho;


//Construtor 
    public lista(int total){
        this.elementos = new Object[total];
        this.tamanho = 0;
    }


    public void adicionar_fim(Object o){
        this.elementos[tamanho] =  o ;
        this.tamanho += 1;
    }

    public void adicionar_meio(Object o, int pos){
        int i;
        for(i=this.tamanho;i<pos;i--){
            this.elementos[i] = this.elementos[i-1];
        }
        this.elementos[pos] = o;
        this.tamanho += 1;
    }

    public int busca(Object o){
        int pos=-1;
        int i;
        for(i=0;i<this.tamanho;i++){
            if(this.elementos[i].equals(o)){
                pos = i;
                break;
            }
        }
        return pos;
    }

    public boolean contem(Object o){
        boolean result;
        int saida;
        saida = busca(o);
        if(saida == -1)
            result = false;
        else
            result = true;

        return result;
    }

    public void remover(Object o){
        int pos=busca(o), i;
        if(pos != -1){
            for(i=pos; i<this.tamanho-1;i++){
                this.elementos[i] = this.elementos[i+1];
            }
            this.elementos[tamanho-1] = null;
            this.tamanho -=1;
        }

    }

    public void imprimir(){
        int i;
        for(i=0;i<this.tamanho;i++){
            System.out.println(this.elementos[i]);
        }

    }

    public int getTamanho(){
        return this.tamanho;
    }
}