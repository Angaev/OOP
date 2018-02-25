rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% test_data\input.txt Hello >nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� �����������, �� ��� ����������� ��������� ���� (�� ���) ������� ��������� ��� ��������
%PROGRAM% notExistFile.txt Hello >nul
if NOT ERRORLEVEL 1 goto err

rem ����� ����� �������� ��������������� � ������� ��������� � ������

rem ��������� ��� ���������� ���������� � ������������ ����� ��������� ���� ���� � ������� ������ � ������������
%PROGRAM% test_data\input.txt line >"%temp%\output.txt"
fc.exe "%temp%\output.txt" "test_data\etalon-answer-for-input.txt" >nul
if ERRORLEVEL 1 echo "Error find string test 1"
if ERRORLEVEL 1 goto err

rem ��� ���������� ���������� � ��� ����� �� ������� ������ ���������� � ����� ������ 
%PROGRAM% test_data\input2.txt line >"%temp%\output2.txt"
fc.exe "%temp%\output2.txt" "test_data\etalon-answer-for-input2.txt" >nul
if ERRORLEVEL 1 goto err

rem ��� ���������� ���������� � ��� ����� �� ������� ������ ���������� � ����� ������ � ������� ����� �������� � ������ � ������� ������
%PROGRAM% test_data\input3.txt line >"%temp%\output3.txt"
fc.exe "%temp%\output3.txt" "test_data\etalon-answer-for-input3.txt" >nul
if ERRORLEVEL 1 goto err

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1