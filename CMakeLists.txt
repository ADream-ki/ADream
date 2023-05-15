#cmake最低版本
cmake_minimum_required(VERSION 3.21.1)
# 这里指定当前模块名以及开发版本，这里推荐用文件名作为模块名
project(ADream VERSION 0.1.0)

set(CMAKE_PREFIX_PATH "D:/Qt/6.5.0/mingw_64/" "D:/VulkanSDK/1.3.243.0")
# 添加Qt的模块
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)


#指定输出路径
SET(OUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
if (NOT EXISTS ${OUT_PATH})
    file(MAKE_DIRECTORY ${OUT_PATH})
endif ()
SET(EXECUTABLE_OUTPUT_PATH ${OUT_PATH})
SET(LIBRARY_OUTPUT_PATH ${OUT_PATH})
# 指定 自定模块目录
set(QML_IMPORT_PATH ${OUT_PATH})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 添加子目录
add_subdirectory(Controls)
add_subdirectory(Moudles)

qt_add_resources(RESOURCES resources.qrc)


set(SOURCES
    main.cpp
    resources.qrc
)

# 添加当前项目
add_executable(ADream ${SOURCES} ${RESOURCES})

# 将自定义控件的动态库链接到当前项目
target_link_libraries(ADream Controls)
target_link_libraries(ADream Moudles)

# 设置Qt的相关属性
set_target_properties(ADream PROPERTIES
  AUTOMOC ON
  AUTORCC ON
  AUTOUIC ON
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  QT_AUTOMOC ON
  QT_AUTORCC ON
  QT_AUTOGEN ON
)

# 将Qt的模块链接到当前项目
target_link_libraries(ADream Qt6::Core Qt6::Gui Qt6::Widgets)