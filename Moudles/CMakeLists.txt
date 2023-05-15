file(GLOB_RECURSE   SRCS  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  LIST_DIRECTORIES false 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    )

add_library(Moudles SHARED
  ${SRCS}
)

target_link_libraries(Moudles Controls)

# 设置Qt的相关属性
set_target_properties(Moudles PROPERTIES
  AUTOMOC ON
  AUTORCC ON
  AUTOUIC ON
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  QT_AUTOMOC ON
  QT_AUTORCC ON
  QT_AUTOGEN ON
)

# 将Qt的模块链接到自定义控件的动态库
target_link_libraries(Moudles Qt6::Core Qt6::Gui Qt6::Widgets)