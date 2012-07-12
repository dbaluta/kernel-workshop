static const struct net_proto_family my_family_ops = {
    .family   = PF_MY,
    .create   = my_create,
    .owner    = THIS_MODULE,
};

