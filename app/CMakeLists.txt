add_executable(
	Game main.cpp
	## March files
	march/player.cpp march/player.h
	march/expedition/expedition.cpp march/expedition/expedition.h

	## March arts
	march/items/artefact.h

	## March UI
		march/tool_box.h
	march/expedition/map.cpp march/expedition/map.h
		march/tool_box.cpp
)
target_compile_features(Game PRIVATE cxx_std_17)

target_link_libraries(Game PRIVATE befry_engine conio.h)
