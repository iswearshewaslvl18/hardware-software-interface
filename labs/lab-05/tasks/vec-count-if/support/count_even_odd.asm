; SPDX-License-Identifier: BSD-3-Clause

%include "printf32.asm"

%define ARRAY_SIZE    10

section .data
    dword_array dd 1392, 12544, 7991, 6992, 7202, 27187, 28789, 17897, 12988, 17992

section .text
extern printf
global main
main:
    mov ecx, ARRAY_SIZE     
    xor esi, esi      
    xor edi, edi

next_element:
    xor edx, edx
    mov eax, dword [dword_array + ecx*4 - 4]
    mov ebx, 2
    div ebx

    test edx, edx
    jne add_to_odd
    inc esi
    jmp test_end
add_to_odd:
    inc edi
test_end:
    loop next_element

    PRINTF32 `Num even is %u, num odd is %u\n\x0`, esi, edi

    ret