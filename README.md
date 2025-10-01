# C++: Ávore de Busca Binária (Binary Search Tree)

Este é um projeto C++ e estruturado que implementa uma estrutura de dados de Ávore de Busca Binária (Binary Search Tree) genérica.

## Árvore Binária enquanto um tipo de Grafo

Em teoria dos grafos, uma árvore é um grafo que atende a duas condições essenciais:

1. **É conexo**: Todos os pontos (vértices) estão ligados entre si.
2. **É acíclico**: Não possui ciclos, ou seja, não há caminhos fechados.

Uma Árvore Binária é um caso particular de árvore onde cada nó tem, no máximo, dois filhos.

## Estrutura de Diretórios

```
.
├── .gitignore         # Arquivos e pastas a serem ignorados pelo Git
├── README.md          # Este arquivo
├── build/             # (Vazio) Onde os executáveis são criados
├── include/
│   ├── BinarySearchTree.hpp      # Interface e implementação da classe template
│   ├── Sale.hpp                  # Interface e implementação da classe de vendas
│   └── SalesHistoryTree.hpp      # Implementação especializada de uma BinarySearchTree para histórico de vendas
└── src/
    └── main.cpp       # Código principal que demonstra o uso da Árvore
```

## Como Usar

### Pré-requisitos

1.  **Compilador C++**: Um compilador moderno como o g++ (MinGW-w64 no Windows ou `build-essential` no Linux).
2.  **Git**: Para controle de versão.

### 1. Compilação

Abra um terminal na pasta raiz do projeto.

#### No Windows (PowerShell ou CMD)

```powershell
g++ src/main.cpp -Iinclude -o build/bst_app.exe
```

#### No Linux / macOS

```bash
g++ src/main.cpp -Iinclude -o build/bst_app
```

### 2. Execução

#### No Windows (PowerShell ou CMD)

```powershell
.\build\bst_app.exe
```

#### No Linux / macOS

```bash
./build/bst_app
```

### Saída Esperada

Após executar o programa, você verá a seguinte saída no terminal, confirmando que tudo funcionou corretamente:

```
--- 1. Criacao da Binary Search Tree (BST) ---
Imprimindo valores em ordem da BST A: 
10; 15; 20; 21; 23;

--- 2. Verificar ocorrencia de valores ---
Existe valor 5? nao
Existe valor 21? sim

--- 3. Remocao de no folha ---
10; 15; 20; 21; 23;
10; 15; 20; 21;

--- 4. Remocao de no com um filho ---
10; 15; 20; 21;
15; 20; 21;

--- 5. Remocao de no com dois filhos ---
15; 20; 21;
15; 21;

--- 6. Altura da Arvore ---
Altura da arvore bstB: 4

--- 7. Nos da Arvore ---
Quantidade de nos da arvore bstB: 8

--- 8. Folhas da Arvore ---
Quantidade de folhas da arvore bstB: 3

--- 9. Similaridade de arvores ---
A arvore bstC e similar a bstD? nao

--- 10. Arvore estritamente binaria ---
A arvore bstE e estritamente binaria? nao

--- 11. Comparacao de arvores ---
A arvore bstX e igual a bstY? sim

--- 12. Maior valor da arvore ---
O maior valor da arvore bstB e: 23

--- 13. Testando a SalesHistoryTree ---
## Historico de Vendas (usando metodo herdado 'inorder'):
Sale(Date: 20220820, Total: 950.25); Sale(Date: 20230410, Total: 850); Sale(Date: 20230915, Total: 1200.5); Sale(Date: 20230920, Total: 1800); Sale(Date: 20231105, Total: 2500.75);

--------------------------------------------
## Testando Tendencia de Vendas:
Resultado: Tendencia de ALTA

--------------------------------------------
## Testando Maior Venda Diaria:
Maior venda registrada: Sale(Date: 20231105, Total: 2500.75)

--------------------------------------------
## Removendo vendas anteriores a 20230101...

Historico Apos Remocao:
Sale(Date: 20230410, Total: 850); Sale(Date: 20230915, Total: 1200.5); Sale(Date: 20230920, Total: 1800); Sale(Date: 20231105, Total: 2500.75);

--------------------------------------------
```