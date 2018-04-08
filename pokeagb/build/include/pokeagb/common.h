#ifndef POKEAGB_MACROS_H_
#define POKEAGB_MACROS_H_

#include <stddef.h>

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "=" VALUE(var)

#define POKEAGB_EXTERN extern __attribute__((long_call))
#define DEPRECATED __attribute__((deprecated))

#ifdef __cplusplus
#define STATIC_ASSERT(expr, message) static_assert(expr, message);
#elif defined(__STDC_VERSION__)
#if __STDC_VERSION__ == 201112L
#define STATIC_ASSERT(expr, message) _Static_assert(expr, message);
#else
#endif
#endif

#ifndef STATIC_ASSERT
#error "No static assert available for this platform"
#endif

/* TODO: Add more asserts to the code. */

/**
 * Assert (at compile time) that a type is of a given size.
 */
#define ASSERT_SIZEOF(type, size)                                     \
    STATIC_ASSERT(sizeof(type) == size,                               \
                   "Expected size of `"                               \
                   #type "` to be " #size ".")

/**
 * Assert (at compile time) that a member occurs at a given offset.
 */
#define ASSERT_OFFSETOF(type, member, offset)                           \
    STATIC_ASSERT(offsetof(type, member) == offset,                     \
                  "Expected `" #member "` in `"                         \
                  #type "` to be at offset " #offset ".")

#ifdef __cplusplus
#define POKEAGB_BEGIN_DECL extern "C" {
#define POKEAGB_END_DECL }
#else
#define POKEAGB_BEGIN_DECL
#define POKEAGB_END_DECL
#endif

#endif /* POKEAGB_MACROS_H_ */
