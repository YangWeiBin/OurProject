set THISDATETIME=%DATE:~0,4%%DATE:~5,2%%DATE:~8,2%%TIME:~0,2%%TIME:~3,2%%TIME:~6,2%
git add .
git commit -m %THISDATETIME%
git push
pause