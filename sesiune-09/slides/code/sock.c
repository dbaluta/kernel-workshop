static struct proto my_proto = {
    .name     = MY_PROTO_NAME,
    .owner    = THIS_MODULE,
    .obj_size = sizeof(struct my_sock),
};

