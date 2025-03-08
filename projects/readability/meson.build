# Readability calculator

# Import the common project settings and dependencies
inc_dirs = [include_directories('include')]
check_dep = dependency('check', required: false)

# Implementation source (excluding main function)
impl_src = ['src/readability.c'] 

# Main executable
executable(
  'readability',
  ['src/main.c'] + impl_src,
  include_directories: inc_dirs,
  dependencies: [cs50_dep],
)

# Test executable (only if check is available)
if check_dep.found()
  test_exe = executable(
    'test-readability',
    ['src/test.c'] + impl_src,
    include_directories: inc_dirs,
    dependencies: [cs50_dep, check_dep],
    override_options: ['c_std=c99'], # To ensure compatibility
  )
  test('readability-tests', test_exe)
endif