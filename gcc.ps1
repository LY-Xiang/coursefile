#安装VSCode
Invoke-WebRequest 'https://code.visualstudio.com/sha/download?build=stable&os=win32-x64' -OutFile './vsc.exe'#下载vsc
./vsc.exe#安装vsc
#配置VSCode

#安装msys2
Invoke-WebRequest 'https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe' -OutFile './msys2.exe'#下载msys2
./msys2.exe in --confirm-command --accept-messages --root C:/msys64#安装msys2
Remove-Item ./msys2.exe#删除msys2安装包

#设置msys2环境变量
$env:CHERE_INVOKING = 'yes'
$env:MSYSTEM = 'UCRT64'

#安装gcc
C:/msys64/usr/bin/bash.exe -lc 'printf "\nexport LANG=zh_CN.UTF-8" >> .bashrc'#设置中文
C:/msys64/usr/bin/bash.exe -lc 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'#设置清华镜像源
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu'#全面更新
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu mingw-w64-ucrt-x86_64-toolchain'#更新并安装gcc
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Scc'#清理安装缓存
