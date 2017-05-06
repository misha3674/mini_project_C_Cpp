TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../external_libs/


SOURCES += main.cpp \
    animationmanager.cpp \
    player.cpp \
    ../external_libs/TinyXML/tinystr.cpp \
    ../external_libs/TinyXML/tinyxml.cpp \
    ../external_libs/TinyXML/tinyxmlerror.cpp \
    ../external_libs/TinyXML/tinyxmlparser.cpp

win32: LIBS += -L$$PWD/../external_libs/SFML/bin/ -lopenal32 -lsfml-audio-2
win32: LIBS += -L$$PWD/../external_libs/SFML/bin/ -lsfml-audio-2
win32: LIBS += -L$$PWD/../external_libs/SFML/bin/ -lsfml-audio-d-2 -lsfml-graphics-2 -lsfml-graphics-d-2 -lsfml-network-2
win32: LIBS += -L$$PWD/../external_libs/SFML/bin/ -lsfml-network-d-2 -lsfml-system-2 -lsfml-system-d-2 -lsfml-window-2 -lsfml-window-d-2

HEADERS += \
    animationmanager.h \
    entity.h \
    player.h \
    level.h \
    ../external_libs/SFML/Audio.hpp \
    ../external_libs/SFML/Config.hpp \
    ../external_libs/SFML/Graphics.hpp \
    ../external_libs/SFML/Main.hpp \
    ../external_libs/SFML/Network.hpp \
    ../external_libs/SFML/OpenGL.hpp \
    ../external_libs/SFML/System.hpp \
    ../external_libs/SFML/Window.hpp \
    ../external_libs/SFML/Audio/AlResource.hpp \
    ../external_libs/SFML/Audio/Export.hpp \
    ../external_libs/SFML/Audio/InputSoundFile.hpp \
    ../external_libs/SFML/Audio/Listener.hpp \
    ../external_libs/SFML/Audio/Music.hpp \
    ../external_libs/SFML/Audio/OutputSoundFile.hpp \
    ../external_libs/SFML/Audio/Sound.hpp \
    ../external_libs/SFML/Audio/SoundBuffer.hpp \
    ../external_libs/SFML/Audio/SoundBufferRecorder.hpp \
    ../external_libs/SFML/Audio/SoundFileFactory.hpp \
    ../external_libs/SFML/Audio/SoundFileReader.hpp \
    ../external_libs/SFML/Audio/SoundFileWriter.hpp \
    ../external_libs/SFML/Audio/SoundRecorder.hpp \
    ../external_libs/SFML/Audio/SoundSource.hpp \
    ../external_libs/SFML/Audio/SoundStream.hpp \
    ../external_libs/SFML/Graphics/BlendMode.hpp \
    ../external_libs/SFML/Graphics/CircleShape.hpp \
    ../external_libs/SFML/Graphics/Color.hpp \
    ../external_libs/SFML/Graphics/ConvexShape.hpp \
    ../external_libs/SFML/Graphics/Drawable.hpp \
    ../external_libs/SFML/Graphics/Export.hpp \
    ../external_libs/SFML/Graphics/Font.hpp \
    ../external_libs/SFML/Graphics/Glsl.hpp \
    ../external_libs/SFML/Graphics/Glyph.hpp \
    ../external_libs/SFML/Graphics/Image.hpp \
    ../external_libs/SFML/Graphics/PrimitiveType.hpp \
    ../external_libs/SFML/Graphics/Rect.hpp \
    ../external_libs/SFML/Graphics/RectangleShape.hpp \
    ../external_libs/SFML/Graphics/RenderStates.hpp \
    ../external_libs/SFML/Graphics/RenderTarget.hpp \
    ../external_libs/SFML/Graphics/RenderTexture.hpp \
    ../external_libs/SFML/Graphics/RenderWindow.hpp \
    ../external_libs/SFML/Graphics/Shader.hpp \
    ../external_libs/SFML/Graphics/Shape.hpp \
    ../external_libs/SFML/Graphics/Sprite.hpp \
    ../external_libs/SFML/Graphics/Text.hpp \
    ../external_libs/SFML/Graphics/Texture.hpp \
    ../external_libs/SFML/Graphics/Transform.hpp \
    ../external_libs/SFML/Graphics/Transformable.hpp \
    ../external_libs/SFML/Graphics/Vertex.hpp \
    ../external_libs/SFML/Graphics/VertexArray.hpp \
    ../external_libs/SFML/Graphics/View.hpp \
    ../external_libs/SFML/Network/Export.hpp \
    ../external_libs/SFML/Network/Ftp.hpp \
    ../external_libs/SFML/Network/Http.hpp \
    ../external_libs/SFML/Network/IpAddress.hpp \
    ../external_libs/SFML/Network/Packet.hpp \
    ../external_libs/SFML/Network/Socket.hpp \
    ../external_libs/SFML/Network/SocketHandle.hpp \
    ../external_libs/SFML/Network/SocketSelector.hpp \
    ../external_libs/SFML/Network/TcpListener.hpp \
    ../external_libs/SFML/Network/TcpSocket.hpp \
    ../external_libs/SFML/Network/UdpSocket.hpp \
    ../external_libs/SFML/System/Clock.hpp \
    ../external_libs/SFML/System/Err.hpp \
    ../external_libs/SFML/System/Export.hpp \
    ../external_libs/SFML/System/FileInputStream.hpp \
    ../external_libs/SFML/System/InputStream.hpp \
    ../external_libs/SFML/System/Lock.hpp \
    ../external_libs/SFML/System/MemoryInputStream.hpp \
    ../external_libs/SFML/System/Mutex.hpp \
    ../external_libs/SFML/System/NativeActivity.hpp \
    ../external_libs/SFML/System/NonCopyable.hpp \
    ../external_libs/SFML/System/Sleep.hpp \
    ../external_libs/SFML/System/String.hpp \
    ../external_libs/SFML/System/Thread.hpp \
    ../external_libs/SFML/System/ThreadLocal.hpp \
    ../external_libs/SFML/System/ThreadLocalPtr.hpp \
    ../external_libs/SFML/System/Time.hpp \
    ../external_libs/SFML/System/Utf.hpp \
    ../external_libs/SFML/System/Vector2.hpp \
    ../external_libs/SFML/System/Vector3.hpp \
    ../external_libs/SFML/Window/Context.hpp \
    ../external_libs/SFML/Window/ContextSettings.hpp \
    ../external_libs/SFML/Window/Event.hpp \
    ../external_libs/SFML/Window/Export.hpp \
    ../external_libs/SFML/Window/GlResource.hpp \
    ../external_libs/SFML/Window/Joystick.hpp \
    ../external_libs/SFML/Window/Keyboard.hpp \
    ../external_libs/SFML/Window/Mouse.hpp \
    ../external_libs/SFML/Window/Sensor.hpp \
    ../external_libs/SFML/Window/Touch.hpp \
    ../external_libs/SFML/Window/VideoMode.hpp \
    ../external_libs/SFML/Window/Window.hpp \
    ../external_libs/SFML/Window/WindowHandle.hpp \
    ../external_libs/SFML/Window/WindowStyle.hpp \
    ../external_libs/SFML/Graphics/Graphics.hpp \
    ../external_libs/TinyXML/tinystr.h \
    ../external_libs/TinyXML/tinyxml.h


DISTFILES += \
    a.txt
