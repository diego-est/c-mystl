#include "mystl.h"
#include <assert.h>
#include <stdio.h>

int
main (void)
{
  /* arrays for testing */
  i32 empty[1] = { 0 };
  i32 ints[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  i32 evens[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
  i32 odds[10] = { 1, 3, 5, 7, 11, 13, 15, 17, 19, 21 };
  i32 fibs[12] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
  i32 three4[12] = { 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
  i32 upto4[4] = { 1, 2, 3, 4 };
  i32 arr[] = { 2, 2, 24, 2, 4 };

  /* all_of(), any_of(), none_of() */
  assert (all_even (evens, evens + 9) == true);
  assert (any_even (evens, evens + 9) == true);
  assert (all_odd (evens, evens + 9) == false);

  assert (all_even (ints, ints + 9) == false);
  assert (any_even (ints, ints + 9) == true);
  assert (all_odd (ints, ints + 9) == false);

  assert (all_even (odds, odds + 9) == false);
  assert (any_even (odds, odds + 9) == false);
  assert (all_odd (odds, odds + 9) == true);

  assert (all_even (empty, empty + 0) == true);
  assert (any_even (empty, empty + 0) == false);
  assert (all_odd (empty, empty + 0) == true);

  /* count() */
  assert (count (arr, arr + 5, 2) == 3);
  assert (count (arr, arr + 5, 4) == 1);

  /* mismatch() */
  ptr_pair assert_1 = { fibs + 3, ints + 3 };
  assert (mismatch (fibs, fibs + 9, ints).first == assert_1.first
          && mismatch (fibs, fibs + 9, ints).second == assert_1.second);

  /* find(), find_if(), find_if_not() */
  assert (*find (ints, ints + 9, 5) == 5);
  assert (*find_even (ints, ints + 9) == 2);
  assert (*find_odd (ints, ints + 9) == 1);

  /* find_end() */
  assert ((find_end(three4, three4 + 11, upto4, upto4 + 3) - three4) == 8);

  printf ("\n\tAll asserts completed succesfully!\n");
  return 0;
}
