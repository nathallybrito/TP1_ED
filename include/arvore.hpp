class arvoreNo{
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
  
}
