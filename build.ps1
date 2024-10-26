$ModName = "keepitdead"
$Prefix = "ProjetosBR_HumanZombie"

$ErrorActionPreference = "Stop"

if (Test-Path "P:\@${ModName}") { Remove-Item -Recurse "P:\@${ModName}" }

New-Item -Type Directory "P:\@${ModName}" | Out-Null
New-Item -Type Directory "P:\@${ModName}\addons" | Out-Null
New-Item -Type Directory "P:\@${ModName}\keys" | Out-Null

& "$((Get-ItemProperty -Path "HKCU:\Software\bohemia interactive\Dayz Tools").path)\Bin\AddonBuilder\AddonBuilder.exe" "P:\keepitdead\${Prefix}" "P:\@${ModName}\addons" "-clear" "-project=P:\keepitdead\${Prefix}" "-sign=$env:BIPRIVATEKEY_PATH" "-packonly"
$buildcode = $lastexitcode
$builderror = $errorMessage

if ($buildcode -ne 0) { throw ("Exec: " + $builderror) }

Move-Item "P:\@${ModName}\addons\${Prefix}.pbo" "P:\@${ModName}\addons\${ModName}.pbo"
Move-Item "P:\@${ModName}\addons\${Prefix}.pbo.crimsonzamboni.bisign" "P:\@${ModName}\addons\${ModName}.pbo.crimsonzamboni.bisign"

Copy-Item $env:BIKEY_PATH -Destination "P:\@${ModName}\keys"
