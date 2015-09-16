#include <idc.idc>

static main(void)
{
    auto popa = FindText(ScreenEA(), SEARCH_DOWN|SEARCH_REGEX, 0, 0, "popa");
    if (popa == BADADDR)
    {
        Message ("Couldn't find popa\n");
        return;
    }

    Message("Found popa at %x\n", popa);
    RunTo(popa);
    GetDebuggerEvent(WFNE_SUSP, -1);

    auto code, i = 0;
    // 当前 18 debug002
    while (++ i)
    {
        if (GetProcessState() == DSTATE_NOTASK)
        {
            Message ("Process detached, crap");
            break;
        }

        StepUntilRet();
        GetDebuggerEvent(WFNE_SUSP, -1);

        Message ("== BEGIN DUMP #%d ==\n", i);
        auto ea = FirstSeg(), addr;
        while (ea != BADADDR)
        {
            Message ("%08x name %s\n", ea, SegName(ea));
            ea = NextSeg(ea);
        }

        if (AskYN (0, "Continue ?") != 1)
        {
            break;
        }
    }
}
