rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с не числовым параметром ожидается не нулевой код возврата
%PROGRAM% hello >nul
if not ERRORLEVEL 1 goto err

rem При запуске с числовым параметром ожидается не нулевой код возврата если число <0
%PROGRAM% -1 >nul
if not ERRORLEVEL 1 goto err

rem При запуске с числовым параметром ожидается не нулевой код возврата если число >255
%PROGRAM% 256 >nul
if not ERRORLEVEL 1 goto err

rem При запуске правильными параметрами ожидается переворот введеного байта
%PROGRAM% 6 >"%temp%\flipByte.txt" 
fc.exe "%temp%\flipByte.txt" test-data\flip6.txt >nul
if ERRORLEVEL 1 goto err

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1