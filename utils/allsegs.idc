#include <idc.idc>

static main(void)
{
    auto ea = FirstSeg(), addr;
    auto i  = 1;

    while (ea != BADADDR)
    {
        Message ("%d. %08x name %s\n", i ++, ea, SegName(ea));
        ea = NextSeg(ea);
    }
}
