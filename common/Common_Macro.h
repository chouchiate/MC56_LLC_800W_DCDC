#define SHIFT(n) (1 << (n))
#define BIT(b) (((uint16_t)1) << (b))
#define STATEMENT(x)      do { x } while (__LINE__ == -1)

#define ELEMEMT_NUMBER(x)	(sizeof(x)/sizeof(x[0]))
//#define ARRAY_SIZE(x)	(sizeof(x)/sizeof(x[0]))

#define ABS(x,y)	(((x)>(y))?((x)-(y)):((y)-(x)))

#define LBYTE(x)		((x)&0xFF)
#define HBYTE(x)		((x)>>8)

#define BYTE_TO_WORD(l, h) (((unsigned short)h<<8) | l)
#define BYTE_TO_DWORD(l0, l1,h0, h1) (((unsigned long)h1<<24) | ((unsigned long)h0<<16) | ((unsigned long)l1<<8) |(l0))
#define WORD_TO_DWORD(l, h) (((unsigned int)h<<16) | l)

#define IS_POWER_OF_2(x)	(((x)&(x-1))==0)

