#include <vga.h>

void printf(const char *format, ...) {
  const char *p = format;
  va_list args;
  va_start(args, format);

  while (*p) {
    if (*p == '%') {
      p++;

      switch (*p) {

        // Для целых чисел
        case 'd': { 
          int i = va_arg(args, int);
          print_int(i);
          break;
        }

        // Для строк
        case 's': {
          char *s = va_arg(args, char *);
          print_str(s);
          break;
        }

        default:
          print_char(*p);
          break;
      }
       
    } else {
      print_char(*p);
    }

    p++;
  }

  va_end(args);
}
