# Plurality voting system

# Import the common project settings and dependencies
inc_dirs = [include_directories('include')]
check_dep = dependency('check', required: true)

executable(
  'plurality',
  'src/plurality.c',
  'src/main.c',
  include_directories: inc_dirs,
  dependencies: [cs50_dep, check_dep],
)

test_exe = executable(
  'test-plurality',
  'test/test.c',
  'src/plurality.c',
  include_directories: inc_dirs,
  dependencies: [cs50_dep, check_dep],
)

test('plurality-tests', test_exe)
