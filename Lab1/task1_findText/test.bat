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

rem ��������� ��� ���������� ���������� � ������������ ����� ��������� ���� ���� � ������� ��� � output
rem %PROGRAM% test_data\input.txt Hello >"%temp%/\output.txt"
rem fc.exe "%temp%\output.txt" test_data\input.txt >nul
rem if ERRORLEVEL 1 goto err


echo testing pass!
exit 0

:err
echo Program testing failed
exit 1