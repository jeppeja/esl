#include "ca_number_to_string.h"
#include <ca_debug/ca_debug.h>
#include <string.h>
#include <limits.h>

// ---------------------
// PUBLIC: functions ---
// ---------------------
size_t ca_int64_to_str(int64_t value, char* dst_str, uint8_t base)
{
    char buffer[sizeof(int64_t)*8+1];// be careful with the length of the buffer
    char* pos = buffer;

    // Only support negative numbers for radix 10
    int sign = (base == 10 && value < 0);
    if (sign) value = -value;

    while (value || pos == buffer) {
        int8_t index = (int8_t)(value % base);
        value /= base; // v/=radix uses less CPU clocks than v=v/radix does
        if (index < 10) {
            *pos = index+'0';
            ++pos;
        }
        else {
            *pos = index + 'a' - 10;
            ++pos;
        }
    }

    ptrdiff_t len = pos - buffer;
    ca_assert(len > 0, "ca_int64_to_str negative lenght");

    if (sign) {
        *dst_str = '-';
        ++dst_str;
        len++;
    }

    while (pos > buffer) {
        --pos;
        *dst_str = *pos;
        ++dst_str;
    }

    *dst_str = '\0';
    return (size_t)len;
}

size_t ca_int32_to_str(int32_t value, char* dst_str, uint8_t base)
{
    char buffer[sizeof(int32_t)*8+1];// be careful with the length of the buffer
    char* pos = buffer;

    // Only support negative numbers for radix 10
    int sign = (base == 10 && value < 0);
    if (sign) value = -value;

    while (value || pos == buffer) {
        int8_t index = (int8_t)(value % base);
        value /= base; // v/=radix uses less CPU clocks than v=v/radix does
        if (index < 10) {
            *pos = index+'0';
            ++pos;
        }
        else {
            *pos = index + 'a' - 10;
            ++pos;
        }
    }

    ptrdiff_t len = pos - buffer;
    ca_assert(len > 0, "ca_int32_to_str negative lenght");

    if (sign) {
        *dst_str = '-';
        ++dst_str;
        len++;
    }

    while (pos > buffer) {
        --pos;
        *dst_str = *pos;
        ++dst_str;
    }

    *dst_str = '\0';
    return (size_t)len;
}

size_t ca_int16_to_str(int16_t value, char* dst_str, uint8_t base)
{
    return ca_int32_to_str(value, dst_str, base);
}

size_t ca_int8_to_str(int8_t value, char* dst_str, uint8_t base)
{
    return ca_int32_to_str(value, dst_str, base);
}

size_t ca_long_to_str(long value, char* dst_str, uint8_t base)
{
#if (LONG_MAX == INT64_MAX)
    return ca_int64_to_str(value, dst_str, base);
#elif (LONG_MAX == INT32_MAX)
    return ca_int32_to_str(value, dst_str, base);
#else
#error ca_long_to_string__not_supported_on_this_platfform
#endif
}

size_t ca_int_to_str(int value, char* dst_str, uint8_t base)
{
#if (INT_MAX == INT64_MAX)
    return ca_int64_to_str(value, dst_str, base);
#elif (INT_MAX == INT32_MAX)
    return ca_int32_to_str(value, dst_str, base);
#else
#error ca_int_to_string__not_supported_on_this_platfform
#endif
}

// ------------------------------
// Unsigned integer functions ---
// ------------------------------
size_t ca_uint64_to_str(uint64_t value, char* dst_str, uint8_t base)
{
    char buffer[sizeof(uint64_t)*8+1];// be careful with the length of the buffer
    char* pos = buffer;

    while (value || pos == buffer) {
        int8_t index = (int8_t)(value % base);
        value /= base; // v/=radix uses less CPU clocks than v=v/radix does
        if (index < 10) {
            *pos = index+'0';
            ++pos;
        }
        else {
            *pos = index + 'a' - 10;
            ++pos;
        }
    }

    ptrdiff_t len = pos - buffer;
    ca_assert(len > 0, "ca_uint64_to_str negative lenght");

    while (pos > buffer) {
        --pos;
        *dst_str = *pos;
        ++dst_str;
    }

    *dst_str = '\0';
    return (size_t)len;
}

size_t ca_uint32_to_str(uint32_t value, char* dst_str, uint8_t base)
{
    char buffer[sizeof(uint32_t)*8+1];// be careful with the length of the buffer
    char* pos = buffer;

    while (value || pos == buffer) {
        int8_t index = (int8_t)(value % base);
        value /= base; // v/=radix uses less CPU clocks than v=v/radix does
        if (index < 10) {
            *pos = index+'0';
            ++pos;
        }
        else {
            *pos = index + 'a' - 10;
            ++pos;
        }
    }

    ptrdiff_t len = pos - buffer;
    ca_assert(len > 0, "ca_uint32_to_str negative lenght");

    while (pos > buffer) {
        --pos;
        *dst_str = *pos;
        ++dst_str;
    }

    *dst_str = '\0';
    return (size_t)len;
}


size_t ca_uint16_to_str(uint16_t value, char* dst_str, uint8_t base)
{
    return ca_uint32_to_str(value, dst_str, base);
}

size_t ca_uint8_to_str(uint8_t value, char* dst_str, uint8_t base)
{
    return ca_uint32_to_str(value, dst_str, base);
}

size_t ca_ulong_to_str(unsigned long value, char* dst_str, uint8_t base)
{
#if (ULONG_MAX == UINT64_MAX)
    return ca_uint64_to_str(value, dst_str, base);
#elif (ULONG_MAX == UINT32_MAX)
    return ca_uint32_to_str(value, dst_str, base);
#else
#error ca_uint_to_string__not_supported_on_this_platfform
#endif
}

size_t ca_uint_to_str(unsigned int value, char* dst_str, uint8_t base)
{
#if (UINT_MAX == UINT64_MAX)
    return ca_uint64_to_str(value, dst_str, base);
#elif (UINT_MAX == UINT32_MAX)
    return ca_uint32_to_str(value, dst_str, base);
#else
#error ca_uint_to_string__not_supported_on_this_platfform
#endif
}
