#if !defined (SELECT_VECS) || defined (HAVE_arm_elf32_le_vec)

{ "arm-*-elf", NULL },
{ "arm*-*-freebsd*", NULL },
{ "arm*-*-linux-*", NULL },
{ "arm*-*-conix*", NULL },
{ "arm*-*-uclinux*", NULL },
{ "arm-*-kfreebsd*-gnu", NULL },
{ "arm*-*-eabi*", NULL },
{ "arm-*-rtems*", NULL },
{ "arm*-*-uclinuxfdpiceabi", &arm_elf32_le_vec },
#endif


    
