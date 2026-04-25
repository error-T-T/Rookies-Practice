/*
Author: RookieT
Date: 2026/04/25
Repository: https://github.com/error-T-T/Rookies-Practice
Email: RookieT@e.gzhu.edu.cn
Type: Practice
Knowledge: ComputerTheory
Skill: Recursion
Abstract: Two recursion demos:
    (1) toBinary() prints binary digits via right-shift recursion;
    (2) unsigned_multiply() implements recursive multiplication using shift and add. 
    (Russian peasant method)
*/
#include <stdio.h>

void toBinary(unsigned int n) {
    if (n >> 1)             // 如果还有更高位（n >> 1 != 0）
        toBinary(n >> 1);   // 先递归输出高位
    putchar('0' + (n & 1)); // 输出当前最低位
}

unsigned int unsigned_multiply(unsigned int x, unsigned int y){
    if(y==0) 
        return 0;
    
    return (y&1) ? 
        x + unsigned_multiply(x<<1, y>>1) : 
        unsigned_multiply(x<<1, y>>1);
}
// 'y & 1' 检查 y 的二进制最低位是否为 1。
// 以下运算符都是按位运算符，基于二进制位操作：
//   &  按位与
//   |  按位或
//   ^  按位异或
//   ~  按位取反
//   << 左移（二进制）
//   >> 右移（二进制）
// 它们不能直接用于其他进制（如三进制）的位操作。


int main(){
    unsigned int x = 5;
    unsigned int y = 3;
    toBinary(x);
    printf(" * ");
    toBinary(y);
    printf(" = ");
    unsigned int result = unsigned_multiply(x, y);
    toBinary(result);
    printf("\n%d * %d = %d\n", x, y, result);

    return 0;
}