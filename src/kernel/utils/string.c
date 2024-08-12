#include <utils.h>

// Соединить две строки
char* concat_str(char *string_1, char *string_2) {
  size_t len1 = strlen(string_1);
  size_t len2 = strlen(string_2);                      

  char* result = malloc(len1 + len2 + 1);

  memcpy(result, string_1, len1);
  memcpy(result + len1, string_2, len2 + 1);    

  return result;
}

// Число в строку
void num_to_str(int num, char str[]) {
  int i = 0;
  int sign = 0;
  int temp = num;

  if (temp < 0) {
    sign = 1;
    temp = -temp;
  }

  do {
    temp /= 10;
    i++;
  } while (temp > 0);

  if (sign) {
    str[0] = '-';
    i++;
  }

  // convert the number to a string
  for (int j = i - 1; j >= sign; j--) {
    str[j] = (num % 10) + '0';
    num /= 10;
  }

  // null-terminate the string
  str[i] = '\0';
}

// Строку в число
int str_to_num(char str[]) {
  int num = 0;
  int sign = 1;
  int i = 0;

  // Если число в строке отрицательное
  if (str[0] == '-') {
    sign = -1;
    i++;
  }

  while (str[i] != '\0') {
    num = num * 10 + (str[i] - '0');
    i++;
  }

  return sign * num;
}

// Узнать длину строки
int strlen(char* string) {
  uint16_t i = 1;

  while(string[i++]);

  return --i;
}

// Сравнение двух строк
int str_equal(char* a, char* b) {
  int result = 1;
  while (*a == *b && *a != '\0') {
    a++;
    b++;
  }

  if (*a == '\0' && *b == '\0') {
    return 1;
  }

  if (*a > *b) {
    return 0;
  } else {
    return 0;
  }
}

// Копирование двух строк
void strncpy(char *dest, char *src, size_t n)
{
  for (size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}

// Копирование строки
char* strcpy(char* destination, const char* source) {
  char* current = destination;

  while (*source != '\0') {
    *current = *source;

    source++;
    current++;
  }

  *current = '\0';

  return destination;
}

// Проверка числа в строке
char* strchr(char* str, char ch) {
  while (*str != '\0') {
    if (*str == ch) {
      return (char*)str;
    }

    str++;
  }
  return NULL;
}

// Симовл в строку
char* char_to_str(char ch) {
	char* str = " ";
	str[0] = ch;

	return str;
}

char* strtok(char* str, char* delimiter) {
  static char* saved = NULL;

  if (str != NULL) {
    saved = str; 
  }

  if (saved == NULL) {
    return NULL;
  }

  char* token_start = saved;
  while (*token_start && strchr(delimiter, *token_start)) {
    token_start++;
  }

  if (*token_start == '\0') {
    saved = NULL;
    return NULL;
  }

  char* token_end = token_start;
  while (*token_end && !strchr(delimiter, *token_end)) {
    token_end++;
  }

  if (*token_end != '\0') {
    *token_end = '\0';
    saved = token_end + 1;
  } else {
    saved = NULL; 
  }

  return token_start;
}

char* strdup(char* str) {
  if (str == NULL) {
    return NULL; 
  }

  size_t len = strlen(str) + 1;
  char* duplicate = (char*)malloc(len); 

  if (duplicate == NULL) {
    return NULL; 
  }

  strcpy(duplicate, str);
  return duplicate;
}


int split(char *str, char delimiter, char ***result) {
  int count = 0;
  const char *temp = str;
  
  // Сначала подсчитываем количество подстрок
  while (*temp) {
    if (*temp == delimiter) {
      count++;
    }
    temp++;
  }
  
  // Учитываем последнюю подстроку
  count++;

  // Выделяем память для указателей на подстроки
  *result = malloc(count * sizeof(char *));
  if (*result == NULL) {
    return -1; // Ошибка выделения памяти
  }
  
  int index = 0;
  char *start = str;
  char *end = str;
  
  while (*end) {
    if (*end == delimiter) {
      // Выделяем память для подстроки
      size_t length = end - start;
      (*result)[index] = malloc(length + 1);
      if ((*result)[index] == NULL) {
        // Очистка уже выделенной памяти в случае ошибки
        for (int j = 0; j < index; j++) {
            free((*result)[j]);
        }
        free(*result);
        return -1; // Ошибка выделения памяти
      }
      strncpy((*result)[index], start, length);
      (*result)[index][length] = '\0'; // Завершаем строку нулевым символом
      start = end + 1; // Переходим к началу следующей подстроки
      index++;
    }
    end++;
  }
  
  // Обрабатываем последнюю подстроку
  if (start != end) {
      size_t length = end - start;
      (*result)[index] = malloc(length + 1);
      if ((*result)[index] == NULL) {
          // Очистка уже выделенной памяти в случае ошибки
          for (int j = 0; j < index; j++) {
              free((*result)[j]);
          }
          free(*result);
          return -1; // Ошибка выделения памяти
      }
      strncpy((*result)[index], start, length);
      (*result)[index][length] = '\0'; // Завершаем строку нулевым символом
  }

  return count; // Возвращаем количество подстрок
}

