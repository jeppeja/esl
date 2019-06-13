/**@file
 * ca_align_macros Atomic functions for pre C11/C++11 code.
 * Modelled after the C11/C++11 atomic.h functions.
 */
#ifndef CA_COMPILER_CA_ATOMIC_H
#define CA_COMPILER_CA_ATOMIC_H

#define ca_atomic_store(object, desired) __sync_lock_test_and_set(object, desired)
#define ca_atomic_load(object) __sync_fetch_and_add(object, 0 )

#endif // CA_COMPILER_CA_ATOMIC_H
