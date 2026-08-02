# build.ps1  —  compile a competitive-programming file with the right flags
#
#   .\build.ps1 sol.cpp          NORMAL build  (fast; use this before you submit)
#   .\build.ps1 sol.cpp -debug   DEBUG build   (slower, but names your bugs:
#                                               out-of-bounds, bad comparators, overflow)
param(
    [Parameter(Mandatory = $true)][string]$file,
    [switch]$debug
)

$out = [System.IO.Path]::ChangeExtension($file, "exe")

if ($debug) {
    Write-Host "DEBUG build -> $out" -ForegroundColor Yellow
    g++ -std=c++20 -O0 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -ftrapv $file -o $out
} else {
    Write-Host "NORMAL build -> $out" -ForegroundColor Green
    g++ -std=c++20 -O2 -Wall -Wextra -Wshadow -Wconversion $file -o $out
}

if ($LASTEXITCODE -eq 0) { Write-Host "OK -> run it with  .\$out" -ForegroundColor Green }
else { Write-Host "compile FAILED" -ForegroundColor Red }
