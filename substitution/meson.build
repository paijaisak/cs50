project('substitution', 'c')

src_files = ['src/encipher.c', 'src/cs50.c']

inc_dir = include_directories('include')

check_dep = dependency('check', required: true)

executable(
  'substitution',
  src_files,
  'src/main.c',
  include_directories: inc_dir,
  dependencies: check_dep,
)

test_exe = executable(
  'test-substitution',
  'test/test.c',
  src_files,
  include_directories: inc_dir,
  dependencies: check_dep,
)

test('test-substitution', test_exe)
