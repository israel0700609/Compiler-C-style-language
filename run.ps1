$ErrorActionPreference = 'Stop'

$repoRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $repoRoot

$pkgRoot = Join-Path $env:LOCALAPPDATA "Microsoft\WinGet\Packages"
$wfb = Join-Path $pkgRoot "WinFlexBison.win_flex_bison_Microsoft.Winget.Source_8wekyb3d8bbwe"
$wlBin = Join-Path $pkgRoot "BrechtSanders.WinLibs.MCF.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin"

# Make sure commands resolve in this session even before shell restart.
$env:PATH = "$wfb;$wlBin;$env:PATH"

Write-Host "Cleaning generated files..."
Remove-Item -Force -ErrorAction SilentlyContinue lex.yy.c, y.tab.c, y.tab.h, compiler.exe

Write-Host "Generating lexer and parser..."
win_bison -d -y ./syntax_analyzer/Parser.y
win_flex ./syntax_analyzer/Scanner.l

Write-Host "Compiling..."
gcc lex.yy.c y.tab.c ast/ast.c semantic_analyzer/BluePrintFiles/scope.c ir_generator/three_ac.c -g -o compiler.exe

Write-Host "Running compiler on inputs..."
Get-Content input1.txt | .\compiler.exe output1.txt
Get-Content input2.txt | .\compiler.exe output2.txt
Get-Content input3.txt | .\compiler.exe output3.txt
Get-Content input4.txt | .\compiler.exe output4.txt
Get-Content input5_part3_demo.txt | .\compiler.exe output5_part3_demo.txt

Write-Host "Done. Generated: output1.txt, output2.txt, output3.txt, output4.txt, output5_part3_demo.txt"
