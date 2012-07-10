/* reserve head room */
void skb_reserve(struct sk_buff *skb, int len);
/* add data to the end */
unsigned char *skb_put(struct sk_buff *skb, unsigned int len);
/* add data to the top */
unsigned char *skb_push(struct sk_buff *skb, unsigned int len);
/* discard data at the top */
unsigned char *skb_pull(struct sk_buff *skb, unsigned int len);
/* discard data at the end */
unsigned char *skb_trim(struct sk_buff *skb, unsigned int len);
