/* 
 * CS:APP Data Lab 
 * 
 * <hekai>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*exploit ~ and & to compute x^y*/
  
  return ~(~(x&~y) & ~(~x&y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 0x1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(~((x+1)+x) | !(x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA + (0xAA<<8);
  mask = mask + (mask<<16);
  return !((x & mask) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*-x = ~x+1*/
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*x-0x30>=0 && 0x39-x>=0*/
  int T = 0x1<<31;
  return !((x+~0x30+1) & T) & !((0x39+~x+1) & T);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = !!x;
  x = ~x+1;
  return (x&y) | (~x&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {

  int T = 0x1<<31;
  x = ~x+1;
  return !((x+y) & T);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*非0 的逻辑非是 0    0 的逻辑非是1, x | ~x+1 ,只有0，位或相反数时，符号位才为0，其他均为1*/

  return ~((x | (~x+1)))>>31&1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*正数时，最高位1的位置+1， 负数时，最高位0的位置+1，归一化为正数处理*/
  int b16,b8,b4,b2,b1,b0;
  int sign = x>>31;
  x = (sign&~x) | (~sign&x);
  
  b16 = !!(x>>16)<<4;
  x = x>>b16;

  b8 = !!(x>>8)<<3;
  x = x>>b8;

  b4 = !!(x>>4)<<2;
  x = x>>b4;

  b2 = !!(x>>2)<<1;
  x = x>>b2;

  b1 = !!(x>>1);
  x = x>>b1;

  b0 = x;

  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int s, exp;
  s = uf & 0x80000000;
  exp = (uf & 0x7F800000)>>23;
  // printf("uf:%d, s:%d, exp:%d", uf, s, exp);
  if (exp==255) {
    return uf;
  }
  if (exp==0) {
    return ((uf & 0x007fffff) << 1) | (uf & (1 << 31));
  }
  exp++;

  // if (exp==255) {
  //   return 0x7F800000 | s;
  // }

  return (exp<<23)|(uf & 0x807FFFFF);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /*
  (1) 取出符号位，指数位，尾数
  (2) 如果E<0,直接由于M是1.xxx或0.xxx，M表示的二进制小数 
  小数点左边只有一位，E小于0表示小数点至少往左边移动一位，所以移动完成后，
  小数点的右边一定是0，即整数部分是0，这种情况下，直接返回0就是要求的答案
  (3)E>= 32，表示M一定是1.xxx（因为E等于-126时M才是0.xxx），如果E >= 32，
  表示小数点要往右移动32bit，但是int类型最多32bit，所以会爆掉，按照题目要求返回 0x80000000u
  (4) 0<=E<32
  这里需要先把frac23bit前面的1补上，即$(1<<23) | frac$​​​，这个表达式代表M，如M = 1.11001，
  则这个表达式就是11100100......000（共24bit）
  当E>=23时，表示小数点右移可以把M小数点右边的23bit小数都吃掉，还能给后面继续补0，所以直接返回24bit+（补的几个0）即可。
  当E<23时，表示小数点右移不能把M小数点右边的23bit小数都吃掉，只能吃掉一部分，所以返回24bit右移“割舍的bit”
  */
  int s, exp,f,E;

  s = (uf & 0x80000000)>>31;
  exp = (uf & 0x7F800000)>>23;
  f = uf & 0x007fffff;
  E = exp -127;
  f = f | 1 <<23;

  if (E < 0) return 0;
  if (E>=31) {
    return 0x80000000u;
  }
  if (E<23) {
    f >>=(23-E);
  }else {
    f<<=(E-23);
  }
  if (s) {
    return ~f+1;
  }else{
    return f;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
/*
情况1：非规格化值能表示的最小2.0x是2-149，所以x<-149时，float无法表示，直接返回0

情况2：规格化值能表示的最小2.0x是2^-126，所以-149 <= x < -126时，是非规格化的值可以表示的，
非规格化的值特点是阶码exp为0，E = 1 - Bias = -126,，比如x是-130，$V = 2^{-126} * 2^{-4}$，
所以M = 2^-4，要返回2^-130的float表示就是0 ，0000 0000， 000 01000 00000 00000 00000，
可以看到是1左移了19bit，19=23-4

情况3：规格化值能表示的最大2.0x是2^127，所以 -126 <= x <= 127时，要使V是2.0x，
需要M是1.000......00，这个很简单，直接把exp的值<<23bit即可，exp = E +Bias(E就是x)

情况4：x > 127时，float无法表示了，返回+INF
*/
  if (x<-149) return 0;
  if (x < -126) {
    int shift = 23 + x + 126;
    return 1 << shift;
  }
  if (x<=127){
    int exp = x + 127;
    return exp<<23;
  }else {
    return 0xFF<<23;
  }
}
