#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief
 */
int calculate() {}

/**
 * @brief
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
 *
 * Точка входа в программу.
 *
 */
int main() {
  char input[256];
  char tokens[TOKENS][TOKENS_LEN]
  int token_count;
  double result = 0.0;

  printf("Простой калькулятор на C:\n\n");
  printf("Поддерживаемые операции:\n + - сложение\n - - вычитание\n : - деление\n * - умножение\n ^ - степень\n ! - факториал\n\n");
  printf("Для выхода введите -0\n");

  while(1) {
    printf('\nВведите выражение:\n');

    if (!fgets(input, sizeof(input), stdin)) {
      printf("Error: ошибка чтения ввода. -0");
      break;
    }

    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "-0") == 0) {
      printf("Exit.");
      break;
    }

    token_count = tokenize(input, tokens);
    if (token_count == 0) {
      printf("Empty input.");
      continue;
    }

    if (calculate(token, token_count, &result) == 0) {
      printf("%.10g\n", result)
    } else {
      printf("Calculation Error.");
    }
  }

  return 0;
}
