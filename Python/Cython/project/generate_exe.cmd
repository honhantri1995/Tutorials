@echo off

set PROJ_PATH=%CD%
set APP_NAME=myapp

echo.
echo Clean up PyInstaller outputs
rmdir /s /q dist
rmdir /s /q build
rmdir /s /q %APP_NAME%.spec

echo.
echo Clean up Cython outputs
rmdir /s /q build_cythonize
del /S *.pyd

:: Create exe file
echo.
echo ------------------------------------
echo Running PyInstaller ...
cd %PROJ_PATH%

pyinstaller ^
	--onefile ^
	--name %APP_NAME% ^
	--add-data="README;README" ^
	--add-binary="app/some_package/some_classes.cp310-win_amd64.pyd;app/some_package/"  ^
	run.py

echo.
echo ---------------------------------------------------------------------
echo The EXE file is successfully generated. check it in folder "%PROJ_PATH%\dist"

pause