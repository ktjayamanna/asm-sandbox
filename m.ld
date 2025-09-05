MEMORY 
{
    ram : ORIGIN = 0x80000000, LENGTH = 0x00001000
}

SECTIONS
{
    .text : { *(.text*) } > ram
}