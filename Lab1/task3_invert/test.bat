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

rem В файле с матрицей должны быть числа, но не буквы или иные символы
echo "test4"
%PROGRAM% test-data\badMatrix.txt >nul
if NOT ERRORLEVEL 1 goto err

rem Программа может загрузить валидную матрицу из файла (ожидается нулевой код возврата)
echo "test5"
%PROGRAM% test-data\matrix.txt >nul
if ERRORLEVEL 1 goto err

rem Программа может загрузить валидную матрицу из файла и выводит определитель матрицы (ожидается нулевой код возврата)
echo "test6"
%PROGRAM% test-data\matrix.txt >"%TEMP%\output.txt"
if ERRORLEVEL 1 goto err
echo "test6_1"
fc.exe "%TEMP%\output.txt" test-data\determinant.txt 
if ERRORLEVEL 1 goto err



echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1