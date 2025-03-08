#!/bin/zsh

meson compile -C builddir plurality

meson test -C builddir plurality-tests -v
