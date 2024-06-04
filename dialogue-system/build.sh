# make text grey
echo '\033[0;90m'

echo 'Building app...'

g++ -o output $(find . -name '*.cpp')

echo 'Build complete - app output to follow:'

# unset colour
echo '\033[0m'