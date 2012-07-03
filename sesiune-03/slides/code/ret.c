ENTRY(ret_from_sys_call)
        # need_resched and signals atomic test
        cli                            
        cmpl $0,need_resched(%ebx)
        jne reschedule
        cmpl $0,sigpending(%ebx)
        jne signal_return
        RESTORE_ALL
