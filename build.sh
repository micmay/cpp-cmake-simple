#!/bin/bash

cmake -G"Eclipse CDT4 - Ninja"
ninja
ninja clangformat