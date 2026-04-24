param(
    [switch]$DryRun
)

$ErrorActionPreference = 'Stop'

$repoRoot = Split-Path -Parent $PSScriptRoot
$repoRoot = Split-Path -Parent $repoRoot
Set-Location $repoRoot

function Move-Folder {
    param(
        [Parameter(Mandatory=$true)][string]$Source,
        [Parameter(Mandatory=$true)][string]$Destination
    )

    if (-not (Test-Path $Source)) {
        Write-Host "SKIP  | $Source (source not found)"
        return
    }

    if (Test-Path $Destination) {
        throw "Destination already exists: $Destination"
    }

    $destParent = Split-Path -Parent $Destination
    if (-not (Test-Path $destParent)) {
        if ($DryRun) {
            Write-Host "DRY   | New-Item -ItemType Directory -Force -Path $destParent"
        } else {
            New-Item -ItemType Directory -Force -Path $destParent | Out-Null
        }
    }

    if ($DryRun) {
        Write-Host "DRY   | Move-Item '$Source' '$Destination'"
    } else {
        Move-Item -Path $Source -Destination $Destination
        Write-Host "MOVED | $Source -> $Destination"
    }
}

$mapping = @(
    @{ Source = 'fundamentals';        Destination = 'theory/01-fondements-cpp/fundamentals' },
    @{ Source = 'macros';              Destination = 'theory/01-fondements-cpp/macros' },
    @{ Source = 'modular-programming'; Destination = 'theory/03-fonctions-modularite/modular-programming' },
    @{ Source = 'oop';                 Destination = 'theory/05-programmation-objet/oop' },
    @{ Source = 'file-handling';       Destination = 'theory/08-fichiers-build-debug/file-handling' },
    @{ Source = 'build-notes';         Destination = 'resources/build-notes' },
    @{ Source = 'course-work';         Destination = 'exercises/course-work' },
    @{ Source = 'clean-examples';      Destination = 'tools/templates/clean-examples' },
    @{ Source = 'experiments';         Destination = 'examples/modern-cpp/experiments' },
    @{ Source = 'refactored';          Destination = 'examples/modern-cpp/refactored' }
)

Write-Host "Repository root: $repoRoot"
if ($DryRun) {
    Write-Host 'Running in DRY-RUN mode (no filesystem changes)'
}

foreach ($m in $mapping) {
    Move-Folder -Source $m.Source -Destination $m.Destination
}

Write-Host ''
Write-Host 'Top-level folders after migration:'
Get-ChildItem -Directory | Select-Object -ExpandProperty Name
