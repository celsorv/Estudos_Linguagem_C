#include <iostream>
#include <string.h>

using namespace std;

struct pessoa {
  char nome[30];
  int idade;
};

typedef struct pessoa uma_pessoa;

typedef struct cachorro {
  char nome[30];
  int idade;
} um_cachorro;

struct categoria {
  char letra;
  int valor;
};


// estruturas podem ser campos de estruturas
struct familia {
  struct pessoa marido;       // ou struct uma_pessoa marido
  struct pessoa esposa;       // ou struct uma_pessoa esposa
  struct cachorro caozinho;   // ou struct um_cachorro caozinho
};

int main() {
  
  pessoa pessoa1;
  uma_pessoa pessoa2;
  um_cachorro cao1;
  um_cachorro cao2;

  struct categoria cat1 = {'A', 10};         // outra forma de inicializar os campos
  struct categoria cat2, cat3 = {'B', 12};   // cat3 é inicializada

  cat2 = cat3;  // copia os dados de cat3 para cat2

  strcpy(pessoa1.nome, "Airton");
  pessoa1.idade = 6;

  strcpy(pessoa2.nome, "Juliana");
  pessoa2.idade = 4;

  strcpy(cao1.nome, "Bob");
  cao1.idade = 8;

  strcpy(cao2.nome, "Fred");
  cao2.idade = 5;

  // -------------------------------------

  familia familia1;
  strcpy(familia1.marido.nome, "Valdemar");
  familia1.marido.idade = 40;

  strcpy(familia1.esposa.nome, "Gloria");
  familia1.esposa.idade = 38;

  strcpy(familia1.caozinho.nome, "Bidu");
  familia1.caozinho.idade = 5;

  // -------------------------------------

  printf("\n");
  printf("Sou a pessoa1, me chamo %s e tenho %d anos\n", pessoa1.nome, pessoa1.idade);
  printf("Sou a pessoa2, me chamo %s e tenho %d anos\n", pessoa2.nome, pessoa2.idade);
  printf("Este é o cao1, se chama %s e tem %d anos\n", cao1.nome, cao1.idade);
  printf("Este é o cao2, se chama %s e tem %d anos\n", cao2.nome, cao2.idade);

  pessoa1 = pessoa2;

  printf("\nCopiando pessoa2 para pessoa1, temos:\n");
  printf("Sou a pessoa1, me chamo %s e tenho %d anos\n", pessoa1.nome, pessoa1.idade);
  printf("Sou a pessoa2, me chamo %s e tenho %d anos\n", pessoa2.nome, pessoa2.idade);

  strcpy(pessoa2.nome, "Henrique"); // veja a seguir, que pessoa1 não se altera

  printf("\n");
  printf("Sou a pessoa1, me chamo %s e tenho %d anos\n", pessoa1.nome, pessoa1.idade);
  printf("Sou a pessoa2, me chamo %s e tenho %d anos\n", pessoa2.nome, pessoa2.idade);

  printf("\n");
  printf("Categoria A letra: %c valor: %d\n", cat1.letra, cat1.valor);
  printf("Categoria B letra: %c valor: %d\n", cat2.letra, cat2.valor);
  printf("Categoria C letra: %c valor: %d (copiado de B)\n", cat3.letra, cat3.valor);

  printf("\n");
  printf("Sou o marido, me chamo %s e tenho %d anos\n", familia1.marido.nome, familia1.marido.idade);
  printf("Sou a esposa, me chamo %s e tenho %d anos\n", familia1.esposa.nome, familia1.esposa.idade);
  printf("Este é o caozinho %s e tem %d anos\n", familia1.caozinho.nome, familia1.caozinho.idade);
  printf("\n");

}