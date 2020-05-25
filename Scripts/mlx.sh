if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root"
   exit 1
fi

mkdir ~/temp
cd ~/temp || exit 1

git clone https://github.com/42Paris/minilibx-linux

echo "Installing MLX for Linux"
cd minilibx-linux/
make
[ -d "/usr/local/lib" ] && cp libmlx.a libmlx_Linux.a /usr/local/lib
[ -d "/usr/X11/lib" ] && cp libmlx.a libmlx_Linux.a /usr/X11/lib
[ -d "/usr/X11/include" ] && cp mlx.h /usr/X11/include
[ -d "/usr/local/include" ] && cp mlx.h /usr/local/include
[ -d "/usr/local/man/man3" ] && cp man/man3/mlx* /usr/local/man/man3
[ -d "/usr/X11/man/man3" ] && cp man/man3/mlx* /usr/X11/man/man3