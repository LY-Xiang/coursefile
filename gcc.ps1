#??VSCode
Invoke-WebRequest 'https://code.visualstudio.com/sha/download?build=stable&os=win32-x64' -OutFile './vsc.exe'#??vsc
./vsc.exe#??vsc
#??VSCode

#??msys2
Invoke-WebRequest 'https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe' -OutFile './msys2.exe'#??msys2
./msys2.exe in --confirm-command --accept-messages --root C:/msys64#??msys2
Remove-Item ./msys2.exe#??msys2???

# ??msys2????
$env:CHERE_INVOKING = 'yes'
$env:MSYSTEM = 'UCRT64'

#??gcc
C:/msys64/usr/bin/bash.exe -lc 'printf "\nexport LANG=zh_CN.UTF-8" >> .bashrc'#????
C:/msys64/usr/bin/bash.exe -lc 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'#???????
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu'#????
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu mingw-w64-ucrt-x86_64-toolchain'#?????gcc
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Scc'#??????
