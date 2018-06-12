# Hash Table
Implementação da Hash Table para a disciplina de Estrutura Básica de Dados I (EDB I)

**Desenvolvido por:**

 - Alison Hedigliranes da Silva
 - Felipe Morais da Silva

# Objetivos
 
- [x] Classe Hash-Table;

- [x] Classe Account;

- [x] Classe Hash-Entry;

## Descrição

O projeto tem por objetivo implementar uma tabela de dispersão, ou Hash Table, por meio de uma aplicação relacionada à contas bancárias. A ideia do projeto consiste em usar a tabela para armazenar as contas de maneira a utilizar o método de tratameto de colisões, encadeamento externo. Esse método consiste em usar listas encadeadas para armazenar contas que apontam para o mesmo endereço na tabela.  

## Execução

Para gerar o executável rode dentro da pasta do programa:

```
make
```
Assim será gerado um executável nomeado "hash".

Para executar o programa use:

```
./hash
```

Para apagar o executável:

```
make clean
```

## Tratamento de Erros

Atualmente o programa trata os seguintes erros:

- Ao se inserir uma conta quando não se possui mais espaço, o tamanho da tabela é aumentado.

## Arquivos do projeto

A seguir descreveremos de forma rápida alguns arquivos que estão no projeto. 

### hash-tbl.h

Responsável por gerenciar a tabela com métodos de inserção e remoção.


### account.h

Responsável por guardar as informações das contas bancárias
