rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% test-data\matrix.txt >nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� �����������, �� �� ������������ ������ ��������� �� ������� ��� ��������
%PROGRAM% test-data\NoExistFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem � ����� � �������� ������ ���� �����, �� �� ����� ��� ���� �������
%PROGRAM% test-data\badMatrix.txt >nul
if NOT ERRORLEVEL 1 goto err


echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1