# Command Line Flags

You can launch `pcsx-redux` with the following command line parameters:

**The parsing code doesn't care about the number of dashes in the parameter's flag, so '-' can be used as well as '--', or any number of dashes.**

| Flag | Meaning |
| :- | :- |
| `-dumpproto` | Dump the protobuf schemas for PCSX-Redux on stdout and exit immediately. |
| `-run` | Begin execution immediately on startup. |
| `-stdout` | Redirect log output to stdout. |
| `-lua_stdout` | Redirect Lua's console output to stdout. |
| `-logfile` | Specify a file to log output to. |
| `-bios` | Specify a BIOS file. |
| `-testmode` | Interpret [internal API](mips_api.md)'s `pcsx_exit()` command and close the emulator. |
| `-exe` | Load a PSX exe. |
| `-loadexe` | Load a PSX exe. |
| `-iso` | Load a PSX disk image (iso, bin/cue). |
| `-loadiso` | Load a PSX disk image (iso, bin/cue). |
| `-memcard1` | Specify a memory card file to use as memory card slot 1. |
| `-memcard2` | Specify a memory card file to use as memory card slot 2. |
| `-pcdrv` | Enable the pcdrv device interface. (Access PC filesystem through SIO). |
| `-pcdrvbase` | Specify base directory for pcdrv. |
| `-safe` | Resets configuration to defaults. |
| `-interpreter` | Use the interpreter CPU core. |
| `-dynarec` | Use the dynamic recompiler CPU core. |