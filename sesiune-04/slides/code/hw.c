attr.bp_addr = kallsyms_lookup_name(ksym_name);
attr.bp_len = HW_BREAKPOINT_LEN_4;
attr.bp_type = HW_BREAKPOINT_W | HW_BREAKPOINT_R;

register_wide_hw_breakpoint(&attr, sample_hbp_handler);
