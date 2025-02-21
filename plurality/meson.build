project('plurality', 'c')

src_files = ['src/cs50.c', 'src/plurality.c']

inc_dir = include_directories('include')

check_dep = dependency('check', required: true)

executable(
  'plurality',
  src_files,
  include_directories: inc_dir,
  dependencies: check_dep,
)

test_exe = executable(
  'test-p',
  'test/test.c',
  src_files,
  include_directories: inc_dir,
  dependencies: check_dep,
)

test('test-p', test_exe)
