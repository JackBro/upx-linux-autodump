#include <idc.idc>

static main(void)
{
    auto ea = FirstSeg(), addr;
    auto i  = 1;
    auto fp = fopen ("c:\\dump\\upx.dump", "wb");

    while (ea != BADADDR)
    {
        Message ("%d. %08x name %s\n", i ++, ea, SegName(ea));

        for (addr = ea; addr < SegEnd(ea); ++ addr)
        {
            fputc (Byte(addr), fp);
        }

        ea = NextSeg(ea);
    }
}
