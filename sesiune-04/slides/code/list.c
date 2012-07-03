struct pid_list {
    pid_t pid;
    struct list_head list;
};
LIST_HEAD(my_list);
 
static int add_pid(pid_t pid)
{
        struct pid_list *ple = kmalloc(sizeof *ple, GFP_KERNEL);
        if (!ple)
                return -ENOMEM;
 
        INIT_LIST_HEAD(&ple->list);
        ple->pid = pid;
        list_add(&ple->list, &my_list);
        return 0;
}
 
static int del_pid(pid_t pid)
{
        struct list_head *i, *tmp;
        struct pid_list *ple;
 
        list_for_each_safe(i, tmp, &my_list) {
                ple = list_entry(i, struct pid_list, list);
                if (ple->pid == pid) {
                        list_del(i);
                        kfree(ple);
                        return 0;
                }
        }
        return -EINVAL;
}
