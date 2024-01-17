#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int totalIngressos = 100;
int ingressosVendidos = 0;
int cont_Oppeheimer = 0, cont_Mario = 0, cont_Anabelle = 0;
int contador = 0, cont_Feminino = 0, cont_Masculino = 0, cont_Desconto = 0;
int cont_ComumF = 0, cont_MediaF = 0, cont_VipF = 0, cont_ComumM = 0, cont_MediaM = 0, cont_VipM = 0;
int contAvaliacao = 0, avaliacao;
int cont_Avaliacao0 = 0, cont_Avaliacao1 = 0, cont_Avaliacao2 = 0, cont_Avaliacao3 = 0, cont_Avaliacao4 = 0, cont_Avaliacao5 = 0;
int quantidade, totalC, totalM, totalV;
int totalPessoas;
char sessao;
char opc_Desconto;
char sexo;
char filme;
float somaC = 0, somaM = 0, somaV = 0, somaTotal = 0;
float valorIngresso;
float porcentagemTotal;
const float SESSAO_COMUM = 20.00, SESSAO_MEDIA = 26.50, SESSAO_VIP = 40.00;
const float DESCONTO_ESTUDANTE = 0.25;

int main()
{
    setlocale(LC_ALL, "portuguese");

    printf("\nBem-vindo ao sistema de venda de ingressos de cinema!\n");
 
    while (1)
    { // Loop infinito até que o usuário saia
        printf("\nMenu:\n");
        printf("1. Comprar ingresso\n");
        printf("2. Verificar disponibilidade de ingressos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        int opcao;
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1: // Processamento para a compra de ingressos
            if (totalIngressos > 0)
            {
                printf("\nInforme a quantidade de ingressos: ");
                scanf("%d", &quantidade);
                fflush(stdin);

                printf("\nInforme o seu sexo: Feminino - [F] ou Masculino [M]: ");
                scanf(" %c", &sexo);
                fflush(stdin);

                if (sexo == 'F' && sexo == 'f')
                {
                    // Cada sessão tem um valor
                    printf("\nEscolha a sessão: Comum [C], Média [M], Vip [V]: ");
                    scanf(" %c", &sessao);
                    fflush(stdin);
                    if (sessao == 'c' || sessao == 'C')
                    {
                        valorIngresso = quantidade * SESSAO_COMUM;
                        cont_ComumF++;
                    }
                    else if (sessao == 'm' || sessao == 'M')
                    {
                        valorIngresso = quantidade * SESSAO_MEDIA;
                        cont_MediaF++;
                    }
                    else if (sessao == 'v' || sessao == 'V')
                    {
                        valorIngresso = quantidade * SESSAO_VIP;
                        cont_VipF++;
                    }
                    while (sessao != 'c' && sessao != 'C' && sessao != 'm' && sessao != 'M' && sessao != 'v' && sessao != 'V')
                    {
                        printf("\nDigite novamente a sessão:");
                        scanf("%c", &sessao);
                    }
                    cont_Feminino++;
                }
                else
                {
                    // Cada sessão tem um valor
                    printf("\nEscolha a sessão: Comum [C], Média [M], Vip [V]: ");
                    scanf(" %c", &sessao);
                    fflush(stdin);
                    if (sessao == 'c' || sessao == 'C')
                    {
                        valorIngresso = quantidade * SESSAO_COMUM;
                        cont_ComumM++;
                    }
                    else if (sessao == 'm' || sessao == 'M')
                    {
                        valorIngresso = quantidade * SESSAO_MEDIA;
                        cont_MediaM++;
                    }
                    else if (sessao == 'v' || sessao == 'V')
                    {
                        valorIngresso = quantidade * SESSAO_VIP;
                        cont_VipM++;
                    }
                    while (sessao != 'c' && sessao != 'C' && sessao != 'm' && sessao != 'M' && sessao != 'v' && sessao != 'V')
                    {
                        printf("\nDigite novamente a sessão:");
                        scanf("%c", &sessao);
                    }
                    cont_Masculino++;
                }

                totalIngressos -= quantidade;
                ingressosVendidos += quantidade;

                if (totalIngressos == 0)
                {
                    printf("Desculpe, todos os ingressos estão esgotados.\n");
                    return 0;
                }

                // Desconto estudante
                printf("\nVocê é estudante? (S/N): ");
                scanf(" %c", &opc_Desconto);
                fflush(stdin);

                if (opc_Desconto == 'S' || opc_Desconto == 's')
                {
                    printf("\nVocê ganhou um desconto de 25 por cento!!!");
                    valorIngresso -= DESCONTO_ESTUDANTE * valorIngresso;
                    cont_Desconto++;
                }
                else if (opc_Desconto == 'N' || opc_Desconto == 'n')
                {
                    printf("\nVocê não tem desconto...\n");
                }

                while (opc_Desconto != 'S' && opc_Desconto != 's' && opc_Desconto != 'N' && opc_Desconto != 'n')
                {
                    printf("\nInforme novamente, se você é estudante ou não:");
                    scanf("%c", &opc_Desconto);
                }

                // Escolha dos filmes disponíveis
                printf("\n*Filmes disponíveis*\n");
                printf("\n1. Oppenheimer - classificação [12]\nSinopse: O físico J. Robert Oppenheimer trabalha com uma equipe de cientistas durante o Projeto Manhattan, levando ao desenvolvimento da bomba atômica.");
                printf("\n\n2. Super Mario - classificação [L]\nSinopse: Mario é um encanador junto com seu irmão Luigi. Um dia, eles vão parar no reino dos cogumelos, governado pela Princesa Peach, mas ameaçado pelo rei dos Koopas, que faz de tudo para conseguir reinar em todos os lugares.");
                printf("\n\n3. Annabelle - classificação [16]\nSinopse: Os investigadores paranormais Ed e Lorraine Warren mantêm a boneca Annabelle trancada em uma sala de artefatos em sua casa. No entanto, em uma noite terrível, Annabelle desperta outros espíritos malignos e ameaça a jovem filha do casal e suas amigas.");
                printf("\n\nEscolha o filme: Oppenheimer [1], Super Mario [2] e Annabelle [3]: ");
                scanf("%d", &filme);
                fflush(stdin);

                if (filme == 1)
                {
                    cont_Oppeheimer++;
                    printf("\nVocê escolheu o filme Oppenheimer! Divirta-se :)");
                }
                else if (filme == 2)
                {
                    cont_Mario++;
                    printf("\nVocê escolheu o filme Super Mario! Divirta-se :)");
                }
                else if (filme == 3)
                {
                    cont_Anabelle++;
                    printf("\nVocê escolheu o filme Annabelle! Divirta-se :)");
                }

                // Avaliação do cliente sobre o sistema
                printf("\nAntes de encerrar, por favor, dê uma nota de avaliação para o nosso sistema de 0 a 5: ");
                scanf("%d", &avaliacao);
                fflush(stdin);

               

                printf("\nO total de ingressos é R$%.2f", valorIngresso);
                printf("\nA quantidade de ingressos é: %d", quantidade);
                printf("\nO filme escolhido foi o: %d", filme);
                fflush(stdin);

                contador++;
                totalC = cont_ComumF + cont_ComumM;
                totalM = cont_MediaF + cont_MediaM;
                totalV = cont_VipF + cont_VipM;
                somaC = somaC + totalC;
                somaM = somaM + totalM;
                somaV = somaV + totalV;
                somaTotal = somaTotal + contador;
            }
            break;

        case 2:
            printf("\nIngressos disponíveis: %d", totalIngressos);
            printf("\nIngressos vendidos: %d", ingressosVendidos);

            break;

        case 3:
            printf("Obrigado por usar nosso sistema. Adeus!\n");
            return 0;

        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}
