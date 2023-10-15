#ifndef BITWISE_OPERATION_H_
#define BITWISE_OPERATION_H_

#define set_bit(reg,bit)     ( (reg)|= (1<<bit) )
#define clear_bit(reg,bit)   ( (reg) &= (~ (1<<bit)) )
#define get_bit(reg,bit)     ( ((reg)>>bit)&(0x01) )
#define toggle_bit(reg,bit)  ( (reg) ^= (1<<bit) )


#endif /* BITWISE_OPERATION_H_ */
