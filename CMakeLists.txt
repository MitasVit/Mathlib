﻿# CMakeList.txt: Projekt CMake pro VM math, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#
cmake_minimum_required (VERSION 3.8)

project ("Math")

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (CMakeTarget "Math.cpp" "Math.h")

# TODO: V případě potřeby přidejte testy a cíle instalace.
