void enable_8259A_irq(unsigned int irq)
{
        unsigned int mask = ~(1 << irq);
        unsigned long flags;

        spin_lock_irqsave(&i8259A_lock, flags);
        cached_irq_mask &= mask;
        if (irq & 8)
                outb(cached_slave_mask, PIC_SLAVE_IMR);
        else
                outb(cached_master_mask, PIC_MASTER_IMR);
        spin_unlock_irqrestore(&i8259A_lock, flags);
}

int i8259A_irq_pending(unsigned int irq)
{
        unsigned int mask = 1<<irq;
        unsigned long flags;
        int ret;

        spin_lock_irqsave(&i8259A_lock, flags);
        if (irq < 8)
                ret = inb(PIC_MASTER_CMD) & mask;
        else
                ret = inb(PIC_SLAVE_CMD) & (mask >> 8);
        spin_unlock_irqrestore(&i8259A_lock, flags);

        return ret;
}
