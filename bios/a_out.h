#define SEGMENT_SIZE 0x10000UL

struct exec {
    unsigned long a_info;
    unsigned long a_text;
    unsigned long a_data;
    unsigned long a_bss;
    unsigned long a_syms;
    unsigned long a_entry;
    unsigned long a_trsize;
    unsigned long a_drsize;
};

#define OMAGIC 0407
#define NMAGIC 0410
#define ZMAGIC 0413
#define QMAGIC 0314

#define N_TXTOFF(e) (0x400) 
#define N_TXTADDR(e) (SEGMENT_SIZE)

/* now works */
#define N_DATADDR(e) \
    (N_TXTADDR(e) + (((e).a_text + SEGMENT_SIZE - 1) & ~(SEGMENT_SIZE - 1)))
    
#define N_BSSADDR(e) (N_DATADDR(e) + (e).a_data)