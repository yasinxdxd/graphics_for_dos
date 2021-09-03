echo off
gcc -s -Wall ..\src\*.c -o renderer.exe -I"..\include" -lm -masm=intel
echo off

