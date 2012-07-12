/*
* Enable paging
*/

movl $pa(swapper_pg_dir),%eax
/* set the page table pointer.. */
movl %eax,%cr3          
movl %cr0,%eax
orl  $X86_CR0_PG,%eax
/* ..and set paging (PG) bit */
movl %eax,%cr0         
