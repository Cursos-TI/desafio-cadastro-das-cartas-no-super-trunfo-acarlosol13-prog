#include <stdio.h>
#include <string.h> 

#define ATTRIBUTE_TO_COMPARE 1 // Altere para 1-5 conforme o atributo desejado


int main() {
   
    // --- Carta 1 ---
    char estado1[4];
    char codigo1[8];
    char cidade1[100];
    int populacao1;
    double area1;
    double pib1; // em bilhões de reais (entrada)
    int pontos1;

    // --- Carta 2 ---
    char estado2[4];
    char codigo2[8];
    char cidade2[100];
    int populacao2;
    double area2;
    double pib2; // em bilhões
    int pontos2;

    // Valores calculados
    double densidade1 = 0.0, densidade2 = 0.0;
    double pibReais1 = 0.0, pibReais2 = 0.0;
    double pibPerCapita1 = 0.0, pibPerCapita2 = 0.0;

    // Entrada: Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: SP): ");
    scanf(" %3s", estado1);
    printf("Codigo da Carta (ex: A01): ");
    scanf(" %7s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Populacao (inteiro): ");
    scanf("%d", &populacao1);
    printf("Area (km²) (ex: 1521.11): ");
    scanf("%lf", &area1);
    printf("PIB (em bilhoes de reais) (ex: 699.28): ");
    scanf("%lf", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // Cálculos Carta 1
    if (area1 != 0.0) densidade1 = (double)populacao1 / area1;
    pibReais1 = pib1 * 1e9; // converte bilhões -> reais
    if (populacao1 != 0) pibPerCapita1 = pibReais1 / (double)populacao1;

    // Entrada: Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: RJ): ");
    scanf(" %3s", estado2);
    printf("Codigo da Carta (ex: B02): ");
    scanf(" %7s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Populacao (inteiro): ");
    scanf("%d", &populacao2);
    printf("Area (km²) (ex: 1200.25): ");
    scanf("%lf", &area2);
    printf("PIB (em bilhoes de reais) (ex: 300.50): ");
    scanf("%lf", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Cálculos Carta 2
    if (area2 != 0.0) densidade2 = (double)populacao2 / area2;
    pibReais2 = pib2 * 1e9;
    if (populacao2 != 0) pibPerCapita2 = pibReais2 / (double)populacao2;

    // Exibe os dados e os valores calculados
    printf("\n\n========= CARTA 1 =========\n");
    printf("%s - %s\n", codigo1, cidade1);
    printf("Estado: %s\n", estado1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n========= CARTA 2 =========\n");
    printf("%s - %s\n", codigo2, cidade2);
    printf("Estado: %s\n", estado2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // Seleciona o atributo a comparar (fixo via #define)
    printf("\n\nComparacao de cartas (atributo escolhido no código):\n");

    if (ATTRIBUTE_TO_COMPARE == 1) { // POPULAÇÃO
        printf("\nAtributo: POPULACAO\n");
        printf("Carta 1 - %s: %d\n", cidade1, populacao1);
        printf("Carta 2 - %s: %d\n", cidade2, populacao2);

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (populacao1 < populacao2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (ATTRIBUTE_TO_COMPARE == 2) { // AREA
        printf("\nAtributo: AREA\n");
        printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);

        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (area1 < area2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (ATTRIBUTE_TO_COMPARE == 3) { // PIB (maior vence) - comparando em reais
        printf("\nAtributo: PIB (em reais)\n");
        printf("Carta 1 - %s: %.2f (reais)\n", cidade1, pibReais1);
        printf("Carta 2 - %s: %.2f (reais)\n", cidade2, pibReais2);

        if (pibReais1 > pibReais2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (pibReais1 < pibReais2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (ATTRIBUTE_TO_COMPARE == 4) { // DENSIDADE (MENOR vence)
        printf("\nAtributo: DENSIDADE POPULACIONAL (MENOR vence)\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", cidade1, densidade1);
        printf("Carta 2 - %s: %.2f hab/km²\n", cidade2, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (densidade1 > densidade2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (ATTRIBUTE_TO_COMPARE == 5) { // PIB PER CAPITA
        printf("\nAtributo: PIB PER CAPITA (reais)\n");
        printf("Carta 1 - %s: %.2f reais\n", cidade1, pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", cidade2, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (pibPerCapita1 < pibPerCapita2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else {
        printf("\nAtributo selecionado invalido. Edite o #define ATTRIBUTE_TO_COMPARE no topo do codigo.\n");
    }

    return 0;
}

