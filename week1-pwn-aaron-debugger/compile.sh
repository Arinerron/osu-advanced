#!/bin/sh

gcc src/main.c -o bin/aaron-debugger -fpie -Wl,-z,relro,-z,now -O0

