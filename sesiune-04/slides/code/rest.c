#define RESTORE_ALL     \
        popl %ebx;      \
        popl %ecx;      \
        popl %edx;      \
        popl %esi;      \
        popl %edi;      \
        popl %ebp;      \
        popl %eax;      \
1:      popl %ds;       \
2:      popl %es;       \
        addl $4,%esp;   \
3:      iret;
