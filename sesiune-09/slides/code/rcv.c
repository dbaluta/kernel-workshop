static struct packet_type my_packet_type __read_mostly = {
    .type    = __constant_htons(MY_ETH),
    .func    = my_rcv,
};

