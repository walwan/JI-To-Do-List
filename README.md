# JI-To-Do-List

## Introduction

This program helps make a list of tasks and involves the regular functions of a to-do-list, including adding tasks, deleting tasks and editing tasks. When the user has new tasks, he can add them to existing list. When the user finishes a certain task, he can remove it from the list. When the task meets changes, the user can also edit the task contents, like task description. Besides, the program is designed to arrange all the tasks in a recommended order based on the due time, priority and time cost set by users.

## Build

### Dependency

This project is written in C++ with Qt as the only external library.

- To build the project, you need to have C++ and qt opensource development environment.

- This project is development in Qt 5.x. Theoretically, this project can be built with Qt 4.x or order, though we DO NOT recommend to do so.

### Get Source Code

- You can download the release version of source code in the release.
- Or clone the repository:
    ```shell=
    git clone https://github.com/walwan/JI-To-Do-List.git
    ```
    - For VG101 Teaching Group, you may need to checkout to the final branch to get the version submitted on canvas:
    ```shell=
    cd JI-To-Do-List
    git checkout final
    ```

### Configure

This project can only be configured by qmake, which is bundled in qt development environment.

If you have Qt Creator installed, we recommend you to configure and build in Qt Creator.

#### Configure in Qt Creator

- Open the project file (JIToDoList.pro) in Qt Creator
- In the "Projects" tab, select target platform configuration
- Select the target (Debug / Release)
- Wait for the configuration to complete

#### Configure in Command Line

To configure the project in command line, you need to whether add the path to the qmake and make executable to the environment variable PATH or use full path to execute qmake and make.

- In the parent directory of the project folder, create  and change to a new folder named "JI-To-Do-List-build":
    ```shell=
    mkdir JI-To-Do-List-build
    cd JI-To-Do-List-build
    ```
- Run qmake:
    ```shell=
    mingw32-make.exe clean
    qmake ../JI-To-Do-List/ -config release
    ```

### Compile

#### Compile in Qt Creator

- Just build the project in the Qt Creator

#### Compile in Command Line

- In the JI-To-Do-List-build folder, make the target:
    ```shell=
    mingw32-make.exe -j4
    ```

### Package and Deploy

#### Windows

Here we just use the "windeployqt" tool.

- In the release subfolder of the build folder of the project, find the JIToDoList.exe executable.
- Move it to a suitable clean folder.
- Run windeployqt:
    ```shell=
    windeployqt.exe .\JIToDoList.exe
    ```

#### X11

Please refer to the Qt documentation ([link](https://doc.qt.io/qt-5/linux-deployment.html)).

## Usage

### Add, Modify, Delete(Done) Tasks

- Use the "New Task" button to add a new task.
- Use the "Edit" button in the each task item lift side to edit that task.
- Use the "Done" button in the each task item lift side to delete(done) that task.

### Generate Suggest List

- Use the "Suggested List" button, the tasks in the left area will be rearranged in the suggested order.
- Note: The name or the descrption of a task will not affect its order in the rearrangement. So if you have two or more tasks with the same due date, priority, and time cost, their order will change in a cycle if you click the button several times.

## Troubleshooting

### General for Build related

If you meet any problem when building the project in command line, please try to build it in Qt Creator.

## Credits
- VG101 Group 10
- VG101 Teaching Group
