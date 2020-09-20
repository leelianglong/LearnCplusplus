## 参考博客
1. https://blog.csdn.net/MakerCloud/article/details/93545513?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase

2. https://www.jb51.net/article/186781.htm


3、 cmakelist的书写：
```
cmake_minimum_required(VERSION 3.18)
project(vscode_cmake_Test)
aux_source_directory(. DIR_TOOT_SRCS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
add_executable(${PROJECT_NAME} ${DIR_TOOT_SRCS})
```

4、在工程根目录下，wecode选择terminal 下，选择powershell 任务，创建文件夹 mkdir build

进入build：  cd build

自动生产Makefile,执行后面的命令：  CMake -G "Unix Makefile" ../

5、编译，执行后面的命令： mingw32-make.exe ， 这样就生成了可执行命令

6、执行可执行命令： ./xxxx


