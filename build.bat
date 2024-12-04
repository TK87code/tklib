@echo off

set files=..\code\main.c

set libs=

cl /Zi %files% /link %libs% /OUT: "main.exe"