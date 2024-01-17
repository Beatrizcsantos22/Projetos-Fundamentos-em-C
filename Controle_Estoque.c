
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define TAM_ESTOQUE 5
int estoque[TAM_ESTOQUE];
float precos[TAM_ESTOQUE];
int produto;
int quantidade;

void pausado()
{
    printf("\n\nPressione [ENTER] para continuar");
    system("pause");
}

// Função para imprimir o estoque, incluindo os preços
void imprimirEstoque()
{
    int i = 0;
    printf("\nEstoque atual:\n");
    for (i; i < TAM_ESTOQUE; i++)
    {
        printf("Produto %d: %d unidades - Preco: R$ %.2f\n", i + 1, estoque[i], precos[i]);
    }
    pausado();
}

void adicionarAoEstoque()
{
    int i = 0;
    float preco;
    system("cls");
    printf("*Adiconar produtos no estoque*\n");

    for (i; i < TAM_ESTOQUE; i++)
    {
        printf("\nDigite o numero do %d° produto : ", i + 1);
        scanf("%d", &produto);
        if (produto >= 1 && produto <= TAM_ESTOQUE)
        {
            printf("Digite a quantidade a ser adicionada: ");
            scanf("%d", &quantidade);

            printf("Digite o preço do produto: ");
            scanf("%f", &preco);

            estoque[produto - 1] += quantidade;
            precos[produto - 1] = preco; // Definindo o preço do produto
            printf("\n => %d unidades adicionadas ao Produto %d com preço R$ %.2f.\n", quantidade, produto, preco);
        }

        else
        {
            printf("=> Produto invalido.\n");
        }
    }
    pausado();
}

void removerDoEstoque()
{

    system("cls");
    printf("*Remover produtos do estoque*");
    printf("\nDigite o numero do produto: ");
    scanf("%d", &produto);

    if (produto >= 1 && produto <= TAM_ESTOQUE)
    {
        printf("Digite a quantidade a ser removida: ");
        scanf("%d", &quantidade);

        if (quantidade <= estoque[produto - 1])
        {
            estoque[produto - 1] -= quantidade;
            printf("=> %d unidades removidas do Produto %d.\n", quantidade, produto);
        }
        else
        {
            printf("=> Quantidade insuficiente em estoque.\n");
        }
    }
    else
    {
        printf("Produto invalido.\n");
    }
    pausado();
}

void registrarVenda()
{

    printf("*Registrar Vendas dos Produtos*");
    printf("\nDigite o numero do produto vendido: ");
    scanf("%d", &produto);

    if (produto >= 1 && produto <= TAM_ESTOQUE)
    {

        printf("Digite a quantidade vendida: ");
        scanf("%d", &quantidade);

        if (quantidade <= estoque[produto - 1])
        {
            estoque[produto - 1] -= quantidade;
            printf("=> %d unidades do Produto %d vendidas.\n", quantidade, produto);
        }
        else
        {
            printf("=> Quantidade insuficiente em estoque para esta venda.\n");
        }
    }
    else
    {
        printf("Produto invalido.\n");
    }
    pausado();
}

void visualizarMaiorMenor()
{
    int i = 0;
    float maior_Produto = 0, menor_Produto = 10000;
    int indice_Maior = 0, indice_Menor = 0;

    for (i; i < TAM_ESTOQUE; i++)
    {
        if (estoque[i] > maior_Produto)
        {
            maior_Produto = estoque[i];
            indice_Maior = i + 1;
        }
        if (estoque[i] < menor_Produto)
        {
            menor_Produto = estoque[i];
            indice_Menor = i + 1;
        }
    } // fim for

    system("cls");
    printf("### Visualizar o Maior e o Menor Números de Produtos no Estoque###\n");
    printf("\n\nO Produto de Maior quantidade é: => %d", indice_Maior);
    printf("\nQuantidade do Produto com maior número no estoque:  %.2f", maior_Produto);
    printf("\n\nO Produto de Menor quantidade é: => %d", indice_Menor);
    printf("\nQuantidade do Produto com o Menor número no estoque: %.2f", menor_Produto);
    pausado();
}

