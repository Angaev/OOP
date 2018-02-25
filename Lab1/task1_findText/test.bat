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

rem программа при правильных параметрах и существующем файле прочитает весь файл и выведет строки с совпадениями
%PROGRAM% test_data\input.txt line >"%temp%\output.txt"
fc.exe "%temp%\output.txt" "test_data\etalon-answer-for-input.txt" >nul
if ERRORLEVEL 1 echo "Error find string test 1"
if ERRORLEVEL 1 goto err

rem при правильных параметрах и сущ файле не находит второе совпадение в одной строке 
%PROGRAM% test_data\input2.txt line >"%temp%\output2.txt"
fc.exe "%temp%\output2.txt" "test_data\etalon-answer-for-input2.txt" >nul
if ERRORLEVEL 1 goto err

rem при правильных параметрах и сущ файле не находит второе совпадение в одной строке и искомое слово написано в притык с искомым словом
%PROGRAM% test_data\input3.txt line >"%temp%\output3.txt"
fc.exe "%temp%\output3.txt" "test_data\etalon-answer-for-input3.txt" >nul
if ERRORLEVEL 1 goto err

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1