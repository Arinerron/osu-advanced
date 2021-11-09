#!/usr/bin/env python3

from subprocess import *
import os
import sys
import re
import mmap
import ctypes


MAX_LENGTH = 200


def check_shellcode(shellcode):
    if not shellcode:
        print('[-] Hey buddy, looks like you forgot to enter your shellcode...')
        return False

    retval = True

    if any([x in shellcode for x in b'\x00\n']):
        print('[-] Your shellcode contains an illegal byte (one of ["\\x00", "\\n"]).')
        retval = False

    if len(shellcode) > MAX_LENGTH:
        print('[-] Your shellcode is %d bytes long, but the maximum length is %d!' % (len(shellcode), MAX_LENGTH))
        retval = False

    with open('/tmp/shellcode.txt', 'wb') as f:
        f.write(shellcode)

    p = Popen("objdump -b binary -m i386:x86-64 -D /tmp/shellcode.txt -M intel | grep -i '\(push\|mov\|pop\|lea\)'", shell=True, stdin=PIPE, stdout=PIPE, stderr=PIPE)
    output = b''.join(p.communicate())
    
    if output:
        print('[-] The following instructions found in your shellcode are not allowed:')
        for line in output.strip().split(b'\n'):
            l = line.split(b'\t')
            if not l:
                continue
            print('    * %s  ->  %s' % (l[1].decode(), re.sub(r'[ \t\n]+', ' ', l[2].decode())))
            retval = False

    return retval


def run_shellcode(shellcode):
    mm = mmap.mmap(-1, len(shellcode) + 0x50, flags=mmap.MAP_SHARED | mmap.MAP_ANONYMOUS, prot=mmap.PROT_WRITE | mmap.PROT_READ | mmap.PROT_EXEC)
    mm.write(shellcode)
    ctypes_buffer = ctypes.c_int.from_buffer(mm)
    function = ctypes.CFUNCTYPE(ctypes.c_int64)(ctypes.addressof(ctypes_buffer))
    function()
    return True


if __name__ == '__main__':
    try:
        print("Hello, and welcome to your first shellcoding challenge. This program takes in Intel x86-64 shellcode, checks to make sure it satisfies certain conditions, then executes it if so. The conditions are:\n1. Does not contain any NULL bytes (\\x00) or newlines (\\n).\n2. Does not contain any variants of the instructions push, pop, mov, lea, and leave.\n3. Is %d bytes or shorter.\n" % MAX_LENGTH);
        print('Flag will be at /flag.txt\n')

        print('... your shellcode: ', end='')
        sys.stdout.flush()
        shellcode = sys.stdin.buffer.readline()[:-1]
        print()
        if check_shellcode(shellcode):
            print('[+] Your shellcode looks good! Running it... good luck!')
            run_shellcode(shellcode)
            print('[-] Looks like your shellcode didn\'t work :(')
    except Exception as e:
        print('[-] Error :(')
