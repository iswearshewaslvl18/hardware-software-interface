; SPDX-License-Identifier: BSD-3-Clause

%include "printf32.asm"

%define ARRAY_SIZE    10

section .data
    dword_array dd 1392, -12544, -7992, -6992, 7202, 27187, 28789, -17897, 12988, 17992

section .text
extern printf
global main
main:
	; TODO: Implement the code to count negative and positive numbers in the array
    mov ecx, ARRAY_SIZE
    xor ebx, ebx
    xor edx, edx
next_element:
    mov eax, dword [dword_array + ecx * 4 - 4]
    cmp eax, 0
    jl negative_nr
    inc ebx
    jmp next
negative_nr:
    inc edx
next:
    loop next_element

    PRINTF32 `Num pos is %u, num neg is %u\n\x0`, ebx, edx
    ret
