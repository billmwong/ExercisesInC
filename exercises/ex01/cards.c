#include <stdio.h>
#include <stdlib.h>

int get_count_diff(int val) {
  if ((val > 2) && (val < 7)) {
    return 1;
  } else if (val == 10) {
    return -1;
  }
  return 0;
}

int get_card_val(char* card_name)
{
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      return 10;
    case 'A':
      return 11;
    default:
      return atoi(card_name);
  }
}

int main()
{
  char card_name[3];
  int count = 0;
  while (card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    if (card_name[0] == 'X') {
      continue;
    }

    int val = get_card_val(card_name);

    if ((val < 1) || ((val > 10) && (card_name[0] != 'A'))) {
      puts("I don't understand that value!");
      continue;
    }

    count += get_count_diff(val);

    printf("Current count: %i\n", count);
  }
  return 0;
}
