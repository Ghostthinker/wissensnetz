
if [ "$1" == "docker" ]; then
  rod=/var/www/localhost/tests/codeception/
  cocept=vendor/bin/codecept
  if [ "$2" == "from" ]; then
    docker exec -w $rod wn-php sh -c "cd ${rod}; codecept run acceptance --steps --debug --html --xml"
  else
    cd $rod
    $cocept run acceptance --steps --debug --html --xml
  fi
else
  codecept run acceptance --steps --debug --html --xml
fi
