#### Linux - 自动 UPX 脱壳

使用 upx.idc 进入原始 OEP .. 没做完，少 mprotect 环节

使用 dumpseg.idc 内存 dump

修复 PH 还是算了

#### 手动步骤

先找 popa 跳到 debug001

然后找 push 3 (sys_read)
