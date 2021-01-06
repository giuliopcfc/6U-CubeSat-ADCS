@echo off
set MATLAB=C:\Program Files\MATLAB\R2020b
"%MATLAB%\bin\win64\gmake" -f Copy_of_detumbling.mk  OPTS="-DTID01EQ=0"
