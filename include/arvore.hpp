/*class arvoreNo{
    public:
        charNo();
    private:
        charItem item;
        charNo *esq;
        charNo *dir;
        friend class ArvoreBinaria;
}

class ArvoreBinaria:{ // Insere e limpa pode reaproveitar talvez
  public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    //void Insere( char item);
    void Caminha( int tipo);
    void limpa();
  private:
    void InsereRecursivo (charNo* &p, char item);
    void ApagaRecursivo(charNo* p);
    void PorNivel();
    void PreOrdem(charNo* p);
    void InOrdem(charNo* p);
    void PosOrdem(charNo* p);
    charNo* raiz;
  
} */

class arvoreNo{
    public:
        charNo(){
          item.SetChave(-1);
          esq = NULL;
          dir = NULL;
        }
    private:
        charItem item;
        charNo *esq;
        charNo *dir;
        friend class ArvoreBinaria;
}

clas ArvoreBinaria{
  public:
  ArvoreBinaria(){
    raiz= NULL;
  }
  ~ArvoreBinaria(){
    Limpa();
  }
  void Insere(char item){
    InsereRecursivo( raiz,item);
  }
  void InsereRecursivo (charNo* &p, char item){
    if(p==NULL){
      P= new CharNo();
      p-> item=item;
    }
    else{
      if(item.GetChave() < p->item.GetChave())
          InsereRecursivo(p->esq,item);
        else
          InsereRecursivo(p -> dir,item);
    }
    }

  void PreOrdem(CharNo *p)
  }


