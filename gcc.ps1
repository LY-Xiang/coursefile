(New-Object System.Net.WebClient).DownloadFile('https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe', './msys2.exe')
./msys2.exe in --confirm-command --accept-messages --root C:/msys64
Remove-Item msys2.exe
$env:CHERE_INVOKING = 'yes'
$env:MSYSTEM = 'UCRT64'
Function msys2
{
	C:/msys64/usr/bin/bash.exe @('-lc') + @Args
}
msys2 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'
msys2 'pacman --noconfirm -Syuu'
msys2 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'
msys2 'pacman --noconfirm -Syuu'
msys2 'pacman --noconfirm -Scc'
msys2 'pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain'

