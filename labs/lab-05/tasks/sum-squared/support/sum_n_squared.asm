; SPDX-License-Identifier: BSD-3-Clause

%include "printf32.asm"

section .data
    num dd 100

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, [num]     
    xor ebx, ebx       

add_to_sum:
    mov eax, ecx
    mul eax
    add ebx, eax
    loop add_to_sum   

    PRINTF32 `Sum(%u): %u\n\x0`, ecx, ebx

    leave
    ret