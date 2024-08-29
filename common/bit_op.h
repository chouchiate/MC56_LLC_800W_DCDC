#ifndef __BIT_OP_H__
#define __BIT_OP_H__

#define SET_BIT0(x) ((x) |= 0x01)
#define SET_BIT1(x) ((x) |= 0x02)
#define SET_BIT2(x) ((x) |= 0x04)
#define SET_BIT3(x) ((x) |= 0x08)
#define SET_BIT4(x) ((x) |= 0x10)
#define SET_BIT5(x) ((x) |= 0x20)
#define SET_BIT6(x) ((x) |= 0x40)
#define SET_BIT7(x) ((x) |= 0x80)

#define CLR_BIT0(x) ((x) &= ~0x01)
#define CLR_BIT1(x) ((x) &= ~0x02)
#define CLR_BIT2(x) ((x) &= ~0x04)
#define CLR_BIT3(x) ((x) &= ~0x08)
#define CLR_BIT4(x) ((x) &= ~0x10)
#define CLR_BIT5(x) ((x) &= ~0x20)
#define CLR_BIT6(x) ((x) &= ~0x40)
#define CLR_BIT7(x) ((x) &= ~0x80)

#define TOGGLE_BIT0(x) ((x) ~= 0x01)
#define TOGGLE_BIT1(x) ((x) ~= 0x02)
#define TOGGLE_BIT2(x) ((x) ~= 0x04)
#define TOGGLE_BIT3(x) ((x) ~= 0x08)
#define TOGGLE_BIT4(x) ((x) ~= 0x10)
#define TOGGLE_BIT5(x) ((x) ~= 0x20)
#define TOGGLE_BIT6(x) ((x) ~= 0x40)
#define TOGGLE_BIT7(x) ((x) ~= 0x80)

#define IS_BIT0_SET(x) ((x) &= 0x01)
#define IS_BIT1_SET(x) ((x) &= 0x02)
#define IS_BIT2_SET(x) ((x) &= 0x04)
#define IS_BIT3_SET(x) ((x) &= 0x08)
#define IS_BIT4_SET(x) ((x) &= 0x10)
#define IS_BIT5_SET(x) ((x) &= 0x20)
#define IS_BIT6_SET(x) ((x) &= 0x40)
#define IS_BIT7_SET(x) ((x) &= 0x80)
#endif /* !__BIT_OP_H__ */