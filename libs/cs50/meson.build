project('cs50', 'c', version: '9.2.2',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ]
)

inc = include_directories('src')

cs50_lib = library('cs50',
    'src/cs50.c',
    include_directories: inc,
    install: true,
)

cs50_dep = declare_dependency(
    include_directories: inc,
    link_with: cs50_lib,
)

install_headers('src/cs50.h')