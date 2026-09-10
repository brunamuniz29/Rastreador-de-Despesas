# Rastreador de Despesas CLI (C++ & SQLite3)

Aplicação em linha de comando (CLI) desenvolvida em C++ para gerenciamento financeiro pessoal, utilizando integração com banco de dados relacional SQLite3 e foco em segurança e gerenciamento de memória.

## 🚀 Funcionalidades

- [x] **Adicionar Despesa:** Gravação de novas despesas com nome, valor e categoria.
- [x] **Listar Despesas:** Leitura e exibição formatada dos registros salvos no banco de dados.
- [x] **Excluir Despesa:** Remoção segura de registros selecionados por ID.
- [ ] **Atualizar Despesa:** *(Em desenvolvimento)* Alteração de registros existentes.
- [ ] **Resumo por Categoria:** *(Em desenvolvimento)* Agrupamento e cálculo de totais por categoria.

## 🛠️ Tecnologias e Conceitos Utilizados

- **Linguagem:** C++ (Orientado a objetos e estruturas de dados)
- **Banco de Dados:** SQLite3
- **Segurança de Dados:** Uso de *Prepared Statements* (`sqlite3_prepare_v2`, `sqlite3_bind_*`) para prevenção de ataques por *SQL Injection*.
- **Controle de Versão:** Git / GitHub

## 📂 Estrutura do Código

O projeto faz uso do ciclo de vida padrão da API C do SQLite3:
1. `sqlite3_open`: Conexão e criação automática da tabela `despesas.db`.
2. `sqlite3_prepare_v2`: Compilação da instrução SQL.
3. `sqlite3_bind_*`: Passagem segura de parâmetros.
4. `sqlite3_step`: Execução do comando.
5. `sqlite3_finalize`: Liberação de memória dos ponteiros de instrução (`sqlite3_stmt`).

## 🔧 Como Compilar e Executar

### Pré-requisitos
- Compilador C++ (`g++` / MinGW / MSYS2)
- Biblioteca `sqlite3.h` e arquivo objeto `sqlite3.o` configurados.

### Compilação via Terminal
```bash
g++ main.cpp sqlite3.o -o rastreador.exe