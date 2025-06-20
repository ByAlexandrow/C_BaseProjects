#include <stdio.h>
#include <string.h>

#define TOKENS 100
#define TOKENS_LEN 20

/**
 * @brief Краткое описание функции calculate.
 */
int calculate() { return 1; }

/**
 * @brief Краткое описание функции tokenize.
 */
int tokenize(char *input, char tokens[TOKENS][TOKENS_LEN]) {
  int count = 0;
  char *token = strtok(input, " \t\n");

  while (token != NULL && count < TOKENS_LEN) {
    strncpy(tokens[count], token, TOKENS_LEN - 1);
    tokens[count][TOKENS_LEN - 1] = '\0';
    count++;
    token = strtok(NULL, " \t\n");
  }
  return count;
}

/**
 * @brief Краткое описание функции main.
 */
int main() {
  char input[256];
  char tokens[TOKENS][TOKENS_LEN];
  int token_count;
  double result = 0.0;

  printf("Простой калькулятор на C:\n\n");
  printf(
      "Поддерживаемые операции:\n + - сложение\n - - вычитание\n : - деление\n "
      "* - умножение\n ^ - степень\n ! - факториал\n\n");
  printf("Для выхода введите -0\n");

  while (1) {
    printf("\nВведите выражение:\n");

    if (!fgets(input, sizeof(input), stdin)) {
      printf("Error: ошибка чтения ввода. -0\n");
      break;
    }

    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "-0") == 0) {
      printf("Exit.\n");
      break;
    }

    token_count = tokenize(input, tokens);
    if (token_count == 0) {
      printf("Empty input.\n");
      continue;
    }

    if (calculate(input, token_count, &result) == 0) {
      printf("%.10g\n", result);
    } else {
      printf("Calculation Error. -0\n");
      break;
    }
  }

  return 0;
}
