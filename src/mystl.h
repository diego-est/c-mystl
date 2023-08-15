#pragma once
#define _MYSTL_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#define let auto
typedef uint8_t u8;
typedef int8_t  i8;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint32_t u32;
typedef int32_t  i32;
typedef uint64_t u64;
typedef int64_t  i64;

typedef struct ptr_pair {
  i32* first;
  i32* second;
} ptr_pair;

typedef struct pair {
  i32 first;
  i32 second;
} pair;

#define check1(func, range, size, expected) do { \
  assert(func(range, range + size) == expected) \
} while (0);


/* === non-modifying sequence algorithms === */
bool
all_even(i32* first, i32* last);

bool
any_even(i32* first, i32* last);

bool
all_odd(i32* first, i32* last);

u64
count(i32* first, i32* last, i32 value);


ptr_pair
mismatch(i32* first1, i32* last1, i32* first2);

i32*
find(i32* first, i32* last, i32 value);

i32*
find_even(i32* first, i32* last);

i32*
find_odd(i32* first, i32* last);

i32*
find_end(i32* first, i32* last, i32* s_first, i32* s_last);

i32*
find_first_of(i32* first, i32* last, i32* s_first, i32* s_last);

i32*
adjacent_find(i32* first, i32* last);

i32*
search(i32* first, i32* last, i32* s_first, i32* s_last);

i32*
search_n(i32* first, i32* last, u64 count, i32 value);

bool
starts_with(i32* first1, i32* last1, i32* first2, i32* last2);

bool
ends_with(i32* first1, i32* last1, i32* first2, i32* last2);


/* === modifying sequence algorithms === */
i32 *
copy(i32 *first, i32 *last, i32 *d_first);

i32 *
copy_if_even(i32 *first, i32 *last, i32 *d_first);

i32 *
copy_n(i32 *first, u64 count, i32 *d_first);

i32 *
copy_backward(i32 *first, i32 *last, i32 *d_last);

i32 *
move(i32 *first, i32 *last, i32 *d_first);

i32 *
move_backward(i32 *first, i32 *last, i32 *d_last);


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


// --- END _MYSTL_H_ DECLARATIONS ---
