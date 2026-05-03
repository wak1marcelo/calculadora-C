#include <stdio.h>

double soma(double number1, double  number2);
double sub(double number1, double number2);
double mult(double number1, double number2);
double divisao(double number1, double number2);
char validacaoOpcao(void);
int calcular(double number1, double number2, char opcao, double *result);
double validarNumero(const char *mensagem);
char validarNovaOperacao (void);
void limparBuffer(void);

int main (void){
    
    double number1, number2, result;
    char opcao, novaOperacao;
    
    do
    {
        number1 = validarNumero("Digite o primeiro numero: ");
        number2 = validarNumero("Digite o segundo numero: ");

        opcao = validacaoOpcao();
    
        if (calcular(number1, number2, opcao, &result)) {
            printf("resultado = %.2lf\n", result);
        } else {
            printf("Erro: divisao por zero ou operacao invalida.\n");
        }
        
        novaOperacao = validarNovaOperacao();
        
    } while (novaOperacao == 'S' || novaOperacao == 's');
    
    return 0;
}

double soma(double number1, double number2){
    return number1 + number2;
}

double sub(double number1, double number2){
    return number1 - number2;
}

double mult(double number1, double number2){
    return number1 * number2;
}

double divisao(double number1, double number2){
    return number1 / number2;
}

char validacaoOpcao(void){
    char opcao;
    do
    {
        printf("Escolha a operação: ");
        scanf(" %c", &opcao);
        limparBuffer();

        if (opcao != '+' && opcao != '-' && opcao != '*' && opcao != '/') {
            printf("Operacao invalida. Tente novamente.\n");
        }
        
    } while (opcao != '+' && opcao != '-' && opcao != '*' && opcao != '/');
    return opcao;
}


int calcular(double number1, double number2, char opcao, double *result){
    switch (opcao)
        {
        case '+':
            *result = soma(number1, number2);
            return 1;
            
        case '-':
            *result = sub(number1, number2);
            return 1;
            
        case '*':
            *result = mult(number1, number2);
            return 1;
            
        case '/':
            if(number2 == 0){
                return 0;
            }
            *result = divisao(number1, number2);
            return 1;
        default:
            return 0;
    
    }

}

double validarNumero(const char *mensagem){
    double number;

    while (1)
    {
        printf("%s", mensagem);

        if(scanf("%lf", &number) == 1){
            limparBuffer();
            return number;
        }

        printf("Entrada invalida. Digite um numero valido.\n");

        limparBuffer();
            
    }
    
}

char validarNovaOperacao (void){
    char novaOperacao;

       do
        {
            printf("Quer fazer uma nova operacao(S/N): ");
            scanf(" %c", &novaOperacao);
            limparBuffer();

            if (novaOperacao != 'S' && novaOperacao != 's' && novaOperacao != 'N' && novaOperacao != 'n') {
                printf("Opcao invalida. Digite S ou N.\n");
        }
        } while (novaOperacao != 'S' && novaOperacao != 's' && novaOperacao != 'N' && novaOperacao != 'n');

        return novaOperacao;
}

void limparBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
    }
    
}