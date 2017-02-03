/*
Keeps a running count of cards in Blackjack
Bill Wong
*/

#include <stdio.h>
#include <stdlib.h>

/*Returns the difference in the count that a given card value will do

  val: the integer value of the card in Blackjack
*/
int get_count_diff(int val)
{
  if ((val > 2) && (val < 7)) {
    return 1;
  } else if (val == 10) {
    return -1;
  }
  return 0;
}

/*Returns the integer card value of a certain card

  card_name: the character array of of the name of the card
*/
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

/*Main function that keeps a running count of the hand. Continually prompts the
  user for a new card in the hand.
*/
int main()
{
  char card_name[3];
  int count = 0;
  while (card_name[0] != 'X') {
    int val;
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    if (card_name[0] == 'X') {
      continue;
    }

    val = get_card_val(card_name);

    if ((val < 1) || ((val > 10) && (card_name[0] != 'A'))) {
      puts("I don't understand that value!");
      continue;
    }

    count += get_count_diff(val);

    printf("Current count: %i\n", count);
  }
  return 0;
}
