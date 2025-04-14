project('cs50_projects', 'c',
  version: '1.0.0',
  default_options: [
    'c_std=c17',
    'warning_level=3',
  ]
)

# Common compiler flags
compiler = meson.get_compiler('c')
add_project_arguments(
  compiler.get_supported_arguments([
    '-Wall',
    '-Wextra',
    '-Wpedantic',
    '-Werror=implicit-function-declaration',
    '-Werror=incompatible-pointer-types',
    '-Wno-unused-parameter',
    '-Wno-unused-includes',
  ]),
  language: 'c'
)

# Get cs50 dependency from libs directory
cs50_dep = dependency('cs50', fallback: ['cs50', 'cs50_dep'], required: true,
                     default_options: ['default_library=static'])

# Define each subproject
subdir('projects/credit')
subdir('projects/plurality')
subdir('projects/readability')
subdir('projects/scrabble')
subdir('projects/substitution')
