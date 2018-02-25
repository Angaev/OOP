rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
rem %PROGRAM% test_data\input.txt Hello >nul
rem if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами, но без возможности прочитать файл (не сущ) ожидает ненулевой код возврата
rem %PROGRAM% notExistFile.txt Hello >nul
rem if NOT ERRORLEVEL 1 goto err

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1