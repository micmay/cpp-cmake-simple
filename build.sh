#!/bin/bash

cmake -G"Eclipse CDT4 - Ninja"
ninja
ninja cppcheck
ninja clangformat