ENTRY=_start
SCRIPT_NAME=elf
ELFSIZE=64
TEMPLATE_NAME=elf32
OUTPUT_FORMAT="elf64-alpha"
TEXT_START_ADDR="0x120000000"
MAXPAGESIZE=0x10000
NONPAGED_TEXT_START_ADDR="0x120000000"
ARCH=alpha
MACHINE=
GENERATE_SHLIB_SCRIPT=yes
DATA_PLT=
NOP=0x47ff041f

OTHER_READONLY_SECTIONS='.reginfo : { *(.reginfo) }'
