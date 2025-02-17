cmake_minimum_required(VERSION 3.30)
project(LZW)

set(CMAKE_CXX_STANDARD 26)

add_executable(LZW)

# 使用 target_sources 添加源碼檔案
target_sources(LZW PRIVATE
        Source/cpp/main.cpp
        Source/cpp/TreeNode.cpp
        Source/cpp/unpackTree.cpp
        Source/cpp/createExampleTree.cpp
        Source/cpp/deserializeTree.cpp
        Source/cpp/lzwEncode.cpp
        Source/cpp/lzwDecode.cpp
        Source/cpp/serializeTree.cpp
)

# (可選) 如果您想把標頭檔也組織到 include 目錄中，可以這樣做：
 target_include_directories(LZW PRIVATE
        Source/cpp/TreeNode.h
         Source/cpp/unpackTree.h
         Source/cpp/createExampleTree.h
         Source/cpp/deserializeTree.h
         Source/cpp/lzwEncode.h
         Source/cpp/lzwDecode.h
         Source/cpp/serializeTree.h
)
