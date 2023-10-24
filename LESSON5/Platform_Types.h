/*
 * Platform_Types.h
 *
 *
 *      Author: Hossam Diab
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE 			CPU_TYPE_32;
#define CPU_BIT_ORDER  	    MSB_FIRST;
#define CPU_BYTE_ORDER  	HIGH_BYTE_FIRST;

#ifndef FALSE
#define FALSE (boolean)false
#endif

#ifndef TRUE
#define TRUE (boolean)true
#endif

typedef _Bool 		boolean;
typedef char		char_t;
typedef int8_t 	    sint8;
typedef uint8_t 	uint8 ;
typedef int16_t 	sint16;
typedef uint16_t 	uint16;
typedef int32_t     sint32;
typedef uint32_t    uint32;
typedef	int64_t     sint64;
typedef uint64_t    uint64;

typedef volatile char_t 		vchar_t;
typedef volatile sint8 			vint8_t;
typedef volatile uint8 			vuint8_t ;
typedef volatile sint16		    vint16_t;
typedef volatile uint16         vuint16_t;
typedef volatile sint32			vint32_t;
typedef volatile uint32         vuint32_t;
typedef	volatile sint64         vint64_t;
typedef volatile uint64         vuint64_t;


#endif /* PLATFORM_TYPES_H_ */
