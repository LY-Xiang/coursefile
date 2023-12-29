Invoke-WebRequest 'https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe' -OutFile './msys2.exe'
./msys2.exe in --confirm-command --accept-messages --root C:/msys64
Remove-Item msys2.exe
$env:CHERE_INVOKING = 'yes'
$env:MSYSTEM = 'UCRT64'
C:/msys64/usr/bin/bash.exe -lc 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu'
C:/msys64/usr/bin/bash.exe -lc 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu'
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Scc'
C:/msys64/usr/bin/bash.exe -lc 'pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain'
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Scc'
