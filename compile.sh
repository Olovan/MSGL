OUTPUT="MSGL"
OUTPUTDIR="bin/"
SOURCES=(
	" Main.cpp"
	" src/Window.cpp"
	" src/Sprite.cpp"
	" src/Texture.cpp"
	" src/Vec2.cpp"
	" src/Vec2i.cpp"
	" src/SpriteAnimation.cpp"
	" src/SpriteSheetImporter.cpp"
	" src/StringUtils.cpp"
	" src/Input.cpp"
	" src/ButtonListener.cpp"
	" src/KeyListener.cpp"
	)
#SOURCES=()
#for SOURCE in $(ls src/)
#do
	#SOURCE="src/$SOURCE"
	#SOURCES="$SOURCES $SOURCE"
#done
INCLUDES=(
	" -Iinclude"
	)
LIBS=(
	" -lglfw" 
	" -lGL"
	" -lm"
	)
FLAGS=(
	" -std=c++11"
	)
echo g++ ${FLAGS[*]} ${INCLUDES[*]} ${SOURCES[*]} ${LIBS[*]} -o $OUTPUT
g++ ${FLAGS[*]} ${INCLUDES[*]} ${SOURCES[*]} ${LIBS[*]} -o $OUTPUT
mv $OUTPUT $OUTPUTDIR
