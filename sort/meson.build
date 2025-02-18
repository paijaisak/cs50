project('sort', 'c')

src_files = ['src/main.c', 'src/cs50.c']

inc_dir = include_directories('include')

check_dep = dependency('check', required: true)

executable(
  'sort',
  src_files,
  include_directories: inc_dir,
  dependencies: check_dep,
)

test_exe = executable(
  'test-sort',
  'test/test.c',
  src_files,
  include_directories: inc_dir,
  dependencies: check_dep,
)

test('test-sort', test_exe)
