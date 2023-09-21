#!/bin/bash

# Install X11 XShm extension
sudo apt-get install --assume-yes gcc make xorg libxext-dev libbsd-dev

# Setup your OS
sudo git clone https://github.com/42Paris/minilibx-linux.git libmlx
sudo mkdir /usr/X11 2>/dev/null
sudo mkdir /usr/X11/include 2>/dev/null
sudo mkdir /usr/X11/lib 2>/dev/null
sudo mkdir /usr/local/lib 2>/dev/null
cd libmlx 2>/dev/null
sudo ./configure 2>/dev/null
sudo cp mlx.h /usr/X11/include 2>/dev/null
sudo cp mlx.h /usr/local/include 2>/dev/null
sudo cp libmlx.a /usr/X11/lib 2>/dev/null
sudo cp libmlx_Linux.a /usr/X11/lib 2>/dev/null
sudo cp libmlx.a /usr/local/lib 2>/dev/null
sudo cp libmlx_Linux.a /usr/local/lib 2>/dev/null
echo "\n# Finished -- Give to your compilator these instructions :"
echo "## -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11"
