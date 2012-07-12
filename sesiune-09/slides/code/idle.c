void cpu_idle(void)
{
	int cpu = smp_processor_id();

	current_thread_info()->status |= TS_POLLING;

	/* endless idle loop with no priority at all */
	while (1) {
		tick_nohz_stop_sched_tick();
		while (!need_resched()) {
			void (*idle)(void);

			check_pgt_cache();
			rmb();
			idle = pm_idle;

			if (rcu_pending(cpu))
				rcu_check_callbacks(cpu, 0);

			if (!idle)
				idle = default_idle;

			if (cpu_is_offline(cpu))
				play_dead();

			__get_cpu_var(irq_stat).idle_timestamp = jiffies;
			idle();
		}
		tick_nohz_restart_sched_tick();
		preempt_enable_no_resched();
		schedule();
		preempt_disable();
	}
}
