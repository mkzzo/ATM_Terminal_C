#include <stdio.h>

int main() {
    int opcao;
    int saldo = 500; // Saldo que persiste e se atualiza a cada operacao
    int valorOperacao;
    int notas100, notas50, notas20, notas10, notas5;
    int restante;

    do {
    	//fase inicial
        // Interface em modo texto do terminal bancario
        printf("\n==================================\n");
        printf("    CAIXA ELETRONICO - TERMINAL   \n");
        printf("    Saldo Atual: R$ %d            \n", saldo);
        printf("==================================\n");
        printf("1 - Realizar Saque\n");
        printf("2 - Realizar Deposito\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) { // Confere se o valor inserido pelo usuário é um int
            printf("\nErro: Entrada invalida. Encerrando programa.\n");
            break;
        }

        switch (opcao) {
            case 1: // Operacao de Saque (MODO BALANCEADO)
                printf("\nDigite o valor do saque: ");
                if (scanf("%d", &valorOperacao) != 1) {// Confere se o valor inserido pelo usuário é um int
                    printf("Erro: Valor invalido.\n");
                    break;
                }

                // Validacoes da regra de negocio
                if (valorOperacao <= 0) {
                    printf("Erro: O valor do saque deve ser maior que zero.\n");
                } else if (valorOperacao > saldo) {
                    printf("Erro: Saldo insuficiente. Saldo atual: R$ %d.\n", saldo);
                } else if (valorOperacao % 5 != 0) { 
                    printf("Erro: Valor indisponivel. O caixa opera apenas com notas de 100, 50, 20, 10 e 5.\n");
                } else {
                    // Atualiza o saldo bancario
                    saldo -= valorOperacao;

                    // =========================================================
                    // DISTRIBUICAO BALANCEADA (HOMOGENEA / COM TROCO)
                    // =========================================================
                    notas100 = notas50 = notas20 = notas10 = notas5 = 0; //Zera os contadores das notas por cada saque
                    restante = valorOperacao; //Atribuimos o "valor da operação" para "restante" para podermos calcular as notas que serão entregues

                    // Passo 1: Garante 1 nota de cada para cada R$ 185
                    //Utilizamos o 185 por ser a soma de todas as notas disponiveis
                    while (restante >= 185) {
                        notas100++;
                        notas50++;
                        notas20++;
                        notas10++;
                        notas5++;
                        restante -= 185; //Utilizamos o 185 por ser a soma de todas as notas disponiveis
                    }

                    // Passo 2: Distribuir ciclicamente
                    //variavel "mudou" é booleana
                    
                    int mudou = 1; //Caso o valor da operação seja menor que 185 ou o resto seja menor, entra nesse loop
                    int ordemCiclica[] = {50, 20, 10, 5, 100};//Priorizamos entregar notas menores que apenas notas de 100
                    while (mudou && restante > 0) {
                        mudou = 0;
                        for (int i = 0; i < 5; i++) {
                            if (restante >= ordemCiclica[i]) {
                                if (ordemCiclica[i] == 100)      notas100++;
                                else if (ordemCiclica[i] == 50)  notas50++;
                                else if (ordemCiclica[i] == 20)  notas20++;
                                else if (ordemCiclica[i] == 10)  notas10++;
                                else if (ordemCiclica[i] == 5)   notas5++;

                                restante -= ordemCiclica[i];
                                mudou = 1;
                            } //Loop de entrega de notas até zerar o valor da operação
                        }
                    }

                    printf("\nSaque de R$ %d realizado com sucesso!\n", valorOperacao);
                    printf("Notas entregues:\n");
                    if (notas100 > 0) printf("%d nota(s) de 100\n", notas100);
                    if (notas50 > 0)  printf("%d nota(s) de 50\n", notas50);
                    if (notas20 > 0)  printf("%d nota(s) de 20\n", notas20);
                    if (notas10 > 0)  printf("%d nota(s) de 10\n", notas10);
                    if (notas5 > 0)   printf("%d nota(s) de 5\n", notas5);
                }
                break;

            case 2: // OPERACAO DE DEPOSITO
                printf("\nDigite o valor do deposito: ");
                if (scanf("%d", &valorOperacao) != 1) {//Confere se o valor inserido pelo usuário é um int
                    printf("Erro: Valor invalido.\n");
                    break;
                }

                if (valorOperacao <= 0) {
                    printf("Erro: O valor do deposito deve ser maior que zero.\n");
                } else if (valorOperacao % 5 != 0) {
                    printf("Erro: Deposito recusado. O caixa aceita apenas cedulas de 100, 50, 20, 10 e 5.\n");
                } else {
                    saldo += valorOperacao;
                    printf("\nDeposito de R$ %d realizado com sucesso!\n", valorOperacao);
                    printf("Novo saldo: R$ %d\n", saldo);
                }
                break;

            case 0: // ENCERRAMENTO
                printf("\nObrigado por utilizar nosso terminal bancario. Ate logo!\n\n");
                break;

            default:
                printf("\nOpcao invalida. Escolha 1, 2 ou 0.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}






