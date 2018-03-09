rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

rem ѕри запуске без параметров ожидаетс€ ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ѕри запуске с не числовым параметром ожидаетс€ не нулевой код возврата
%PROGRAM% hello >nul
if not ERRORLEVEL 1 goto err

rem ѕри запуске с числовым параметром ожидаетс€ не нулевой код возврата если число <0
%PROGRAM% -1 >nul
if not ERRORLEVEL 1 goto err

rem ѕри запуске с числовым параметром ожидаетс€ не нулевой код возврата если число >255
%PROGRAM% 256 >nul
if not ERRORLEVEL 1 goto err

rem ѕри запуске правильными параметрами ожидаетс€ переворот введеного байта
%PROGRAM% 6 >"%temp%\flipByte.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\flipByte.txt" test-data\flip6.txt >nul
if ERRORLEVEL 1 goto err

rem ѕровер€ем, что программа не всегда выдает код завершени€ 1
%PROGRAM% 158 >"%temp%\158.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\158.txt" test-data\flip6.txt >nul
if not ERRORLEVEL 1 goto err

rem ƒалее тестируем flip каждого отдельно вз€того бита

echo "128"
%PROGRAM% 128 >"%temp%\1.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\1.txt" test-data\1.txt >nul
if ERRORLEVEL 1 goto err

echo "64"
%PROGRAM% 64 >"%temp%\2.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\2.txt" test-data\2.txt >nul
if ERRORLEVEL 1 goto err

echo "32"
%PROGRAM% 32 >"%temp%\4.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\4.txt" test-data\4.txt >nul
if ERRORLEVEL 1 goto err

echo "16"
%PROGRAM% 16 >"%temp%\8.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\8.txt" test-data\8.txt >nul
if ERRORLEVEL 1 goto err

echo "1"
%PROGRAM% 1 >"%temp%\128.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\128.txt" test-data\128.txt >nul
if ERRORLEVEL 1 goto err

echo "2"
%PROGRAM% 2 >"%temp%\64.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\64.txt" test-data\64.txt >nul
if ERRORLEVEL 1 goto err

echo "4"
%PROGRAM% 4 >"%temp%\32.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\32.txt" test-data\32.txt >nul
if ERRORLEVEL 1 goto err

echo "8"
%PROGRAM% 8 >"%temp%\16.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\16.txt" test-data\16.txt >nul
if ERRORLEVEL 1 goto err

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1