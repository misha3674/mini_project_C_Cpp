TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    animationmanager.cpp \
    player.cpp

win32: LIBS += -L$$PWD/SFML/bin/ -lopenal32 -lsfml-audio-2
win32: LIBS += -L$$PWD/SFML/bin/ -lsfml-audio-d-2 -lsfml-graphics-2 -lsfml-graphics-d-2 -lsfml-network-2
win32: LIBS += -L$$PWD/SFML/bin/ -lsfml-network-d-2 -lsfml-system-2 -lsfml-system-d-2 -lsfml-window-2 -lsfml-window-d-2

HEADERS += \
    SFML/Graphics.hpp \
    SFML/Window.hpp \
    SFML/Graphics/BlendMode.hpp \
    SFML/Graphics/CircleShape.hpp \
    SFML/Graphics/Color.hpp \
    SFML/Graphics/ConvexShape.hpp \
    SFML/Graphics/Drawable.hpp \
    SFML/Graphics/Export.hpp \
    SFML/Graphics/Font.hpp \
    SFML/Graphics/Glsl.hpp \
    SFML/Graphics/Glyph.hpp \
    SFML/Graphics/Image.hpp \
    SFML/Graphics/PrimitiveType.hpp \
    SFML/Graphics/Rect.hpp \
    SFML/Graphics/RectangleShape.hpp \
    SFML/Graphics/RenderStates.hpp \
    SFML/Graphics/RenderTarget.hpp \
    SFML/Graphics/RenderTexture.hpp \
    SFML/Graphics/RenderWindow.hpp \
    SFML/Graphics/Shader.hpp \
    SFML/Graphics/Shape.hpp \
    SFML/Graphics/Sprite.hpp \
    SFML/Graphics/Text.hpp \
    SFML/Graphics/Texture.hpp \
    SFML/Graphics/Transform.hpp \
    SFML/Graphics/Transformable.hpp \
    SFML/Graphics/Vertex.hpp \
    SFML/Graphics/VertexArray.hpp \
    SFML/Graphics/View.hpp \
    SFML/System/Clock.hpp \
    SFML/System/Err.hpp \
    SFML/System/Export.hpp \
    SFML/System/FileInputStream.hpp \
    SFML/System/InputStream.hpp \
    SFML/System/Lock.hpp \
    SFML/System/MemoryInputStream.hpp \
    SFML/System/Mutex.hpp \
    SFML/System/NativeActivity.hpp \
    SFML/System/NonCopyable.hpp \
    SFML/System/Sleep.hpp \
    SFML/System/String.hpp \
    SFML/System/Thread.hpp \
    SFML/System/ThreadLocal.hpp \
    SFML/System/ThreadLocalPtr.hpp \
    SFML/System/Time.hpp \
    SFML/System/Utf.hpp \
    SFML/System/Vector2.hpp \
    SFML/System/Vector3.hpp \
    SFML/Window/Context.hpp \
    SFML/Window/ContextSettings.hpp \
    SFML/Window/Event.hpp \
    SFML/Window/Export.hpp \
    SFML/Window/GlResource.hpp \
    SFML/Window/Joystick.hpp \
    SFML/Window/Keyboard.hpp \
    SFML/Window/Mouse.hpp \
    SFML/Window/Sensor.hpp \
    SFML/Window/Touch.hpp \
    SFML/Window/VideoMode.hpp \
    SFML/Window/Window.hpp \
    SFML/Window/WindowHandle.hpp \
    SFML/Window/WindowStyle.hpp \
    SFML/Audio.hpp \
    SFML/Config.hpp \
    SFML/Main.hpp \
    SFML/Network.hpp \
    SFML/OpenGL.hpp \
    SFML/System.hpp \
    animationmanager.h \
    entity.h \
    player.h

DISTFILES += \
    a.txt
