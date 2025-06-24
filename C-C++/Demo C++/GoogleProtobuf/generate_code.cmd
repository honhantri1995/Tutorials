echo off

:: Path to proto compiler
set PROTOC=protoc-25.1-win64\bin\protoc.exe

:: Path to your available code
set SRC_DIR=.

:: Path to the generated code (often same as SRC_DIR)
set DST_DIR=.

%PROTOC% -I=%SRC_DIR% --cpp_out=%DST_DIR% %SRC_DIR%/addressbook.proto
