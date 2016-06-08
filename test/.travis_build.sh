echo "Running unit tests..."
./unit_test -v
result=$?
rm -r unit_test logs
echo "Unit tests completed : $result"
exit $result
