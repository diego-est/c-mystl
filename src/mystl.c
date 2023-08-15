#include "mystl.h"
#include <stdio.h>

/* === non-modifying sequence algorithms === */

/* checks if all of the elements in a range are even */
bool
all_even (i32 *first, i32 *last)
{
  for (; first != last; ++first)
    if (*first % 2 == 0)
      continue;
    else
      return false;
  return true;
}

/* checks if any of the elements in a range are even */
bool
any_even (i32 *first, i32 *last)
{
  for (; first != last; ++first)
    if (*first % 2 == 0)
      return true;
    else
      continue;
  return false;
}

/* checks if all of the elements in a range are odd */
bool
all_odd (i32 *first, i32 *last)
{
  for (; first != last; ++first)
    if (*first % 2 != 0)
      continue;
    else
      return false;
  return true;
}

/* returns the number of elements equal(==) to value */
u64
count (i32 *first, i32 *last, i32 value)
{
  u64 acc = 0;
  for (; first != last; ++first)
    if (*first == value)
      acc++;
  return acc;
}

/* finds the first position where two ranges differ */
ptr_pair
mismatch (i32 *first1, i32 *last1, i32 *first2)
{
  while (first1 != last1 && *first1 == *first2)
    ++first1, ++first2;
  ptr_pair r = { first1, first2 };
  return r;
}

/* finds the first element equal(==) to value */
i32 *
find (i32 *first, i32 *last, i32 value)
{
  while (first != last && *first != value)
    ++first;
  return first;
}

/* finds the first even element */
i32 *
find_even (i32 *first, i32 *last)
{
  while (first != last && *first % 2 != 0)
    ++first;
  return first;
}

/* finds the first odd element */
i32 *
find_odd (i32 *first, i32 *last)
{
  while (first != last && *first % 2 == 0)
    ++first;
  return first;
}

/* finds the last sequence of elements in a certain range */
i32 *
find_end (i32 *first, i32 *last, i32 *s_first, i32 *s_last)
{
  if (s_first == s_last)
    return last;
  i32 *result = last;
  while (true)
    {
      i32 *new_result = search(first, last, s_first, s_last);
      if (new_result == last) break;
      else
        {
          result = new_result;
          first = result;
          ++first;
        }
    }
  return result;
}

/* searches for any one of a set of elements */
i32 *
find_first_of (i32 *first, i32 *last, i32 *s_first, i32 *s_last)
{
  (void)first;
  (void)last;
  (void)s_first;
  (void)s_last;
  return NULL;
}

/* finds the first two adjacent items that are equal(==) */
i32 *
adjacent_find (i32 *first, i32 *last)
{
  if (first == last)
    return last;

  i32 *next = first + 1;
  for (; next != last;++next, ++first)
    if(*first == *next) return first;
  return last;
}

/* searches for a range of elements */
i32 *
search (i32 *first, i32 *last, i32 *s_first, i32 *s_last)
{
  while (true)
    {
      i32 *it = first;
      for (i32 *s_it = s_first;; ++it, ++s_it)
        {
          if (s_it == s_last)
            return first;
          if (it == last)
            return last;
          if (*it != *s_it)
            break;
        }
      ++first;
    }
}

/* searches a range for a number of consecutive copies of an element */
i32 *
search_n (i32 *first, i32 *last, u64 count, i32 value)
{
  (void)first;
  (void)last;
  (void)count;
  (void)value;
  return NULL;
}

/* checks whether a range starts with another range */
bool
starts_with (i32 *first1, i32 *last1, i32 *first2, i32 *last2)
{
  for (; first1 != last1; ++first1, ++first2)
    if (*first1 != *first2) return false;
    else if (first2 == last2) return true;
  return false;
}

/* checks whether a range ends with another range */
bool
ends_with (i32 *first1, i32 *last1, i32 *first2, i32 *last2)
{
  (void)first1;
  (void)last1;
  (void)first2;
  (void)last2;
  return false;
}


/* === modifying sequence algorithms === */
i32 *
copy(i32* first, i32* last, i32* d_first)
{
  (void)first;
  (void)last;
  (void)d_first;
  return first;
}


/* === partitioning operations === */


/* === sorting operations === */


/* === binary search operations (on sorted ranges) === */


/* === other operations on sorted ranges === */


/* === set operations (on sorted ranges === */


/* === heap operations === */


/* === minimum/maximum operations === */


/* === comparison operations === */


/* === permutation operations === */


/* === fold operations === */


// --- END _MYSTL_H_ DEFINITIONS ---
