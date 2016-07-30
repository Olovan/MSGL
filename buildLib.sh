OUTPUT="libmsgl.so"
OUTPUTDIR="bin/"
SOURCES=(
	" src/Window.cpp"
	" src/Sprite.cpp"
	" src/Texture.cpp"
	" src/Vec2.cpp"
	" src/Vec2i.cpp"
	" src/SpriteAnimation.cpp"
	" src/SpriteSheetImporter.cpp"
	" src/StringUtils.cpp"
	" src/Input.cpp"
	" src/KeyListener.cpp"
	" src/ButtonListener.cpp"
	)
INCLUDES=(
	" -Iinclude"
	)
LIBS=(
	" -lglfw" 
	" -lGL"
	" -lm"
	" -lgcc_s"
	" -lgcc"
	)
FLAGS=(
	" -std=c++11"
	" -shared"
	" -Wl,-soname,libmsgl.so"
	" -fPIC"
	)
echo g++ ${FLAGS[*]} ${INCLUDES[*]} ${SOURCES[*]} ${LIBS[*]} -o $OUTPUT
g++ ${FLAGS[*]} ${INCLUDES[*]} ${SOURCES[*]} ${LIBS[*]} -o $OUTPUT
mv $OUTPUT $OUTPUTDIR
