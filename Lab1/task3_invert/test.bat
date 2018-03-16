rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
echo "test0"
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
echo "test1"
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
echo "test2"
%PROGRAM% test-data\matrix.txt >nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами, но не существующим файлом ожидается не нулевой код возврата
echo "test3"
%PROGRAM% test-data\NoExistFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem В файле с матрицей должны быть числа, но не буквы или иные символы ожидается не нулевой код возврата
echo "test4"
%PROGRAM% test-data\badMatrix.txt >nul
if NOT ERRORLEVEL 1 goto err

rem при запуске с пустым файлом ожидается не нулевой код возврата
echo "test4_1"
%PROGRAM% test-data\emptyFile.txt >nul
if NOT ERRORLEVEL 1 goto err


rem Программа может загрузить валидную матрицу из файла (ожидается нулевой код возврата)
echo "test5"
%PROGRAM% test-data\matrix.txt >nul
if ERRORLEVEL 1 goto err

rem Программа правильно инвертирует матрицу
echo "test6"
%PROGRAM% test-data\matrix.txt >"%TEMP%\result.txt"
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\result.txt" test-data\invertMatrix.txt

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1