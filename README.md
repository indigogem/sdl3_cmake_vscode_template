#### SDL3+cmake+vscode template

install vscode

install exstansions for visual code: C/C++ Extension Pack (this includes also cmake tools)

get visual studio compiler (cl.exe) (for example install Visual Studio Community 2022) (why? its native to windows, feel free setup presets for other compilers and systems)(also you can just straight up use Visual Studio instead of vscode)

```shell
git clone https://github.com/indigogem/sdl3_cmake_vscode_template.git
```

```shell
cd thirdparty 
cmake --preset vs2022win64
cmake --build --preset debug-win-x64
cd ..
cmake --preset vs2022win64
cmake --build --preset debug-win-x64
```

Open VScode and setup you Cmake tools.

![image](https://github.com/user-attachments/assets/9db1fcd0-52aa-410c-b285-dfcea3808677)



This is slightly more modern template to start developing game with sdl3 on windows.

It has setup presets for Visual Studio compiler (note that presets also setuped in thirdparty)

All thirdparty builds separatly to not tight your project (sdl3 and glm build in this template), and you can freely add more libs that also could be not even have cmake poroject setuped.

Just add them as sdl and glm added in this project, if library dont setup to be find with find_package, you can add you custom find in cmake\ as it done for gml.

Also you can add more cmake functions here like build shaders etc. 

Some downside is you should be aware how you build your thirdparty, to not link you release build with debug version etc.

Executable will be put in build/bin

./data/ will be synced with ./build/bin/data (on windows using robocopy, check cmake file) (data/ ignored by git, check .gitignore)

