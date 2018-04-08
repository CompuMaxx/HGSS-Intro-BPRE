#ifndef POKEAGB_MATH_H_
#define POKEAGB_MATH_H_

#include <stddef.h>

#define ABS(x) (x) < 0 ? -(x) : (x)

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/* x subtract y, with a floor value of 1. TODO: Adjustable floor value */

#define NON_ZERO_SUB(x, y) (x - y) ? (x - y) : 1

/* given address to start of array (x), address to an index of array(y) and size of array(z),
   get the position of the array member y is in. */
#define GET_SLOT_FROM_PTR(x, y, z) ((y - x) / z)

#endif /* POKEAGB_MATH_H_ */