float calcularValorTotalArrecadado()
{
    int i = 0;
    float valorTotal = 0;
    for (i; i < TAM_ESTOQUE; i++)
    {
        float valorVendido = (float)quantidade * precos[i];
        valorTotal += valorVendido;
    }
    printf("\nO valor total arrecadado nas vendas de produtos foi: R$ %.2f\n", valorTotal);
    pausado();
}

/*Senhor Pedroca,
A sua missão é fazer 4 funções e 4 saida de dados, fazendo com q o usuário visualize
a porcentagem  e média total de produtos no estoque, e a porcentagem e media de vendas.
Se tiver alguma ideia, fique a vontade!!*/

float mediaProdutos()
{
    int i = 0;
    float soma = 0;

    for (i; i < TAM_ESTOQUE; i++)
    {
        soma = soma + precos[i];
        printf("Media do %d produto: %.2f\n", i + 1, soma / TAM_ESTOQUE);
        getch();
    }
}

float porcentagemProdutos()
{
    int i = 0;
    float porcentagem = 0;

    for (i; i < TAM_ESTOQUE; i++)
    {
        porcentagem = (precos[i] / TAM_ESTOQUE) * 100; // Correção aqui
        printf("Porcentagem do %d produto: %.2f %%\n", i + 1, porcentagem);
        getch();
    }
}

float mediaVendas()
{
    int i = 0;
    float somaV = 0;

    for (i; i < TAM_ESTOQUE; i++)
    {
        somaV = somaV + quantidade;
        printf("Media da %d° venda: %.2f\n", i + 1, somaV / TAM_ESTOQUE);
        getch();
    }
}

float porcentagemVendas()
{
    int i = 0;
    float porcentagem = 0;

    for (i; i < TAM_ESTOQUE; i++)
    {
        porcentagem = (quantidade / TAM_ESTOQUE) * 100; // Correção aqui
        printf("Porcentagem da %d° venda: %.2f %%\n", i + 1, porcentagem);
        getch();
    }
}

int main()
{

    int escolha;
    setlocale(LC_ALL, "portuguese");
    do
    {
        system("cls");
        printf("/-----------------------------------------------------\\\n");
        printf("|-----------------------Menu--------------------------|\n");
        printf("| Escolha uma opção:                                  |\n");
        printf("| 1.  Adicionar estoque                               |\n");
        printf("| 2.  Imprimir estoque                                |\n");
        printf("| 3.  Remover do estoque                              |\n");
        printf("| 4.  Registrar venda                                 |\n");
        printf("| 5.  Visualizar Maior e Menor quantidade de Produtos |\n");
        printf("| 6.  Visualizar o valor total arrecadado             |\n");
        printf("| 7.  Visualizar média total do valor dos produtos    |\n");
        printf("| 8.  Visualizar porcentagem do valor dos produtos    |\n");
        printf("| 9.  Visualizar média total do valor dos produtos    |\n");
        printf("| 10. Visualizar porcentagem do valor dos produtos    |\n");
        printf("| 11. Sair                                            |\n");
        printf("\\----------------------------------------------------/\n");
        printf("Opcão: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            adicionarAoEstoque();
            break;
        case 2:
            imprimirEstoque();
            break;
        case 3:
            removerDoEstoque();
            break;
        case 4:
            registrarVenda();
            break;
        case 5:
            visualizarMaiorMenor();
            break;
        case 6:
            calcularValorTotalArrecadado();
            break;
        case 7:
            mediaProdutos();
            break;
        case 8:
            porcentagemProdutos();
            break;
        case 9:
            mediaProdutos();
            break;
        case 10:
            porcentagemProdutos();
            break;
        case 11:
            printf("Saindo...\n");
            abort();
            break;
        default:
            printf("opção invalida. Tente novamente.\n");
        }

    } while (escolha != 10);
}