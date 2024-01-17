#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

const float PAGAMENTOBOLETO = 0.30, PAGAMENTODEBITO = 0.20;
float valorPassagem, total, passagem, totalFinal;
int quantidadePassagem, quantidadeParcelas;
char classe, formaPagamento;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("******Passagem de ônibus***** ");
    printf("\n\nDigite o valor da sua passagem:");
    scanf("%f", &valorPassagem);
    fflush(stdin);

    printf("\n\n|Digite a quantidade de passagem(ALERTA! a quantidade de compra de passagem 10):");
    scanf("%d", &quantidadePassagem);
    fflush(stdin);

    if (quantidadePassagem <= 10)
    {
        passagem = valorPassagem * quantidadePassagem;
        printf("\n\nA quantidade de passagem é =%d o valor total R$ = %0.2f", quantidadePassagem, passagem);
    }

    else
    {
        printf("\n\nERRO!! o limite de quantidade de passagem ultrapassou, tente novamente ");
        // função que encerra o programa
        abort();
    }

    // Definição de cada classe: [E] Economico , [M] Media ,[A] Alta
    printf("\n\nEscolha a classe para viajar:Economica,Media ou Alta:[E/M/A]");
    classe = getchar();

    if (classe == 'e' || classe == 'E')
    {
        total = passagem + 0;
    }
    else if (classe == 'm' || classe == 'M')
    {
        total = passagem + 65.00;
    }

    if (classe == 'a' || classe == 'A')
    {
        total = passagem + 125.50;
    }
    printf("\nSua Passagem custa =%0.2f", total);
    fflush(stdin);

    // Forma de pagamento
    printf("\n\n******Forma de pagamento******");
    printf("\nEscolha a forma de Pagamento: Boleto[b],Crédito[c],Débito[d]");
    formaPagamento = getchar();

    if (formaPagamento == 'b' || formaPagamento == 'B')
    {
        printf("\nVoce ganhou um desconto de 30 porcento!!!");
        totalFinal = total - PAGAMENTOBOLETO;
        printf("\nO valor final de sua passagem é R$%0.2f", totalFinal);
        abort();
    }

    else if (formaPagamento == 'c' || formaPagamento == 'C')
    {
        printf("\nParcelamos ate 5x vezes!");
        printf("\nDigite a quantidade de parcelas:");
        scanf("%d", &quantidadeParcelas);
        totalFinal = total / quantidadeParcelas;
        printf("\nVoce parcelou em =%d  \nSua parcela sera cobrado a partir do proximo mês!", quantidadeParcelas);
        printf("\nO total da sua compra de passagem é  R$%0.2f", totalFinal);
        abort();
    }

    else if (formaPagamento == 'd' || formaPagamento == 'D')
    {
        printf("Voce ganhou um desconto de 25 porcento!!!");
        totalFinal = total - PAGAMENTODEBITO;
        printf("total final de sua compra é R$%0.2f", totalFinal);
        abort();
    }
    return 0;
}