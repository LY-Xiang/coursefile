#安装VSCode
Invoke-WebRequest 'https://code.visualstudio.com/sha/download?build=stable&os=win32-x64' -OutFile './vsc.exe'#下载vsc
if ([System.IO.File]::Exists('./vsc.exe')){
    ./vsc.exe#安装vsc
}
Remove-Item ./vsc.exe#删除安装包

#配置VSCode

#安装msys2
Invoke-WebRequest 'https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe' -OutFile './msys2.exe'#下载msys2
if([System.IO.File]::Exists('./msys2.exe')){
    ./msys2.exe in --confirm-command --accept-messages --root C:/msys64#安装msys2
}
Remove-Item ./msys2.exe#删除msys2安装包

#设置msys2环境变量
$env:CHERE_INVOKING = 'yes'
$env:MSYSTEM = 'UCRT64'

#安装gcc&clang
C:/msys64/usr/bin/bash.exe -lc 'printf "\nexport LANG=zh_CN.UTF-8" >> .bashrc'#设置中文
C:/msys64/usr/bin/bash.exe -lc 'sed -i "s#https\?://mirror.msys2.org/#https://mirrors.tuna.tsinghua.edu.cn/msys2/#g" /etc/pacman.d/mirrorlist*'#设置清华镜像源
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu'#全面更新
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Syuu --needed base-devel mingw-w64-ucrt-x86_64-toolchain'#更新并安装gcc
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -S clang'#安装clang
C:/msys64/usr/bin/bash.exe -lc 'pacman --noconfirm -Scc'#清理安装缓存

#安装python
Invoke-WebRequest 'https://mirror.bjtu.edu.cn/python/3.13.0/python-3.13.0a2-amd64.exe' -OutFile './py.exe'#下载python
if([System.IO.File]::Exists('./py.exe')){
    ./py.exe#安装py
}
Remove-Item ./py.exe#删除安装包

#pip
python3 -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade pip#临时利用清华源升级pip
python3 -m pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple#设置pip清华源
python3 -m pip config set global.extra-index-url "https://pypi.org/simple/"#原生备用
