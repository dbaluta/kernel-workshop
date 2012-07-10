struct sk_buff {
struct sk_buff *next;
struct sk_buff *prev;

struct sock *sk;
ktime_t tstamp;
struct net_device *dev;
char cb[48];

unsigned int len,
data_len;
__u16 mac_len,
hdr_len;

void (*destructor)(struct sk_buff *skb);

sk_buff_data_t transport_header;
sk_buff_data_t network_header;
sk_buff_data_t mac_header;
sk_buff_data_t tail;
sk_buff_data_t end;

unsigned char *head,
*data;
unsigned int truesize;
atomic_t users;
