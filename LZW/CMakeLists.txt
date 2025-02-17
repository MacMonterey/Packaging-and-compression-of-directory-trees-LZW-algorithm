cmake_minimum_required(VERSION 3.30)
project(LZW)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 強制要求使用指定的 C++ 標準
set(CMAKE_CXX_EXTENSIONS OFF)       # 禁用編譯器特定的擴展

# 建立可執行檔
add_executable(LZW Source/cpp/main.cpp
        Source/cpp/TreeNode.cpp
        Source/cpp/TreeNode.h
        Source/cpp/unpackTree.cpp
        Source/cpp/unpackTree.h
        Source/cpp/createExampleTree.cpp
        Source/cpp/createExampleTree.h
        Source/cpp/deserializeTree.cpp
        Source/cpp/deserializeTree.h
        Source/cpp/lzwEncode.cpp
        Source/cpp/lzwEncode.h
        Source/cpp/lzwDecode.cpp
        Source/cpp/lzwDecode.h
        Source/cpp/serializeTree.cpp
        Source/cpp/serializeTree.h
        Source/cpp/saveAndLoadData.cpp
        Source/cpp/saveAndLoadData.h)

# 使用 target_sources 添加源碼檔案
#[[target_sources(LZW PRIVATE
        Source/cpp/main.cpp
        Source/cpp/TreeNode.cpp
        Source/cpp/unpackTree.cpp
        Source/cpp/createExampleTree.cpp
        Source/cpp/deserializeTree.cpp
        Source/cpp/lzwEncode.cpp
        Source/cpp/lzwDecode.cpp
        Source/cpp/serializeTree.cpp
)]]

# (可選) 如果您想把標頭檔也組織到 include 目錄中，可以這樣做：
#[[target_include_directories(LZW PRIVATE
        Source/cpp/TreeNode.h
         Source/cpp/unpackTree.h
         Source/cpp/createExampleTree.h
         Source/cpp/deserializeTree.h
         Source/cpp/lzwEncode.h
         Source/cpp/lzwDecode.h
         Source/cpp/serializeTree.h
)]]
