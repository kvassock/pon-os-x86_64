#include <utils.h>

// Сканкод в строку
char* scancode_convert(uint8_t scancode) {
  switch(scancode) {
    case 1:
      return "ESC";
      break;

    case 2:
      return "1";
      break;
 
    case 3:
      return "2"; 
      break;

    case 4:
      return "3"; 
      break;

    case 5:
      return "4"; 
      break;

    case 6:
      return "5"; 
      break;

    case 7:
      return "6"; 
      break;

    case 8:
      return "7"; 
      break;

    case 9:
      return "8"; 
      break;

    case 10:
      return "9"; 
      break;

    case 11:
      return "0"; 
      break;

    case 12:
      return "-"; 
      break;

    case 13:
      return "="; 
      break;

    case 14:
      return "\b";
      break;

    case 15:
      return "\t";
      break;

    case 16:
      return "q"; 
      break;

    case 17:
      return "w"; 
      break;

    case 18:
      return "e"; 
      break;

    case 19:
      return "r"; 
      break;

    case 20:
      return "t"; 
      break;

    case 21:
      return "y"; 
      break;

    case 22:
      return "u"; 
      break;

    case 23:
      return "i"; 
      break;

    case 24:
      return "o"; 
      break;

    case 25:
      return "p"; 
      break;

    case 26:
      return "["; 
      break;

    case 27:
      return "]"; 
      break;

    case 28:
      return "ENTER";
      break;

    case 29:
      return "CTRL";
      break;

    case 30:
      return "a"; 
      break;

    case 31:
      return "s"; 
      break;

    case 32:
      return "d"; 
      break;

    case 33:
      return "f"; 
      break;

    case 34:
      return "g"; 
      break;

    case 35:
      return "h"; 
      break;

    case 36:
      return "j"; 
      break;

    case 37:
      return "k"; 
      break;

    case 38:
      return "l"; 
      break;

    case 39:
      return ";"; 
      break;

    case 40:
      return "'";
      break;

    case 41:
      return "`";
      break;

    case 42:
      return "SHIFT";
      break;

    case 43:
      return "\\";
      break;

    case 44:
      return "z"; 
      break;

    case 45:
      return "x"; 
      break;

    case 46:
      return "c"; 
      break;

    case 47:
      return "v"; 
      break;

    case 48:
      return "b"; 
      break;

    case 49:
      return "n"; 
      break;

    case 50:
      return "m"; 
      break;

    case 51:
      return ","; 
      break;

    case 52:
      return "."; 
      break;

    case 53:
      return "/"; 
      break;

    case 57:
      return " ";
      break;

    case 72:
      return "UP";
      break;

    case 80:
      return "DOWN";
      break;

    case 75:
      return "LEFT";
      break;

    case 77:
      return "RIGHT";
      break;

  } 
  
  return "NULL";
}
