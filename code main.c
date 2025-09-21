#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char repetir; // 's' ou 'n'

    do {
        // Limpa a tela antes de cada pedido
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // Cabeçalho simples
        printf("=========================================\n");
        printf("     Hamburgueria Toubi - Sistema de Pedidos\n");
        printf("=========================================\n\n");

        int opcao;
        double total = 0.0;

        // Variáveis para guardar o pedido
        char burger_nome[100] = "";
        double burger_preco = 0.0;
        int burger_qtd = 0;

        char bebida_nome[100] = "";
        double bebida_preco = 0.0;
        int bebida_qtd = 0;

        char sobremesa_nome[100] = "";
        double sobremesa_preco = 0.0;
        int sobremesa_qtd = 0;

        // ----- Seção Hambúrguer -----
        printf("=== Cardápio Hamburguer ===\n");
        printf("1) X-Burger Gourmet .......... R$ 15.90\n");
        printf("2) X-Salada Especial ......... R$ 16.90\n");
        printf("3) X-Bacon Premium ........... R$ 18.50\n");

        printf("\nEscolha seu hamburguer: ");
        if (scanf("%d", &opcao) != 1) return 0;

        switch (opcao) {
            case 1:
                burger_preco = 15.90;
                sprintf(burger_nome, "X-Burger Gourmet");
                break;
            case 2:
                burger_preco = 16.90;
                sprintf(burger_nome, "X-Salada Especial");
                break;
            case 3:
                burger_preco = 18.50;
                sprintf(burger_nome, "X-Bacon Premium");
                break;
            default:
                printf("Opção inválida. Encerrando.\n");
                return 0;
        }

        printf("Quantidade: ");
        if (scanf("%d", &burger_qtd) != 1) return 0;
        total += burger_preco * burger_qtd;

        // ----- Bebida -----
        char resp;
        printf("Vai querer bebida? (s/n): ");
        scanf(" %c", &resp);

        if (resp == 's' || resp == 'S') {
            printf("=== Cardápio Bebidas ===\n");
            printf("1) Refrigerante Lata ......... R$ 6.50\n");
            printf("2) Suco Natural .............. R$ 7.50\n");
            printf("3) Água Mineral .............. R$ 3.50\n");

            printf("Escolha sua bebida: ");
            if (scanf("%d", &opcao) != 1) return 0;

            switch (opcao) {
                case 1:
                    bebida_preco = 6.50;
                    sprintf(bebida_nome, "Refrigerante Lata");
                    break;
                case 2:
                    bebida_preco = 7.50;
                    sprintf(bebida_nome, "Suco Natural");
                    break;
                case 3:
                    bebida_preco = 3.50;
                    sprintf(bebida_nome, "Água Mineral");
                    break;
                default:
                    printf("Opção inválida. Nenhuma bebida adicionada.\n");
            }

            if (bebida_preco > 0) {
                printf("Quantidade: ");
                if (scanf("%d", &bebida_qtd) != 1) return 0;
                total += bebida_preco * bebida_qtd;
            }
        }

        // ----- Sobremesa -----
        printf("Vai querer sobremesa? (s/n): ");
        scanf(" %c", &resp);

        if (resp == 's' || resp == 'S') {
            printf("=== Cardápio Sobremesas ===\n");
            printf("1) Brownie com Sorvete ....... R$ 8.90\n");
            printf("2) Petit Gateau .............. R$ 9.90\n");
            printf("3) Pudim ..................... R$ 6.90\n");

            printf("Escolha sua sobremesa: ");
            if (scanf("%d", &opcao) != 1) return 0;

            switch (opcao) {
                case 1:
                    sobremesa_preco = 8.90;
                    sprintf(sobremesa_nome, "Brownie com Sorvete");
                    break;
                case 2:
                    sobremesa_preco = 9.90;
                    sprintf(sobremesa_nome, "Petit Gateau");
                    break;
                case 3:
                    sobremesa_preco = 6.90;
                    sprintf(sobremesa_nome, "Pudim");
                    break;
                default:
                    printf("Opção inválida. Nenhuma sobremesa adicionada.\n");
            }

            if (sobremesa_preco > 0) {
                printf("Quantidade: ");
                if (scanf("%d", &sobremesa_qtd) != 1) return 0;
                total += sobremesa_preco * sobremesa_qtd;
            }
        }

        // ----- Resumo -----
        printf("\n=== Resumo do Pedido ===\n");
        if (burger_qtd > 0)
            printf("%dx %s — R$ %.2f\n", burger_qtd, burger_nome, burger_preco * burger_qtd);
        if (bebida_qtd > 0)
            printf("%dx %s — R$ %.2f\n", bebida_qtd, bebida_nome, bebida_preco * bebida_qtd);
        if (sobremesa_qtd > 0)
            printf("%dx %s — R$ %.2f\n", sobremesa_qtd, sobremesa_nome, sobremesa_preco * sobremesa_qtd);

        printf("------------------------\n");
        printf("TOTAL: R$ %.2f\n", total);
        printf("Obrigado pela preferência!\n");

        // Pergunta se quer repetir
        printf("\nDeseja fazer outro pedido? (s/n): ");
        scanf(" %c", &repetir);

    } while (repetir == 's' || repetir == 'S');

    printf("\nEncerrando sistema. Até logo!\n");
    return 0;
}
