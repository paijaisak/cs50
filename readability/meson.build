project('readability', 'c')

src_files = ['src/main.c', 'src/cs50.c', 'src/test.c']

inc_dir = include_directories('include')

check_dep = dependency('check', required: true)

exe = executable(
  'readability',
  src_files,
  include_directories: inc_dir,
  dependencies: check_dep,
)

test('test', exe)
