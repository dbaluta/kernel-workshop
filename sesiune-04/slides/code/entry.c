ENTRY(system_call)
        # save orig_eax
        pushl %eax                      
        SAVE_ALL
        GET_CURRENT(%ebx)
        ...
        cmpl $(NR_syscalls),%eax
        jae badsys
        call *SYMBOL_NAME(sys_call_table)(,%eax,4) 
        # save the return value
        movl %eax,EAX(%esp)            
