# 🏧 Caixa Eletrônico (ATM Terminal) em C

Simulador de terminal bancário interativo desenvolvido em linguagem C. O projeto implementa operações essenciais de um caixa eletrônico (saques, depósitos e consulta de saldo em tempo real) com validação de entrada e um **algoritmo de distribuição balanceada de cédulas**.

---

## 📌 Funcionalidades

- **Saldo Persistente em Memória:** O saldo inicial (padrão de R$ 500) é atualizado dinamicamente a cada transação durante a execução.
- **Operação de Depósito:**
  - Validação de valores estritamente positivos.
  - Verificação de compatibilidade com as cédulas aceitas (múltiplos de 5).
- **Operação de Saque:**
  - Verificação de saldo disponível.
  - Restrição de valores aos múltiplos de 5.
  - **Distribuição Balanceada de Cédulas:** Em vez de utilizar apenas uma abordagem puramente gulosa (priorizando unicamente notas de 100), o terminal busca diversificar o troco do cliente:
    1. **Fase Homogênea:** Para cada R$ 185,00 (soma de $100 + 50 + 20 + 10 + 5$), entrega-se ao menos uma nota de cada denominação.
    2. **Fase Cíclica:** O restante é distribuído de forma rotativa priorizando notas médias/baixas (`50, 20, 10, 5, 100`).
- **Tratamento de Entradas Inválidas:** Verificação do retorno de `scanf` para evitar loops infinitos caso caracteres não numéricos sejam inseridos.

---

## 💵 Cédulas Disponíveis

O sistema opera exclusivamente com as seguintes notas:
- R$ 100,00
- R$ 50,00
- R$ 20,00
- R$ 10,00
- R$ 5,00

---

## 🛠️ Como Compilar e Executar

### Pré-requisitos
- Compilador C instalado (como `gcc` ou `clang`).

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/mkzzo/ATM_Terminal_C
   cd ATM_Terminal_C
   ```

2. **Compile o código-fonte:**
   ```bash
   gcc -Wall -Wextra -std=c99 ATM.c -o atm
   ```

3. **Execute o programa:**
   - **Linux / macOS:**
     ```bash
     ./atm
     ```
   - **Windows:**
     ```cmd
     atm.exe
     ```

---

## 💻 Exemplo de Uso

```text
==================================
    CAIXA ELETRONICO - TERMINAL   
    Saldo Atual: R$ 500            
==================================
1 - Realizar Saque
2 - Realizar Deposito
0 - Encerrar
Escolha uma opcao: 1

Digite o valor do saque: 235

Saque de R$ 235 realizado com sucesso!
Notas entregues:
1 nota(s) de 100
2 nota(s) de 50
1 nota(s) de 20
1 nota(s) de 10
1 nota(s) de 5
```

---

## 📂 Estrutura Sugerida do Repositório

```text
├── docs/
│   └── documentacao-atm.pdf   # Slides projeto
├── ATM.c                      # Código-fonte principal
├── .gitignore                 # Arquivo para ignorar binários e executáveis
└── README.md                  # Apresentação e guia do projeto
```

---

## 📄 Licença

Este projeto foi desenvolvido para fins educacionais e de estudo sobre lógica de programação e algoritmos em C.
