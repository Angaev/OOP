rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% test_data\input.txt Hello >nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами, но без возможности прочитать файл (не сущ) ожидает ненулевой код возврата
%PROGRAM% notExistFile.txt Hello >nul
if NOT ERRORLEVEL 1 goto err

rem далее тесты связаные непосредственно с поиском подстроки в строке

rem программа при правильных параметрах и существующем файле прочитает весь файл и выведет его в output
rem %PROGRAM% test_data\input.txt Hello >"%temp%/\output.txt"
rem fc.exe "%temp%\output.txt" test_data\input.txt >nul
rem if ERRORLEVEL 1 goto err


echo testing pass!
exit 0

:err
echo Program testing failed
exit 1