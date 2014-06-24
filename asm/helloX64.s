.section .data
    string:
        .ascii "hrllo, world !! X64\n"
    string_end:
        .equ lrn, string_end - string

.section .text
.global _start
    _start:
        movq $4, %rax
        movq $1, %rbx
        movq $string, %rcx
        movq $lrn, %rdx
        int $0x80

        movq $1, %rax
        movq $0, %rbx
        int $0x80
