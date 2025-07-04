#!/bin/bash

# Run tests and generate coverage report
./run_build.sh

# Capture coverage data from build directory (where .gcda files are)
lcov --capture --directory build --output-file coverage.info

# Remove system headers for cleaner results
lcov --remove coverage.info '/usr/*' --output-file coverage.info

# Remove test files and keep only include files
lcov --extract coverage.info '*/include/*' --output-file coverage.info

# Generate HTML report
genhtml coverage.info --output-directory coverage_report

# View the report
firefox coverage_report/include/index.html