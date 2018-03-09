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
echo "test1"
%PROGRAM% test_data\input.txt line >"%temp%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output.txt" "test_data\etalon-answer-for-input.txt" >nul
if ERRORLEVEL 1 goto err

rem при правильных параметрах и сущ файле не находит второе совпадение в одной строке (правильное поведение)
echo "test2"
%PROGRAM% test_data\input2.txt line >"%temp%\output2.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output2.txt" "test_data\etalon-answer-for-input2.txt" >nul
if not ERRORLEVEL 1 goto err

rem тест на правильную обработку пустых строк в указаном файле
echo "test3"
%PROGRAM% test_data\input4.txt line >"%temp%\output4.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output4.txt" "test_data\etalon-answer-for-input4.txt" >nul
if ERRORLEVEL 1 goto err

rem если в тексте не удалось найти подстроку, то выведет `Text not found`
echo "test4"
%PROGRAM% test_data\input5.txt line >"%temp%\output5.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output5.txt" "test_data\etalon-answer-for-input5.txt" >nul
if ERRORLEVEL 1 goto err


echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1