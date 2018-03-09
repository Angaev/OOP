rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � �� �������� ���������� ��������� �� ������� ��� ��������
%PROGRAM% hello >nul
if not ERRORLEVEL 1 goto err

rem ��� ������� � �������� ���������� ��������� �� ������� ��� �������� ���� ����� <0
%PROGRAM% -1 >nul
if not ERRORLEVEL 1 goto err

rem ��� ������� � �������� ���������� ��������� �� ������� ��� �������� ���� ����� >255
%PROGRAM% 256 >nul
if not ERRORLEVEL 1 goto err

rem ��� ������� ����������� ����������� ��������� ��������� ��������� �����
%PROGRAM% 6 >"%temp%\flipByte.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\flipByte.txt" test-data\flip6.txt >nul
if ERRORLEVEL 1 goto err

rem ���������, ��� ��������� �� ������ ������ ��� ���������� 1
%PROGRAM% 158 >"%temp%\158.txt" 
if ERRORLEVEL 1 goto err
fc.exe "%temp%\158.txt" test-data\flip6.txt >nul
if not ERRORLEVEL 1 goto err

rem ����� ��������� flip ������� �������� ������� ����

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