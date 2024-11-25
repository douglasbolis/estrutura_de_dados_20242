#include <stdio.h>
#include <string.h>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  char num[1000];
  int i = 0, mapNumbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  scanf("%s", num);

  for (int i = 0; i < strlen(&num); i++) {
    switch (num[i]) {
      case '0':
        mapNumbers[0]++;
        break;
      case '1':
        mapNumbers[1]++;
        break;
      case '2':
        mapNumbers[2]++;
        break;
      case '3':
        mapNumbers[3]++;
        break;
      case '4':
        mapNumbers[4]++;
        break;
      case '5':
        mapNumbers[5]++;
        break;
      case '6':
        mapNumbers[6]++;
        break;
      case '7':
        mapNumbers[7]++;
        break;
      case '8':
        mapNumbers[8]++;
        break;
      case '9':
        mapNumbers[9]++;
        break;
      default:
        break;
    }
  }

  do {
    printf("%d ", mapNumbers[i]);
    i++;
  } while (i < 10);

  return 0;
}
