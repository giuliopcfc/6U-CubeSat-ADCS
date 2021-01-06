@echo off
set MATLAB=C:\Program Files\MATLAB\R2020b
"%MATLAB%\bin\win64\gmake" -f detumbling.mk  OPTS="-DTID01EQ=0"
