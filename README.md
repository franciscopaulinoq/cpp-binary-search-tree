# C++: Ávore de Busca Binária (Binary Search Tree)

Este é um projeto C++ e estruturado que implementa uma estrutura de dados de Ávore de Busca Binária (Binary Search Tree) genérica.

## Estrutura de Diretórios

```
.
├── .gitignore         # Arquivos e pastas a serem ignorados pelo Git
├── README.md          # Este arquivo
├── build/             # (Vazio) Onde os executáveis são criados
├── include/
│   └── BinarySearchTree.hpp      # Interface e implementação da classe template
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
10 15 20 21 23

--- 2. Verificar ocorrencia de valores ---
Existe valor 5? nao
Existe valor 21? sim

--- 3. Remocao de no folha ---
10 15 20 21 23
10 15 20 21

--- 4. Remocao de no com um filho ---
10 15 20 21
15 20 21

--- 5. Remocao de no com dois filhos ---
15 20 21
15 21
```