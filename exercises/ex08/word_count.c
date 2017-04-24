/*
 * Prints the frequency of each word in a text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

void print_hash(gpointer key, gpointer val, gpointer user_data)
{
  printf(user_data, (char*) key, (int*) val);
}

int main()
{
  char word[100];
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  FILE *fd = fopen("test.txt", "r");

  // Loop through each word
  while (fscanf(fd, "%s", word) == 1) {
    gchar *gword = malloc(100 * sizeof(gchar));
    strcpy(gword, word);

    gpointer count = g_hash_table_lookup(hash, gword);
    if (count) {
      // Word is already in table, increment the count
      g_hash_table_replace(hash, gword, (gpointer) (count + 1));
    } else {
      // Create word in table with count of 1
      g_hash_table_insert(hash, gword, (gpointer) 1);
    }
  }
  g_hash_table_foreach(hash, print_hash, "%s: %d\n");
  return 0;
}