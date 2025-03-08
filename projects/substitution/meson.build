# Substitution cipher

# Import the common project settings and dependencies
inc_dirs = [include_directories('include')]
check_dep = dependency('check', required: true)

src_files = ['src/encipher.c']

executable(
  'substitution',
  src_files,
  'src/main.c',
  include_directories: inc_dirs,
  dependencies: [cs50_dep, check_dep],
)

test_exe = executable(
  'test-substitution',
  'test/test.c',
  src_files,
  include_directories: inc_dirs,
  dependencies: [cs50_dep, check_dep],
)

test('substitution-tests', test_exe)
