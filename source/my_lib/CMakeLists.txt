cmake_minimum_required(VERSION 3.10)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SOURCES
    factorial.c # liczy silnie liczby n
	power.c	# oblicza potęgę (potęgowanie binarne)
	#cos.c		# funkcje liczące cosinusa
)

add_library(my_library STATIC ${SOURCES})
