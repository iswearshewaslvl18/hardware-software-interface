%include "printf32.asm"

%define ARRAY_LEN 7

section .data
input dd 122, 184, 199, 242, 263, 845, 911
output times ARRAY_LEN dd 0

section .text
extern printf
global main
main:
    xor ecx, ecx
push_array:
    push dword [input + 4 * ecx]
    inc ecx
    cmp ecx, ARRAY_LEN
    jl push_array

    xor ecx, ecx
pop_array:
    pop dword [output + 4 * ecx]
    inc ecx
    cmp ecx, ARRAY_LEN
    jl pop_array

    PRINTF32 `Reversed array: \n\x0`
    xor ecx, ecx
print_array:
    mov edx, [output + 4 * ecx]
    PRINTF32 `%d\n\x0`, edx
    inc ecx
    cmp ecx, ARRAY_LEN
    jl print_array

    xor eax, eax
    ret
