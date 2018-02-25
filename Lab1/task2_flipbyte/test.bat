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
fc.exe "%temp%\flipByte.txt" test-data\flip6.txt >nul
if ERRORLEVEL 1 goto err

echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1